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

int row[8], a, b, lineCnt;

bool place(int r, int c){
	for(int prev = 0; prev < c; prev++)
		if(row[prev] == r || abs(row[prev]-r) == abs(prev-c))
			return false;
	return true;
}

void backtrack(int c){
	if(c == 8 && row[b] == a){
		printf("%2d      %d", ++lineCnt, row[0]+1);
		for(int j = 1; j < 8; j++) printf(" %d", row[j]+1);
		printf("\n");
	}
	for(int r = 0; r < 8; r++){
		if(place(r,c)){
			row[c] = r;
			backtrack(c+1);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		a--; b--;
		memset(row, 0, sizeof(row));
		lineCnt = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if(t) cout << endl;
	}
  return 0;
}
