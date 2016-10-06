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
	int w, h, n;
	while(cin >> w >> h >> n && w){
		int x1, x2, y1, y2, spots = w*h;
		bool mat[h][w];
		REP(i, h) REP(j, w) mat[i][j] = true;
		while(n--){
			cin >> x1 >> y1 >> x2 >> y2;
			x1--; y1--; x2--; y2--;
			for(int i = min(x1,x2); i <= max(x1, x2); i++) {
				for(int j = min(y1,y2); j <= max(y1, y2); j++) {
					if(mat[j][i] == true) {
						spots--;
						mat[j][i] = false;
					}
				}
			}
		}
		if(spots == 0) printf("There is no empty spots.\n");
		else if(spots == 1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n", spots);
	}
  return 0;
}
