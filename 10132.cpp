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
	int t;
	string line;
	scanf("%d%*c", &t);
	getline(cin, line);
	while(t--){
		int m = 300, M = 0;
		int maxTemp = 0;
		map<string, int> msi;
		map<string, int>::iterator it;
		vector<string> vs;
		while(getline(cin,line)) {
			if(line == "") break;
			vs.pb(line);
			m = min(m, (int)line.size());
			M = max(M, (int)line.size());
		}
		for(int i = 0; i < vs.size(); i++){
			for(int j = 0; j < vs.size(); j++){
				string comb = vs[i];
				if(i != j){
					if((comb.size() + vs[j].size()) == (m+M)){
						comb.append(vs[j]);
						it = msi.find(comb);
						if(it == msi.end()) msi.insert(make_pair(comb, 1));
						else it->second++;
					}
				}
			}
		}
		for(it = msi.begin(); it != msi.end(); it++) maxTemp = max(maxTemp, it->second);
		for(it = msi.begin(); it != msi.end(); it++){
			if(it->second == maxTemp){
				cout << it->first << endl;
				break;
			}
		}
		if(t) cout << endl;
	}
  return 0;
}
