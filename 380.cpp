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

int curr = 0;
map<string, int> idx;
map<string, int>::iterator it;
map<int, vector< tuple<int,int,int> > > adj;
map<int, vector< tuple<int,int,int> > >::iterator jit;
vector<int> visited;

string dfs(int i, int time){
	if(visited[i]) return "9999";

	int sz = adj[i].size();
	visited[i] = 1;
	
	REP(j, sz){
		if(get<0>(adj[i][j]) <= time && time <= get<1>(adj[i][j]))
			return dfs(get<2>(adj[i][j]), time);
	}
	
	for(it = idx.begin(); it != idx.end(); it++)
		if(it->second == i) 
			return it->first;
}

int main(){
	int n, sys = 1;
	scanf("%d%*c", &n);
	printf("CALL FORWARDING OUTPUT\n");
	while(n--){
		string src, time, dur, target;
		curr = 0;
		idx.clear(); adj.clear();
		while(cin >> src && src != "0000"){
			cin >> time >> dur >> target;
			if(idx.find(src) == idx.end()) idx.insert(make_pair(src, curr++));
			if(idx.find(target) == idx.end()) idx.insert(make_pair(target, curr++));
			it = idx.find(src); jit = adj.find(it->second);
			tuple<int,int,int> t = make_tuple(stoi(time), stoi(time)+stoi(dur), idx[target]);
			vector< tuple<int,int,int> > vt; vt.pb(t);
			if(jit == adj.end()) adj.insert(make_pair(it->second, vt));
			else jit->second.pb(t);
		}
		printf("SYSTEM %d\n", sys++);
		while(cin >> time && time != "9000"){
			string res;
			visited.clear();
			REP(i, idx.size()) visited.pb(0);
			cin >> src;
			if(idx.find(src) == idx.end()) res = src;
			else res = dfs(idx[src], stoi(time));
			cout << "AT " << time << " CALL TO " << src << " RINGS " << res << endl;
		}
	}
	printf("END OF OUTPUT\n");
  return 0;
}




