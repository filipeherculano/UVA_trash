#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n;
	bool isFirst = true;
	scanf("%d%*c%*c", &n);
	while(n--){
		if(!isFirst) cout << endl;
		isFirst = false;
		string line;
		vector<string> vs;
		vector<int> vi(178);
		vector< vector<int> > vvi;
		while(getline(cin, line) && line.size() > 0) vs.push_back(line);
		sort(vs.begin(), vs.end());
		FOR(i, vs.size()){
			FOR(i, 178) vi[i] = 0;
			FOR(j, vs[i].size())
				if(vs[i][j] != ' ') vi[vs[i][j]]++;
			vvi.push_back(vi);
		}
		for(int i = 0; i < vvi.size()-1; i++){
			for(int j = i+1; j < vvi.size(); j++){
				bool ok = true;
				FOR(z, 178)
					if(vvi[i][z] != vvi[j][z]) ok = false;
				if(ok){
					cout << vs[i] << " = " << vs[j] << endl;
				}
			}
		}
	}	
  return 0;
}
