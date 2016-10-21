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
	int t;
	cin >> t;
	while(t--){
		map<ll, ll> ss;
		map<ll, ll>::iterator it;
		ll n, m = 0, first = 0;
		cin >> n;
		int num[n];
		REP(i, n) cin >> num[i];
		REP(i, n) {
			it = ss.find(num[i]);
			if(it == ss.end()) ss.insert(make_pair(num[i], i));
			else {
				i = it->second;
				m = max(m, (ll)ss.size());
				ss.clear();
			}
			if(i == n-1){
				m = max(m, (ll)ss.size());
				ss.clear();
			}
		}
		cout << m << endl;
	}
  return 0;
} 
