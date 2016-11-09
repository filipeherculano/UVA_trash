#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int n, m;
	while(cin >> n >> m && (n || m)){
		int count = 0;
		int v[] = {0,1,2,3,4,5,6,7}, cons[m][3];
		REP(i, m) cin >> cons[i][0] >> cons[i][1] >> cons[i][2];
		do{
			bool ok = true;
			REP(i, m){
				int pos1, pos2;
				REP(j, n){
					if(cons[i][0] == v[j]) pos1 = j;
					if(cons[i][1] == v[j]) pos2 = j;
				}
				if(cons[i][2] < 0 && abs(pos1-pos2) < abs(cons[i][2])) ok = false;
				else if(cons[i][2] > 0 && abs(pos1-pos2) > abs(cons[i][2])) ok = false;
			}
			if(ok) count++;
		} while(next_permutation(v, v+n));
		cout << count << endl;
	}
  return 0;
}
