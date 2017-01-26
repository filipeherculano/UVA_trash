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
// Pre calculated;
ll mat[8][15] = {1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
 , 1 , 4 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
 , 1 , 9 , 26 , 26 , 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
 , 1 , 16 , 92 , 232 , 260 , 112 , 16 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
 , 1 , 25 , 240 , 1124 , 2728 , 3368 , 1960 , 440 , 32 , 0 , 0 , 0 , 0 , 0 , 0
 , 1 , 36 , 520 , 3896 , 16428 , 39680 , 53744 , 38368 , 12944 , 1600 , 64 , 0 , 0 , 0 , 0
 , 1 , 49 , 994 , 10894 , 70792 , 282248 , 692320 , 1022320 , 867328 , 389312 , 81184 , 5792 , 128 , 0 , 0
 , 1 , 64 , 1736 , 26192 , 242856 , 1444928 , 5599888 , 14082528 , 22522960 , 22057472 , 12448832 , 3672448 , 489536 , 20224 , 256};
int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) && n){
		n--;
		if(k >= 15) printf("0\n");
		else printf("%lld\n", mat[n][k]);
	}
  return 0;
}












