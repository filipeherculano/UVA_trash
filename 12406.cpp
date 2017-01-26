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

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	while(t--){
		bool imp = true;
		int p, q;
		ll m = 0x3f3f3f3f3f3f3f3f, M = 0;
		scanf("%d %d", &p, &q);
		q = (1 << q);
		printf("Case %d:", caso++);
		
		REP(bitmask, (1 << p)){
			string start(p, '1');
			REP(i, p){
				if(bitmask&(1 << i)) start[p-1-i] = ('2');
			}
			if((stoll(start)) % q == 0) {
				m = min(m, stoll(start));
				M = max(M, stoll(start));
				imp = false;
			}
		}
		if(imp) printf(" impossible\n");
		else {
			printf(" %lld", m);
			if(M && m != M) printf(" %lld\n", M);
			else cout << endl;
		}
	}
  return 0;
}
