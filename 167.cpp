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

int mat[8][8], pos[8];

bool place(int r, int c){
	REP(col, c){
		if(r == pos[col] || abs(r-pos[col]) == abs(c-col))
			return false;
	}
	return true;
}

int backtrack(int c){
	int res = 0;
	if(c == 8){
		int sum = 0;
		REP(i, 8) sum += mat[pos[i]][i];
		return sum;
	}
	
	REP(r, 8){
		if(place(r,c)){
			pos[c] = r;
			res = max(res,backtrack(c+1));
		}
	}
	return res;
}

int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		REP(i, 8) REP(j, 8) scanf("%d", &mat[i][j]);
		printf("%5d\n", backtrack(0));
	}
  return 0;
}
