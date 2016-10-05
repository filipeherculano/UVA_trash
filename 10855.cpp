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
	int N, n;
	while(scanf("%d %d%*c", &N, &n) && (N || n)){
		vector<int> vi;
		string big[N], small[n];
		REP(i, N) cin >> big[i];
		REP(i, n) cin >> small[i];
		
		for(int r = 0; r < 4; r++){
			int count = 0;
			for(int i = 0; i <= (N-n); i++){
				for(int j = 0; j <= (N-n); j++){
					bool ok = true;
					for(int k = i; k < (n+i) && ok; k++){
						for(int z = j; z < (n+j) && ok; z++){
							if(big[k][z] != small[k-i][z-j]){
								ok = false;
							}
						}
					}
					if(ok) count++;
				}
			}
			vi.pb(count);
			char temp[n][n];
			REP(i, n) REP(j, n) temp[i][j] = small[n-1-j][i];
			REP(i, n) REP(j, n) small[i][j] = temp[i][j];
		}
		
		REP(i, 4) printf("%d%c", vi[i], i == 3 ? '\n':' ');
	}
  return 0;
}
