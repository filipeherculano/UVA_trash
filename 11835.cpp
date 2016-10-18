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
	int g, p, s;
	while(cin >> g >> p && (g || p)){
		int gp[g][p];
		REP(i, g) REP(j, p) cin >> gp[i][j];
		cin >> s;
		vector<int> score[s];
		REP(i, s){
			int col, aux;
			cin >> col;
			REP(j, col){
				cin >> aux;
				score[i].pb(aux);
			}
		}
		REP(i, s){
			int M = -1;
			set<int> si;
			vector<int> pilot(p, 0);
			REP(j, g) REP(z, p) if(gp[j][z]-1 < score[i].size()) pilot[z] += score[i][gp[j][z]-1];
			REP(j, p) M = max(M, pilot[j]);
			REP(j, p) if(M == pilot[j]) si.insert(j+1);
			for(set<int>::iterator it = si.begin(); it != si.end(); it++){
				cout << *it;
				if(it == --si.end()) cout << endl;
				else cout << " ";
			}
		}
	}
  return 0;
}
