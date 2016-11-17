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
	int n;
	while(scanf("%d", &n) && n){
		bool found = false;
		vector<ll> s(n);
		map<ll, pair<int,int> > cmb;
		map<ll, pair<int,int> >::iterator it;
		ll M = -536870912, m = 536870911;
		int index;
		
		REP(i, n) cin >> s[i];
		
		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j < n; j++){
				if(i != j){
					M = max(M, s[i]-s[j]);
					m = min(m, s[i]-s[j]);
				}
			}
		}
		
		sort(all(s));
		
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(s[i]+s[j] >= m && s[i]+s[j] <= M)
					cmb.insert(make_pair(s[i]+s[j], make_pair(i, j)));
		
		for(int i = n-1; i >= 0 && !found; i--){
			for(int j = 0; j < n && !found; j++){
				if(i != j){
					it = cmb.find(s[i]-s[j]);
					if(it != cmb.end() && 
						i != it->second.first && i != it->second.second &&
						j != it->second.first && j != it->second.second){
						found = true;
						index = i;
					}
				}
			}
		}
		
		if(found) printf("%lld\n", s[index]);
		else printf("no solution\n");
	}
  return 0;
}





















