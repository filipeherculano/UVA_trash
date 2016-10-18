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
		llu n, total = 0;
		vector<llu> vi;
		while(cin >> n && n) vi.pb(n);
		sort(all(vi));
		for(llu i = 0; i < vi.size(); i++) total += 2.0*(powl((ld)vi[i], (ld)(vi.size()-i)));
		if(total > 5000000) printf("Too expensive\n");
		else printf("%lld\n", total);
	}
  return 0;
}
