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

ll mat[14][14][14];

void DP(){
	mat[1][1][1] = 1;
	for(int n = 2; n <= 13; n++)
		for(int p = 1; p <= n; p++)
			for(int r = 1; r <= n; r++)
				mat[n][p][r] = mat[n-1][p][r]*(n-2) + mat[n-1][p-1][r] + mat[n-1][p][r-1];
}

int main(){
	DP();
	int t, n, p, r;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &p, &r);
		printf("%lld\n", mat[n][p][r]);
	}
  return 0;
}
