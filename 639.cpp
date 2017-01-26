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

int n;
vector< vector<int> > mat;

bool place(int x, int y){
  if(mat[x][y] == -1 || mat[x][y] == 1) return false;
  for(int i = y+1; i < n; i++){
    if(mat[x][i] == -1) break;
    if(mat[x][i] == 1) return false;
  }
  for(int i = y-1; i >= 0; i--){
    if(mat[x][i] == -1) break;
    if(mat[x][i] == 1) return false;
  }
  for(int i = x+1; i < n; i++){
    if(mat[i][y] == -1) break;
    if(mat[i][y] == 1) return false;
  }
  for(int i = x-1; i >= 0; i--){
    if(mat[i][y] == -1) break;
    if(mat[i][y] == 1) return false;
  }
  return true;
}

int backtrack(int sum){
  int m = 0;
  REP(i, n) {
    REP(j, n) {
      if(place(i, j)){
        mat[i][j] = 1;
        m = max(m,backtrack(sum+1));
        mat[i][j] = 0;
      }
    }
  }
  if(m) return m;
  return sum;
}

int main(){
  while(scanf("%d%*c", &n) && n){
    string line;
		mat.clear();
    REP(i, n) {
			vector<int> temp;
			getline(cin, line);
      REP(j, line.size()) {       
        if(line[j] == '.') temp.pb(0);
        else temp.pb(-1);
      }
			mat.pb(temp);
    }
		//REP(i, n) REP(j, n) printf("%d%c", mat[i][j], j == n-1? '\n':' ');
    cout << backtrack(0) << endl;
  }
  return 0;
}
