#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int t, test = 1;
	scanf("%d%*c", &t);
	while(t--){
		int n;
		bool ok = true;
		scanf("%*c = %d", &n);
		long long matrix[n][n];
		REP(i, n) {
			REP(j, n) {
				scanf("%lld", &matrix[i][j]);
				if(matrix[i][j] < 0) ok = false;
			}
		}
		scanf("%*c");
		if(ok) REP(i, n) REP(j, n) if(matrix[i][j] != matrix[n-1-i][n-1-j]) ok = false;
		
		printf("Test #%d: %s", test++, ok ? "Symmetric.\n":"Non-symmetric.\n");
	}
  return 0;
}
