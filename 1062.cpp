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
	int caso = 1;
	string line;
	while(getline(cin, line) && line.compare("end")){
		int v[26], m = 1500, cnt = 0;
		vector< stack<char> > vsc;
		memset(v, 0, 26);
		REP(i, line.size()){
			bool fit = false;
			v[line[i]-'A']++;
			REP(j, vsc.size()){
				if(vsc[j].top() >= line[i]){
					vsc[j].push(line[i]);
					fit = true;
					break;
				}
			}
			if(!fit) {
				stack<char> temp;
				temp.push(line[i]);
				vsc.pb(temp);
			}
		}
		REP(i, 26) if(v[i]) cnt++;
		printf("Case %d: %d\n", caso++, min(cnt, (int)vsc.size()));
	}
  return 0;
}





