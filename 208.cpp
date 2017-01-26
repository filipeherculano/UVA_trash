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

ll n, cnt;
vector<int> mat[23], path, visited;

void backtrack(int i){
	if(i == n){
		REP(j, path.size()){
			printf("%d%c", path[j], j == path.size()-1 ? '\n':' ');
		}
		cnt++;
		return;
	}
	
	visited[i] = 1;
	REP(j, mat[i].size()){
		if(!visited[mat[i][j]]){
			path.pb(mat[i][j]);
			backtrack(mat[i][j]);
			path.pop_back();
		}
	}
	visited[i] = 0;
}

int main(){
	int caso = 1;
	path.pb(1);
	while(~scanf("%lld", &n)){
		int a, b; cnt = 0;
		REP(i, 23) mat[i].clear();
		visited.clear();
		while(scanf("%d %d", &a, &b) && (a || b)){
			mat[a].pb(b); mat[b].pb(a);
			visited.pb(0);
		}
		REP(i, 23) sort(all(mat[i]));
		printf("CASE %d:\n", caso++);
		if(mat[n].size() != 0 || n == 1){
			backtrack(1);
		}
		printf("There are %lld routes from the firestation to streetcorner %lld.\n", cnt, n);
	}
  return 0;
}




