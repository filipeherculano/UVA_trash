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
	int n;
	cin >> n;
	while(n--){
		string line;
		int p, num;
		scanf("%d%*c", &p);
		int m = p;
		vector<int> v[p], res;
		REP(i, p){
			stringstream ss;
			getline(cin, line);
			ss << line;
			while(ss >> num) v[i].pb(num);
		}
		REP(i, p)	m = min(m, (int)v[i].size());
		REP(i, p) if(v[i].size() == m) res.pb(i+1);
		REP(i, res.size()) printf("%d%c", res[i], i == res.size()-1 ? '\n':' ');
		if(n) getline(cin, line);
	}
  return 0;
}
