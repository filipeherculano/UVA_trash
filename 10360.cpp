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
const double EPS = 1e-9;

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int d, n, rx, ry, rv = 0;
		int mat[1025][1025];
		REP(i, 1025) REP(j, 1025) mat[i][j] = 0;
		scanf("%d", &d);
		scanf("%d", &n);
		REP(i, n){
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			for(int j = (x-d >= 0 ? x-d:0); j <= x+d && j < 1025; j++){
				for(int z = (y-d >= 0 ? y-d:0); z <= y+d && z < 1025; z++){
					mat[j][z] += v;
					if(mat[j][z] > rv){
						rx = j;
						ry = z;
						rv = mat[j][z];
					}
				}
			}
		}
		printf("%d %d %d\n", rx, ry, rv);
	}
  return 0;
}
