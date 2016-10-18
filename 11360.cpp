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
	int t, n, s, caso = 1;
	cin >> t;
	while(t--){
		string op, line;
		scanf("%d%*c", &n);
		int matrix[n][n], a, b;
		
		REP(i, n) {
			cin >> line;
			REP(j, n) {
				matrix[i][j] = line[j]-'0';
			}
		}
		scanf("%d", &s);
		while(s--){
			cin >> op;
			if(!op.compare("row")){
				cin >> a >> b; a--; b--;
				for(int i = 0; i < n; i++) swap(matrix[a][i], matrix[b][i]);
			} else if(!op.compare("col")){
				cin >> a >> b; a--; b--;
				for(int i = 0; i < n; i++) swap(matrix[i][a], matrix[i][b]);
			} else if(!op.compare("inc")) REP(i, n) REP(j, n) matrix[i][j] = (matrix[i][j]+1) % 10;
			else if(!op.compare("dec")) REP(i, n) REP(j, n) matrix[i][j] = matrix[i][j] == 0 ? 9 : matrix[i][j]-1;
			else if(!op.compare("transpose")) REP(i, n) REP(j, n) if(i < j) swap(matrix[i][j], matrix[j][i]);
		}
		printf("Case #%d\n", caso++);
		REP(i, n) {
			REP(j, n) printf("%d", matrix[i][j]);
			cout << endl;
		}
		cout << endl;
	}
  return 0;
}
