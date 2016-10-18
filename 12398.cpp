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
	int caso = 1;
	string line;
	while(getline(cin, line)){
		int matrix[3][3];
		REP(i, 3) REP(j, 3) matrix[i][j] = 0;
		printf("Case #%d:\n", caso++);
		REP(i, line.size()){
			int coor = line[i] - 'a';
			if(coor-3 >= 0) matrix[(coor-3)/3][(coor-3)%3] = (matrix[(coor-3)/3][(coor-3)%3]+1)%10;
			if(coor+3 <= 8) matrix[(coor+3)/3][(coor+3)%3] = (matrix[(coor+3)/3][(coor+3)%3]+1)%10;
			if(coor % 3) matrix[(coor-1)/3][(coor-1)%3] = (matrix[(coor-1)/3][(coor-1)%3]+1)%10;
			if(coor % 3 != 2) matrix[(coor+1)/3][(coor+1)%3] = (matrix[(coor+1)/3][(coor+1)%3]+1)%10;
			matrix[coor/3][coor%3] = (matrix[coor/3][coor%3]+1)%10;
		}
		REP(i, 3) REP(j, 3) printf("%d%c", matrix[i][j], j == 2 ? '\n':' ');
	}
  return 0;
} 
