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
	while(scanf("%d", &n) && n){
		int matrix[n][n], line[n] = {0}, col[n] = {0}, lineOdd = 0, colOdd = 0;
		REP(i, n) REP(j, n) cin >> matrix[i][j];
		REP(i, n) REP(j, n) {
			line[i] += matrix[i][j];
			col[j] += matrix[i][j];
		}
		REP(i, n){
			if(line[i]&1) lineOdd++;
			if(col[i]&1) colOdd++;
		}
		if(!lineOdd && !colOdd) printf("OK\n");
		else if(lineOdd == 1 && colOdd == 1) {
			int x, y;
			REP(i, n) if(line[i]&1) x = i+1;
			REP(i, n) if(col[i]&1) y = i+1;
			printf("Change bit (%d,%d)\n", x, y);
		} else printf("Corrupt\n");
	}
  return 0;
}
