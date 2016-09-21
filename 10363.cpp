#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

/*
	Here the tricky part is:
		ºX is always greater or equal to O;
		ºThe maximum difference between the two is 1;
		ºIf X wins, then O has to have 1 less them him;
		ºIf O wins, then X is equal to him;
		ºBoth can't win;
		ºThe only one that can score in twice is X because the
		  maximum number of X is 5 and O is 4, and to score t-
		  wice the number of occurences must be 5;

		Note: Not a trivial question, need some thinking.
*/

int main(){
	int n;
	cin >> n;
	while(n--){
		bool ok = true;
		int O = 0, X = 0;
		char board[3][3];
		FOR(i, 3){
			FOR(j, 3){
				cin >> board[i][j];
			}
			scanf("%*c");
		}
		
		FOR(i, 3){
			FOR(j, 3){
				if(board[i][j] == 'O') O++;
				else if(board[i][j] == 'X') X++;
			}
		}
		if(O > X) ok = false;
		else if(X - O > 1) ok = false;
		else{
			int o = 0, x = 0;
			if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') x++;
			if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') x++;
			if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') x++;
			if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') x++;
			if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') x++;
			if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') x++;
			if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') x++;
			if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') x++;
			
			if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') o++;
			if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') o++;
			if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') o++;
			if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') o++;
			if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') o++;
			if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') o++;
			if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') o++;
			if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') o++;
			
			if(x >= 1 && o >= 1) ok = false;
			else if(x == 1 && o == 0 && X - O != 1) ok = false;
			else if(x == 0 && o == 1 && O - X != 0) ok = false;
		}
		printf("%s\n", ok ? "yes" : "no");
	}
  return 0;
}





