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
	int pos = 0;
	map<string, int> ss;
  map<string, int>::iterator it;
	string x, line;
	REP(j, 5){
		bool allZ = false;
		x += "a";
		while(1){
			bool allZ = true, ok = true, carry = false;
			REP(i, x.size()) if(x[i] != 'z') allZ = false;
			REP(i, x.size()-1) if(x[i] >= x[i+1]) ok = false;
			if(ok) ss.insert(make_pair(x, ++pos));
			for(int i = x.size()-1; i >= 0; i--){
				if(i == x.size()-1){
					if(x[i] == 'z') {
						x[i] = 'a';
						carry = true;
					} else x[i]++;
				} else {
					if(carry){
						if(x[i] == 'z') x[i] = 'a';
						else {
							x[i]++;
							carry = false;
						}
					}
				}
			}
			if(allZ) break;
		}
	}
  while(getline(cin, line)){
  	it = ss.find(line);
  	if(it == ss.end()) printf("0\n");
  	else cout << it->second << endl;
  }
  return 0;
}


