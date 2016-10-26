#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

// Map the combinations, not the courses.

int main(){
	int n;
	while(cin >> n && n){
		int m = 1, cnt = 0;
		map<vector<int>, int> mii;
		map<vector<int>, int>::iterator it;
		REP(i, n) {
			vector<int> v(5);
			REP(j, 5) cin >> v[j];
			sort(all(v));
			it = mii.find(v);
			if(it == mii.end()) mii.insert(make_pair(v, 1));
			else {
				it->second++;
				m = max(m, it->second);
			}
		}
		for(it = mii.begin(); it != mii.end(); it++)
			if(it->second == m) cnt += it->second;
		cout << cnt << endl;
	}
  return 0;
}






