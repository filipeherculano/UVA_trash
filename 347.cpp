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

bool runAround(int i){
	string line = to_string(i);
	int dig[10] = {0}, vis[line.size()] = {0}, curr = 0;
	REP(i, line.size()) {
		if(dig[line[i] - '0'] || (line[i] - '0') == 0) return false;
		else dig[line[i] - '0'] = 1;
	}
	do{
		vis[curr]++;
		curr = ((line[curr]-'0')+curr)%line.size();
	} while((curr == 0 && vis[curr] == 1) || vis[curr] == 0);
	
	if(vis[0] != 2) return false;
	
	REP(i, line.size()) 
		if(vis[i] == 0 || (i != 0 && vis[i] > 1))
			return false;
	return true;
}

int main(){
	string line;
	vector<int> global;
	vector<int>::iterator it;
	int caso = 1;
	FOR(i, 1, 9876543)
		if(runAround(i))
			global.pb(i);
			
	while(cin >> line && line != "0"){
		printf("Case %d: ", caso++);
		it = upper_bound(all(global), stoi(line));
		cout << *it << endl;
	}	
  return 0;
}
