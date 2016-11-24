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

int m, n, x, y;
vector<string> mat;
string path = "IEHOVA", res;

void backtrack(int x, int y, int idx){
	if(idx == 6){
		if(x && mat[x-1][y] == '#') res.append("forth");
		if(y && mat[x][y-1] == '#') res.append("left");
		if(y != n-1 && mat[x][y+1] == '#') res.append("right");
		return;
	}
	
	if(x && mat[x-1][y] == path[idx]){
		res.append("forth ");
		backtrack(x-1, y, idx+1);
	}
	if(y && mat[x][y-1] == path[idx]){
		res.append("left ");
		backtrack(x, y-1, idx+1);
	}
	if(y != n-1 && mat[x][y+1] == path[idx]){
		res.append("right ");
		backtrack(x, y+1, idx+1);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		string line;
		scanf("%d %d%*c", &m, &n);
		mat.clear();
		res.clear();
		REP(i, m){
			getline(cin, line);
			REP(j, line.size())
				if(line[j] == '@')
					{x = i; y = j;}
			mat.pb(line);
		}
		backtrack(x, y, 0);
		cout << res << endl;
	}
  return 0;
}
