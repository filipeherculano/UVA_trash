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
	int m, n;
	while(scanf("%d %d%*c", &n, &m) && (n || m)){
		char big[n][n], temp[m][m], c;
		int coor[2][2] = {n,n,-1,-1};
		bool res = false;
		string line;
		REP(i, n) REP(j, n) big[i][j] = '.';
		REP(i, m) REP(j, m) temp[i][j] = '.';
		REP(i, n) {
			cin >> line;
			REP(j, line.size()) if(line[j] == '*') big[i][j] = line[j];
		}
		REP(i, m) {
			cin >> line;
			REP(j, line.size()) if(line[j] == '*') temp[i][j] = line[j];
		}
		REP(i, m) REP(j, m) if(temp[i][j] == '*') {coor[0][0] = min(coor[0][0], i); coor[0][1] = min(coor[0][1], j); coor[1][0] = max(coor[1][0], i); coor[1][1] = max(coor[1][1], j);}
		int lin = (coor[1][0]-coor[0][0])+1, col = (coor[1][1]-coor[0][1])+1;
		char small[lin][col];
		REP(i, lin) REP(j, col) small[i][j] = temp[i+coor[0][0]][j+coor[0][1]];
		// here is were shit gets CrAzY!
		for(int i = 0; i <= n-lin && !res; i++){
			for(int j = 0; j <= n-col && !res; j++){
				bool ok = true;
				char aux[n][n];
				REP(ii, n) REP(jj, n) aux[ii][jj] = big[ii][jj];
				for(int k = 0; k < lin && ok; k++){
					for(int z = 0; z < col && ok; z++){
						if(small[k][z] == '*' && aux[k+i][z+j] == '.') ok = false;
						else if(small[k][z] == '*' && aux[k+i][z+j] == '*') aux[k+i][z+j] = '.';
					}
				}
				if(ok){
					for(int ii = 0; ii <= n-lin && !res; ii++){
						for(int jj = 0; jj <= n-col && !res; jj++){
							ok = true;
							for(int kk = 0; kk < lin && ok; kk++){
								for(int zz = 0; zz < col && ok; zz++){
									if(small[kk][zz] == '*' && aux[kk+ii][zz+jj] == '.') ok = false;
									else if(small[kk][zz] == '*' && aux[kk+ii][zz+jj] == '*') aux[kk+ii][zz+jj] = '.';
								}
							}
							res = ok;
						}
					}
				}
			}
		}
		printf("%d\n", res);
	}
  return 0;
}
