#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define X first
#define Y second

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

bool check(int i, int j, int b, int w, int val){
	return i >= 0 && i < b && j >= 0 && j < w && val != -1;
}

int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
  	int b,w;
	int ch[4][2] = {0,1,
			-1,0,
			0,-1,
			1,0};
	while(scanf("%d %d%*c", &b, &w) && (b || w)){
		int mat[b][w], state = 0, res[5] = {0};
		pair<int,int> ii = {b-1,0};
		REP(i,b) {
			string line;
			getline(cin,line);
			REP(j,w) mat[i][j] = (line[j]-'0'), mat[i][j] = (mat[i][j] == 1 ? -1:0);
		}
		while(!(ii.X == b-1 && ii.Y == 0 && mat[ii.X][ii.Y] == 1)){
			if(check(ii.X+ch[(state ? state-1:3)][0], ii.Y+ch[(state ? state-1:3)][1], b, w, 
				mat[ii.X+ch[(state ? state-1:3)][0]][ii.Y+ch[(state ? state-1:3)][1]])) {
				state = (state ? state-1:3);
				mat[ii.X][ii.Y]++;
				ii.X += ch[state][0];
				ii.Y += ch[state][1];
				continue;
			}
			if(check(ii.X+ch[state][0], ii.Y+ch[state][1], b, w, mat[ii.X+ch[state][0]][ii.Y+ch[state][1]])) {
				mat[ii.X][ii.Y]++;
				ii.X += ch[state][0];
				ii.Y += ch[state][1];
			} else state = (state+1)%4;
		}
		REP(i,b) REP(j,w) if(mat[i][j] >= 0 && mat[i][j] < 5) res[mat[i][j]]++;
		REP(i,5) printf("%3d", res[i]); cout << endl;
	}
	return 0;
}







