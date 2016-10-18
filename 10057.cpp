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
	while(cin >> n){
		vector<int> v(n);
		REP(i, n) cin >> v[i];
		sort(all(v));
		int a = v[(n/2)-1], b = v[n/2], count = 0;
		if(v.size()&1){
			REP(i, v.size()) if(v[i] == b) count++;
			printf("%d %d 1\n", b, count);
		} else {
			REP(i, v.size()) if(v[i] == a || v[i] == b) count++;
			printf("%d %d %d\n", a, count, 1 + abs(a-b));
		}
	}
  return 0;
}
