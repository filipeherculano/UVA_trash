#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	bool isFirst = true;
	int t;
	scanf("%d%*c", &t);
	while(t--){
		scanf("%*c");
		if(!isFirst) cout << endl;
		isFirst = false;
		
		string line;
		stringstream ss;
		vector<int> vi;
		vector<string> vd;
		int aux;
		string temp;
		
		getline(cin, line);
		ss << line;
		while(ss >> aux) vi.pb(aux);
		ss.clear();
		getline(cin, line);
		ss << line;
		while(ss >> temp) vd.pb(temp);
		vector<string> res(vd.size());
		REP(i, vi.size()) res[vi[i]-1] = (vd[i]);
		REP(i, vd.size()) cout << res[i] << endl;
	}
  return 0;
}
