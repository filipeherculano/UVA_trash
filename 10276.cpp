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
	int v[] = {1,3,7,11,17,23,31,39,49,59,71,83,97,111,127,143,161,
						179,199,219,241,263,287,311,337,363,391,419,449,479,511,
						543,577,611,647,683,721,759,799,839,881,923,967,1011,
						1057,1103,1151,1199,1249,1299};
	while(t--){
		int n;
		scanf("%d", &n);
		printf("%d\n", v[n-1]);
	}
  return 0;
}
