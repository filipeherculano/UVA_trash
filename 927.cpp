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
	int c;
	scanf("%d", &c);
	while(c--){
		ll exp, k, d, n = 1, res = 0;
		scanf("%lld", &exp);
		vector<ll> poli(exp+1);
		REP(i, exp+1) cin >> poli[i];
		scanf("%lld %lld", &d, &k);
		while(k > 0){
			k -= d*n;
			n++;
		}
		n--;
		REP(i, exp+1)
			res += poli[i]*pow(n, i);
		printf("%lld\n", res);
	}
  return 0;
}
