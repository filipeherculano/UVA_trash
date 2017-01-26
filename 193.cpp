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

int nd, ed;
vector<int> adj[100], path, color;

bool place(int i, int cor){
	if(cor == 2){
		REP(j, adj[i].size())
			if(color[adj[i][j]] == cor)
				return false;
	}
	return true;
}

void backtrack(int i){
	if(i == nd){
		vector<int> tmp;
		REP(j, nd) if(color[j] == 2) tmp.pb(j);
		if(tmp.size() > path.size()) path = tmp;
	} else{
		color[i] = 1;
		backtrack(i+1);
		color[i] = 0;
		if(place(i, 2)){ // try black
			color[i] = 2;
			backtrack(i+1);
			color[i] = 0;
		}
	}
}

int main(){
	int m;
	scanf("%d", &m);
	while(m--){
		path.clear();
		scanf("%d %d", &nd, &ed);
		REP(i, nd) {
			adj[i].clear();
			color.pb(0);
		}
		REP(i, ed){
			int a, b;
			scanf("%d %d", &a, &b);
			a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		backtrack(0);
		printf("%lu\n", path.size());
		REP(i, path.size()) printf("%d%c", path[i]+1, i == path.size()-1 ? '\n':' ');
	}
  return 0;
}
