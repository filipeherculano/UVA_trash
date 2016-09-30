#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	bool isFirst = true;
	int puzzle = 1;
	string matrix[5];
	while(getline(cin, matrix[0]) && matrix[0].compare("Z")){
		if(!isFirst) cout << endl;
		isFirst = false;
		string moves;
		int x, y;
		bool solution = true;
		FOR(i, 1, 5) getline(cin, matrix[i]);
		REP(i, 5) {
			if(matrix[i].size() == 5){
				REP(j, 5) if(matrix[i][j] == ' ') {x = i;	y = j;}
			} else {
				x = i;
				y = 4;
				matrix[i].pb(' ');
			}
		}
		while(getline(cin, moves)){
			bool zero = false;
			REP(i, moves.size()){
				if(moves[i] == '0') zero = true;
				else if(moves[i] == 'A'){
					if(x) {
						swap(matrix[x-1][y], matrix[x][y]);
						x--;
					} else solution = false;
				} else if(moves[i] == 'B'){
					if(x != 4) {
						swap(matrix[x+1][y], matrix[x][y]);
						x++;
					} else solution = false;
				} else if(moves[i] == 'L'){
					if(y) {
						swap(matrix[x][y-1], matrix[x][y]);
						y--;
					} else solution = false;
				} else if(moves[i] == 'R'){
					if(y != 4) {
						swap(matrix[x][y+1], matrix[x][y]);
						y++;
					} else solution = false;
				}
			}
			if(zero) break;
		}
		printf("Puzzle #%d:\n", puzzle++);
		if(solution) REP(i, 5) REP(j, 5)	printf("%c%c", matrix[i][j], j == 4 ? '\n':' ');
		else printf("This puzzle has no final configuration.\n");
	}
  return 0;
}
