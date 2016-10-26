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
	int n;
	while(cin >> n && n){
		ll aux, k, cnt = 0;
		multiset<ll> bills;
		while(n--){
			cin >> k;
			REP(i, k) {
				cin >> aux;
				bills.insert(aux);
			}
			cnt += abs(*(bills.begin())-*(bills.rbegin()));
			bills.erase(bills.begin());
			bills.erase(--bills.end());
		}
		cout << cnt << endl;
	}
  return 0;
}
