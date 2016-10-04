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
	int caso = 1, s, ready;
	int q[12], m[12];
	while(cin >> s && s >= 0){
		printf("Case %d:\n", caso++);
		int ready = s;
		REP(i, 12) cin >> q[i];
		REP(i, 12) cin >> m[i];
		REP(i, 12){
			if(ready >= m[i]) {
				printf("No problem! :D\n");
				ready -= m[i];
			} else printf("No problem. :(\n");
			ready += q[i];
		}
	}
  return 0;
}
