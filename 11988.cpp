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
	string line;
	while(getline(cin, line)){
		string res;
		string::iterator it = res.begin();
		bool home = false;
		REP(i, line.size()){
			if(line[i] == '[') {
				home = true;
				it = res.begin();
				it++;
			} else if(line[i] == ']') {
				home = false;
				it = res.end();
			} else if(home) res.insert(it, line[i]);
			else res.insert(it, line[i]);
		}
		cout << res << endl;
	}
  return 0;
}
