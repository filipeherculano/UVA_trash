#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool isOK(ll a){
	int dig[10] = {0};
	while(a){
		dig[a%10]++;
		a /= 10;
	}
	REP(i,10)
		if(dig[i] > 1) 
			return false;
	return true;
}

int main(){
	string out;
	ll t;
	scanf("%lld", &t);
	getline(cin, out);
	while(t--){
		ll n;
		scanf("%lld", &n);
		for(ll i = 1; i <= 9876543210; i++){
			if((i*n) > 9876543210) break;
			if(isOK(i) && isOK(i*n))
				printf("%lld / %lld = %lld\n", (i*n), i, n);
		}
		if(t) cout << endl;
	}
  return 0;
}
