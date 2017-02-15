#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

double res;
int vis[60];
ll adj[60][60], w[60];
int pres[60];

void dfs(int i, int sz, ll sum){
	if(vis[i]){
		ll s = sum - w[i];
		int tam = sz - vis[i];
		if(res == -1.0) res = (double)s/(double)tam;
		else res = min(res, (double)s/(double)tam);
		return;
	}
	vis[i] = sz;
	w[i] = sum;
	REP(j,60){
		if(pres[j] && adj[i][j]) 
			dfs(j,sz+1,sum+adj[i][j]);
	}
	w[i] = 0;
	vis[i] = 0;
}

int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int N, n, m, caso = 1;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &n, &m);
		res = -1.0;
		REP(i,60) REP(j,60) adj[i][j] = 0;
		REP(i,60) pres[i] = 0;
		REP(i,m){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a][b] = c;
			pres[a] = 1;
			pres[b] = 1;
		}
		REP(i,60) if(pres[i]) dfs(i, 1, 0);
		if(res < 0) printf("Case #%d: No cycle found.\n", caso++);
		else printf("Case #%d: %.2lf\n", caso++, res);
	}
	return 0;
}
