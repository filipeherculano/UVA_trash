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
	int n, r, c, k;
	while(cin >> n >> r >> c >> k && (n || r || c || k)){
		int mat[r][c];
		REP(i, r) REP(j, c) cin >> mat[i][j];
		while(k--){
			int temp[r][c];
			REP(i, r) REP(j, c) temp[i][j] = mat[i][j];
			REP(i, r) {
				REP(j, c) {
					if(i && ((mat[i][j]+1) % n) == mat[i-1][j]) temp[i-1][j] = mat[i][j];
					if(i < r-1 && ((mat[i][j]+1) % n) == mat[i+1][j]) temp[i+1][j] = mat[i][j];
					if(j && ((mat[i][j]+1) % n) == mat[i][j-1]) temp[i][j-1] = mat[i][j];
					if(j != c-1 && ((mat[i][j]+1) % n) == mat[i][j+1]) temp[i][j+1] = mat[i][j];
				}
			}
			REP(i, r) REP(j, c) mat[i][j] = temp[i][j];
		}
		REP(i, r) REP(j, c) printf("%d%c", mat[i][j], j == c-1 ? '\n':' ');
	}
  return 0;
}
