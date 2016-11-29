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

vector<int> adj[17];
int visited[17];
vector<int> path;

bool isPrime(int num){
	for(int i = 2; i < num; i++)
		if(!(num%i))
			return false;
	return true;
}

void dfs(int i, int height, int sz){
	visited[i] = 1;
	path.pb(i);
	if(height == 0 && isPrime(i+path[0])){
		REP(j, path.size()) 
			printf("%d%c", path[j], j == path.size()-1 ? '\n':' ');
	} else if(height > 0){
		REP(j, adj[i].size()) 
			if(!visited[adj[i][j]] && adj[i][j] <= sz) 
				dfs(adj[i][j], height-1, sz);
	}
	path.pop_back();
	visited[i] = 0;
}

int main(){
	bool isFirst = true;
	int caso = 1, sz;
	for(int i = 1; i <= 16; i++)
		for(int j = 1; j <= 16; j++)
			if(isPrime(i+j) && i != j)
				adj[i].pb(j);
	while(~scanf("%d", &sz)){
		if(!isFirst) cout << endl;
		isFirst = false;
		path.clear();
		REP(i, 17) visited[i] = 0;
		printf("Case %d:\n", caso++);
		dfs(1, sz-1, sz);	
	}
  return 0;
}
