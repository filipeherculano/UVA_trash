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

int solve(vector<string> vs, int x, int y, int sz, int m, int n){
	int side = sz/2;
	bool ok = true;
	char c = vs[x][y];
	
	if(x-side < 0 || y-side < 0 || x+side > m-1 || y+side > n-1) return sz-1;
	
	for(int i = x-side; i <= x+side && ok; i++)
		for(int j = y-side; j <= y+side && ok; j++)
			if(vs[i][j] != c) ok = false;
	
	if(ok) return solve(vs, x, y, sz+1, m, n);
	else return sz-1;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int m, n, q, x, y;
		scanf("%d %d %d%*c", &m, &n, &q);
		printf("%d %d %d\n", m, n, q);
		vector<string> vs(m);
		REP(i,m) getline(cin, vs[i]);
		REP(i,q){
			scanf("%d %d", &x, &y);
			printf("%d\n", solve(vs, x, y, 1, m, n));
		}
	}
  return 0;
}
