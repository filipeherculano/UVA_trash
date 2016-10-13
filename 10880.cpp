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
			for(int i = 1; i <= sqrt(c-r); i++) if((c % i) == r) vi.pb(i);
			REP(i, vi.size()) vi.pb((c-r)/(i+1));
			sort(all(vi));
			REP(i, vi.size()) printf(" %d", vi[i]);
		} else printf(" 0");
		cout << endl;
	}
  return 0;
}
