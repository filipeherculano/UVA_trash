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

vector< vector<int> > vvi, visited;
int n, m;

int dfs(int i, int length){
	int res = length;
	
	REP(j, vvi[i].size()) {
		if(!visited[i][vvi[i][j]]){
			visited[i][vvi[i][j]] = 1; visited[vvi[i][j]][i] = 1;
			res = max(res, dfs(vvi[i][j], length+1));
			visited[i][vvi[i][j]] = 0; visited[vvi[i][j]][i] = 0;
		}
	}	
	
	return res;
}

int main(){
	while(scanf("%d %d", &n, &m) && (n || m)){
		int res = 0;
		visited.clear();
		vvi.clear();
		REP(i, n){
			vector<int> temp, zero(n, 0);
			vvi.pb(temp);
			visited.pb(zero);
		}
		REP(i, m) {
			int a, b;
			scanf("%d %d", &a, &b);
			vvi[a].pb(b);
			vvi[b].pb(a);
		}
		REP(i, n) {
			REP(i, n) REP(j, n) visited[i][j] = 0;
			res = max(res, dfs(i, 0));
		}
		cout << res << endl;
	}
  return 0;
}
