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

bool isOK(vector<string> matrix, int r, int c){
	REP(i, r) {
		int zero = 0;
		REP(j, c) {
			if(matrix[i][j] == '0') zero++;
		}
		if(!zero) return false;
	}
	return true;
}

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	while(t--){
		int r, c, moves = INF;
		scanf("%d %d%*c", &r, &c);
		vector<string> matrix(r);
		REP(i, r) getline(cin, matrix[i]);
		
		if(isOK(matrix, r, c)){
			REP(i, c){
				int temp = 0;
				REP(j, r){
					if(matrix[j][i] == '1'){
						int dist = INF;
						REP(k, c){
							if(matrix[j][k] == '0') dist = min(dist, abs(i-k));
							if(dist == 1) break;
						}
						temp += dist;
					}
				}
				moves = min(moves, temp);
			}
			printf("Case %d: %d\n", caso++, moves);
		} else printf("Case %d: -1\n", caso++);
	}
  return 0;
}




