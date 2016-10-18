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
	int aux;
	vector<int> vi;
	while(cin >> aux) {
		vi.pb(aux);
		sort(all(vi));
		if(vi.size()&1) printf("%d\n", vi[vi.size()/2]);
		else printf("%d\n", (vi[vi.size()/2]+vi[(vi.size()/2)-1])/2);
	}
  return 0;
}
