#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	int m;
	vector< vector<int> > conf;
	map<char, int> words;
	words['P'] = 0; words['G'] = 1; words['A'] = 2; words['S'] = 3; words['N'] = 4; 
	words['r'] = 0; words['o'] = 1; words['y'] = 2; words['g'] = 3; words['b'] = 4; 
	string line;
	
	while(getline(cin, line) && line != "#"){
		if(line[0] == 'e'){
			int index;
			m = INF;
			REP(i, conf.size()){ // fix pattern
				int cnt = 0;
				REP(j, conf.size()){ // iterate through all
					if(i != j)
						REP(z, 5)
							if(conf[i][z] != conf[j][z])
								cnt++;
				}
				if(cnt < m){
					m = cnt;
					index = i;
				}
			}
			cout << index+1 << endl;
			conf.clear();
		} else {
			vector<int> temp(5);
			for(int i = 2; i < line.size() ; i+=4)
				temp[words[line[i]]] = words[line[i-2]];
			conf.pb(temp);
		}
	}
  return 0;
}
