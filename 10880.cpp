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
	int n, c, r, caso = 1;
	cin >> n;
	while(n--){
		cin >> c >> r;
		printf("Case #%d:", caso++);
		if(c != r){
			vector<int> vi;
			for(int i = 1; i <= sqrt(c-r); i++) if(!((c-r)%i)) vi.pb(i);
			int size = vi.size();
			REP(i, size) vi.pb((c-r)/(vi[i]));
			sort(all(vi));
			REP(i, vi.size()) {
				if(vi[i] > r) {
					if(i){
						if(vi[i] != vi[i-1]) printf(" %d", vi[i]);
					} else printf(" %d", vi[i]);
				}
			}
		} else printf(" 0");
		cout << endl;
	}
  return 0;
}
