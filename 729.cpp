#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	int d;
	scanf("%d%*c", &d);
	while(d--){
		int n, h;
		scanf("%d %d", &n, &h);
		string temp;
		for(int i = 0; i < n; i++){
			if(i >= n-h) temp.pb('1');
			else temp.pb('0');
		}
		do{
			cout << temp << endl;
		} while(next_permutation(all(temp)));
		if(d) cout << endl;
	}
  return 0;
}
