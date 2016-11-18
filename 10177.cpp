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
		llu res[6] = {0,0,0,0,0,0};
		for(llu lin = 1; lin <= n; lin++){
			for(llu col = 1; col <= n; col++){
				if(lin == col) res[0] += (n-lin+1)*(n-col+1);
				else res[1] += (n-lin+1)*(n-col+1);
				for(llu prof = 1; prof <= n; prof++){
					if(lin == col && lin == prof) res[2] += (n-lin+1)*(n-col+1)*(n-prof+1);
					else res[3] += (n-lin+1)*(n-col+1)*(n-prof+1);
					for(llu quad = 1	; quad <= n; quad++){
						if(lin == col && lin == prof && lin == quad) res[4] += (n-lin+1)*(n-col+1)*(n-prof+1)*(n-quad+1);
						else res[5] += (n-lin+1)*(n-col+1)*(n-prof+1)*(n-quad+1);
					}
				}
			}
		}
		REP(i, 6) printf("%llu%c", res[i], i == 5? '\n':' ');
	}
  return 0;
}
