#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	int n, c = 1;
	while(scanf("%d", &n) && n){
		int v[n], q, m;
		vector<int> sum;
		REP(i,n) scanf("%d", &v[i]);
		scanf("%d", &m);
		printf("Case %d:\n", c++);
		REP(i,n)
			REP(j,n)
				if(i != j)
					sum.pb(v[i]+v[j]);
			
		REP(i,m){
			int close = INF, index;
			scanf("%d", &q);
			REP(j,sum.size()){
				if(abs(sum[j]-q) < close){
					close = abs(sum[j]-q);
					index = j;
				}
			}
			printf("Closest sum to %d is %d.\n", q, sum[index]);
		}
	}
  return 0;
}
