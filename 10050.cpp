#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int t, n, p, temp;
	cin >> t;
	while(t--){
		int count = 0;
		cin >> n; n++;
		cin >> p;
		int v[n];
		REP(i, n) v[i] = 0;
		REP(i, p){
			cin >> temp;
			for(int j = temp; j < n; j+=temp) 
				if((j % 7) != 6 && (j % 7) != 0) v[j] = 1;
		}
		REP(i, n) count += v[i];
		cout << count << endl;
	}
  return 0;
}
