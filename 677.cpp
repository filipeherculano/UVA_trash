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

bool ok;
int n, sz;
vector< vector<int> > adj;
vector<int> visited;
vector<int> path;

void dfs(int i, int height){
	visited[i] = 1;
	path.pb(i);
	if(height == 0){
		printf("(");
		REP(i, path.size()) printf("%d%c", path[i]+1, i == path.size()-1 ? ')':',');
		printf("\n");
		ok = true;
	} else {
		REP(j, adj[i].size()) 
			if(!visited[adj[i][j]]) 
				dfs(adj[i][j], height-1);
	}
	path.pop_back();
	visited[i] = 0;
}

int main(){
	while(~scanf("%d", &n)){
		ok = false;
		if(n == -9999){
			adj.clear();
			visited.clear();
			cout << endl;
		} else {
			scanf("%d", &sz);
			REP(i, n) visited.pb(0);
			REP(i, n){
				int aux;
				vector<int> vi;
				REP(j, n){
					scanf("%d", &aux);
					if(aux) vi.pb(j);
				}
				adj.pb(vi);
			}
			dfs(0, sz);
			if(!ok) printf("no walk of length %d\n", sz);
		}	
	}
  return 0;
}
