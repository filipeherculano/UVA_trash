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
	ll n, m, aux;
	while(cin >> n >> m && (n || m)){
		set<ll> s;
		REP(i, n){
			cin >> aux;
			s.insert(aux);
		}
		REP(i, m){
			cin >> aux;
			s.insert(aux);
		}
		cout << (n+m)-s.size() << endl;
	}
  return 0;
}
