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
		int pos[n][3];
		set<int> dist;
		bool ok = true;
		REP(i, n){
			scanf("%d %d", &pos[i][0], &pos[i][1]);
			pos[i][2] = i;
		}
		REP(i, n) pos[i][2] += pos[i][1];
		REP(i, n) if(pos[i][2] < 0 || pos[i][2] >= n) ok = false;
		if(ok) {
			REP(i, n) dist.insert(pos[i][2]);
			if(dist.size() != n) ok = false;
		}
		if(ok) {
			int res[n];
			REP(i, n) res[pos[i][2]] = pos[i][0];
			REP(i, n) printf("%d%c", res[i], i == n-1 ? '\n':' ');
			
		} else printf("-1\n");
	}
  return 0;
}
