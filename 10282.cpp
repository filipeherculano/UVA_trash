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
	map<string,string> mss;
	map<string,string>::iterator it;
	string line, key, value, query;
	while(getline(cin, line) && line != ""){
		stringstream ss;
		ss << line;
		ss >> value >> key;
		mss.insert(make_pair(key, value));
	}
	while(cin >> query){
		it = mss.find(query);
		if(it == mss.end()) printf("eh\n");
		else cout << it->second << endl;
	}
  return 0;
}
