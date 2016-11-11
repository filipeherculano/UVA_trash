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
	int n, m;
	while(scanf("%d %d%*c", &n, &m) && n){
		int matrix[n][m], cnt = 0;
		string line;
		REP(i, n) {
			getline(cin, line);
			REP(j, line.size()) matrix[i][j] = line[j]-'0';
		}
		for(int lin = 1; lin <= n; lin++){
			for(int col = 1; col <= m; col++){
				for(int i = 0; i <= n-lin; i++){
					for(int j = 0; j <= m-col; j++){
						bool ok = true;
						for(int ii = i; ii < i+lin && ok; ii++)
							for(int jj = j; jj < j+col && ok; jj++)
								if(matrix[ii][jj] == 0) ok = false;
						if(ok) cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
  return 0;
}
