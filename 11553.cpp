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
const double EPS = 1e-9;

using namespace std;

int n;
vector< vector<int> > mat;
vector<int> pos;

bool place(int r, int c){
	REP(i, pos.size()){
		if(pos[i] == r || i == c)
			return false;
	}
	return true;
}

int backtrack(int c){
	int m = INF;
	if(c == n){
		int sum = 0;
		REP(i, pos.size()) {
			sum += mat[pos[i]][i];
			//cout << mat[pos[i]][i] << endl;	
			//printf("%d %d\n", pos[i], i);
		}
		return sum;
	}
	REP(r, n){
		if(place(r, c)){
			pos.pb(r);
			m = min(m, backtrack(c+1));
			pos.pop_back();
		}
	}
	return m;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int cnt = 0;
		scanf("%d", &n);
		mat.clear();
		REP(i, n){
			vector<int> temp(n);
			REP(j, n) scanf("%d", &temp[j]);
			mat.pb(temp);
		}
		cout << backtrack(0) << endl;
	}
  return 0;
}















