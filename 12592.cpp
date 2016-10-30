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
	int n, q;
	string key, value, line;
	map<string, string> mss;
	map<string, string>::iterator it;
	scanf("%d%*c", &n);
	REP(i, n){
		getline(cin, key);
		getline(cin, value);
		mss.insert(make_pair(key, value));
	}
	scanf("%d%*c", &q);
	REP(i, q){
		getline(cin, line);
		it = mss.find(line);
		cout << it->second << endl;
	}
  return 0;
}
