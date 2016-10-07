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
	int m, n, op;
	cin >> m;
	while(m--){
		cin >> n;
		int mat[n][n], t;
		REP(i, n) REP(j, n) cin >> mat[i][j];
		for(int i = 0; i < (n+1)/2; i++){
			cin >> t;
			while(t--){
				cin >> op;
				if(op == 1) { FOR(k, i, n/2) FOR(z, i, n-i) if(z == i || z == n-1-i || k == i) swap(mat[k][z], mat[n-1-k][z]);
				} else if(op == 2){ FOR(k, i, n-i) FOR(z, i, n/2) if(k == i || k == n-1-i || z == i) swap(mat[k][z], mat[k][n-1-z]);
				} else if(op == 3){ FOR(k, i, n-i) FOR(z, i, n-i) if(k == i || z == n-1-i) swap(mat[k][z], mat[z][k]);
				} else if(op == 4){ FOR(k, i, n-i) FOR(z, i, n-i) if(k == i || z == i) swap(mat[k][z], mat[n-1-z][n-1-k]);
				}
			}
		}
		REP(i, n) REP(j, n) printf("%d%c", mat[i][j], j == n-1 ? '\n':' ');
	}
  return 0;
}









