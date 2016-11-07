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
	int t;
	cin >> t;
	while(t--){
		bool ok = true;
		int n, m;
		cin >> n >> m;
		int mat[n][m], v[m];
		REP(i, n) {
			REP(j, m) {
				cin >> mat[i][j];
				v[j] = 0;
			}
		}
		REP(j, m) REP(i, n)	v[j] += mat[i][j];
		REP(i, m) if(v[i] != 2) ok = false;
		for(int i = 0; i < m-1; i++){
			for(int j = i+1; j < m; j++){
				for(int z = 0; z < n; z++){
					if(mat[z][i] != mat[z][j]) break;
					if(z == n-1) ok = false;
				}
			}
		}
		printf("%s", ok ? "Yes\n":"No\n");
	}
  return 0;
}



