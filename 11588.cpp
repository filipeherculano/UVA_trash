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
	int x, caso = 1;
	cin >> x;
	while(x--){
		int r, c, m, n, v[26] = {0}, M = -1, total = 0;
		string line;
		cin >> r >> c >> m >> n;
		scanf("%*c");
		REP(i, r) {
			getline(cin, line);
			REP(j, line.size()) v[line[j]-'A']++;
		}
		REP(i, 26) M = max(M, v[i]);
		REP(i, 26){
			if(M == v[i]) total += m*v[i];
			else total += n*v[i];
		}
		printf("Case %d: %d\n", caso++, total);
	}
  return 0;
}



