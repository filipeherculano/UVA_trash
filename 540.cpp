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
	int t, scn = 1;
	while(cin >> t && t){
		string line;
		int n, aux;
		vector<int> vi[t], pos;
		queue<int>qi[t];
		REP(i, t){
			cin >> n;
			REP(j, n){
				cin >> aux;
				vi[i].pb(aux);
			}
		}
		scanf("%*c");
		printf("Scenario #%d\n", scn++);
		while(cin >> line && line.compare("STOP")){
			if(!line.compare("ENQUEUE")){
				bool found = false;
				cin >> aux;
				for(int team = 0; team < t && !found; team++){
					for(int person = 0; person < vi[team].size() && !found; person++){
						if(aux == vi[team][person]){
							for(int i = 0; i < pos.size() && !found; i++){
								if(pos[i] == team){
									qi[team].push(aux);
									found = true;
								} 
							}
							if(!found){
								pos.pb(team);
								qi[team].push(aux);
								found = true;
							}
						}
					}
				}
			} else if(!line.compare("DEQUEUE")){
				for(int i = 0; i < pos.size(); i++){
					cout << qi[pos[i]].front() << endl;
					qi[pos[i]].pop();
					if(qi[pos[i]].empty()) pos.erase(pos.begin());
					break;
				}
			}
		}
		cout << endl;
	}
  return 0;
}











