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
	int n;
	while(~scanf("%d", &n)){
		int aux, total = 0;
		vector<int> adj[n];
		int m[n][n];
		REP(i, n) {
			REP(j, n) {
				cin >> m[i][j];
				if(m[i][j]) adj[i].pb(j);
			}
		}
		
		for(int i = 0; i < n; i++){ // first node
			for(int j = 0; j < adj[i].size(); j++){ 
				for(int z = 0; z < adj[adj[i][j]].size(); z++){ // second node
					if(adj[adj[i][j]][z] != i && m[adj[adj[i][j]][z]][i] == 1){
						if((i+1 < adj[i][j]+1 && adj[i][j]+1 < adj[adj[i][j]][z]+1) || 
							(i+1 > adj[i][j]+1 && adj[i][j]+1 > adj[adj[i][j]][z]+1)){
							printf("%d %d %d\n", i+1, adj[i][j]+1, adj[adj[i][j]][z]+1);
							total++;
						}
					}
				}
			}
		}
		printf("total:%d\n\n", total);
	}
  return 0;
}
