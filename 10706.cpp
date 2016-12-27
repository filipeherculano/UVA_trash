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

int digCount(ll n){
	int cnt = 0;
	while(n){
		cnt++;
		n /= 10;
	}
	return cnt;
}

ll comp(ll sz){
	ll sub = 1000000, d = 7, res = 0;
	while(sub){
		if(sz >= sub){
			res += (sz-sub+1)*d;
			sz -= (sz-sub+1);
		}
		sub /= 10;
		d--;
	}
	return res;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll i, sz = 1, j;
		cin >> i;
		while(i > comp(sz)){
			i -= comp(sz);
			sz++;
		}
		for(j = 1; i > digCount(j); j++) i -= digCount(j);
		string aux = to_string(j);
		cout << aux[i-1] << endl;
	}
  return 0;
}










