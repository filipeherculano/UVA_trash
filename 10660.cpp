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
	int t;
	scanf("%d", &t);
	while(t--){
		ll mat[25], n, global_min = 0x3f3f3f3f3f3f3f3f;
		vector< vector<ll> > vvi;
		vector<ll> res(5);
		REP(i, 25) mat[i] = 0;
		scanf("%lld", &n);
		REP(i, n){
			int x, y, num;
			scanf("%d %d %d", &x, &y, &num);
			mat[(x*5) + y] = num;
		}
		for(int a = 0; a <= 20; a++){
			for(int b = a+1; b <= 21; b++){
				for(int c = b+1; c <= 22; c++){
					for(int d = c+1; d <= 23; d++){
						for(int e = d+1; e <= 24; e++){
							ll sum = 0;
							int local_min;
							for(int i = 0; i < 25; i++){
								local_min = min((abs((a/5)-(i/5))+abs((a%5)-(i%5))),(abs((b/5)-(i/5))+abs((b%5)-(i%5))));
								local_min = min(local_min,((abs((c/5)-(i/5))+abs((c%5)-(i%5)))));
								local_min = min(local_min,((abs((d/5)-(i/5))+abs((d%5)-(i%5)))));
								local_min = min(local_min,((abs((e/5)-(i/5))+abs((e%5)-(i%5)))));
								sum += local_min*mat[i];
							}
							if(global_min > sum){
								global_min = sum;
								res[0] = a; res[1] = b; res[2] = c;
								res[3] = d; res[4] = e;
							}
						}
					}
				}
			}
		}
		REP(i, 5) printf("%lld%c", res[i], i == 4 ? '\n':' ');
	}
  return 0;
}





