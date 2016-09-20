#include <bits/stdc++.h>
#define FOR(i,n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int board[8][8];

void vertical(int x, int y, int dir, int k){
	if(dir == 2){
		if(x && board[x-1][y]) vertical(x-1, y, 1, k);
		if(x < 7 && board[x+1][y]) vertical(x+1, y, 0, k);
	} else if(dir == 1){
		board[x][y] = 2;
		if(k) return;
		else if(x && board[x-1][y]) vertical(x-1, y, 1, k);
	} else if(dir == 0){
		board[x][y] = 2;
		if(k) return;
		else if(x < 7 && board[x+1][y]) vertical(x+1, y, 0, k);
	}
}

void horizontal(int x, int y, int dir, int k){
	if(dir == 2){
		if(y && board[x][y-1]) horizontal(x, y-1, 1, k); // left
		if(y < 7 && board[x][y+1]) horizontal(x, y+1, 0, k); // right
	} else if(dir == 1){
		board[x][y] = 2;
		if(k) return;
		else if(y && board[x][y-1]) horizontal(x, y-1, 1, k);
	} else if(dir == 0){
		board[x][y] = 2;
		if(k) return;
		else if(y < 7 && board[x][y+1]) horizontal(x, y+1, 0, k);
	}
}

void diagonalNE(int x, int y, int dir, int k){
	if(dir == 2){ // both
		if(x && y < 7 && board[x-1][y+1]) diagonalNE(x-1, y+1, 1, k);
		if(x < 7 && y && board[x+1][y-1]) diagonalNE(x+1, y-1, 0, k);	
	} else if(dir == 1){ // up
		board[x][y] = 2;
		if(k) return;
		else if(x && y < 7 && board[x-1][y+1]) diagonalNE(x-1, y+1, 1, k);
	} else if(dir == 0){ // down
		board[x][y] = 2;
		if(k) return;
		else if(x < 7 && y && board[x+1][y-1]) diagonalNE(x+1, y-1, 0, k);	
	}
}

void diagonalNO(int x, int y, int dir, int k){
	if(dir == 2){ // both
		if(x && y && board[x-1][y-1]) diagonalNO(x-1, y-1, 1, k);
		if(x < 7 && y < 7 && board[x+1][y+1]) diagonalNO(x+1, y+1, 0, k);		
	} else if(dir == 1){ // up
		board[x][y] = 2;
		if(k) return;
		else if(x && y && board[x-1][y-1]) diagonalNO(x-1, y-1, 1, k);
	} else if(dir == 0){ // down
		board[x][y] = 2;
		if(k) return;
		else if(x < 7 && y < 7 && board[x+1][y+1]) diagonalNO(x+1, y+1, 0, k);		
	}
}

int main(){
	string line;
	while(getline(cin, line)){
		int j = 0, k = 0, count = 0;
		FOR(i, 8) FOR(j, 8) board[i][j] = 1;
		FOR(i, line.size()){
			if(line[i] >= '1' && line[i] <= '8') k += (line[i] - '0')-1;
			else if(line[i] == '/') {j++;k=-1;}
			else board[j][k] = 0;
			k++;
		}
		j = 0; k = 0;
		FOR(i, line.size()){
			if(line[i] >= '1' && line[i] <= '8') k += (line[i] - '0')-1;
			else if(line[i] == '/') {j++;k=-1;}
			else {
				if(line[i] == 'k' || line[i] == 'K'){ // ok
					diagonalNO(j, k, 2, 1);
					diagonalNE(j, k, 2, 1);
					horizontal(j, k, 2, 1);
					vertical(j, k, 2, 1);
				} else if(line[i] == 'n' || line[i] == 'N'){
					if(j-2 >= 0 && k+1 < 8 	&& board[j-2][k+1]) board[j-2][k+1] = 2;
					if(j-2 >= 0 && k-1 >= 0 && board[j-2][k-1]) board[j-2][k-1] = 2;
					if(j+1 < 8	&& k-2 >= 0 && board[j+1][k-2]) board[j+1][k-2] = 2;
					if(j-1 >= 0 && k-2 >= 0 && board[j-1][k-2]) board[j-1][k-2] = 2;
					if(j+2 < 8 	&& k+1 < 8 	&& board[j+2][k+1]) board[j+2][k+1] = 2;
					if(j+2 < 8 	&& k-1 >= 0 && board[j+2][k-1]) board[j+2][k-1] = 2;
					if(j+1 < 8 	&& k+2 < 8 	&& board[j+1][k+2]) board[j+1][k+2] = 2;
					if(j-1 >= 0 && k+2 < 8 	&& board[j-1][k+2]) board[j-1][k+2] = 2;
				} else if(line[i] == 'p' || line[i] == 'P'){ // ok
					if(line[i] == 'p') {
						if(j < 7 && k < 7 && board[j+1][k+1]) board[j+1][k+1] = 2;
						if(j < 7 && k && board[j+1][k-1]) board[j+1][k-1] = 2;
					} else if(line[i] == 'P'){
						if(j && k && board[j-1][k-1]) board[j-1][k-1] = 2; 
						if(j && k < 7 && board[j-1][k+1]) board[j-1][k+1] = 2;
					}
				} else if(line[i] == 'b' || line[i] == 'B'){ // ok
					diagonalNO(j, k, 2, 0);
					diagonalNE(j, k, 2, 0);
				} else if(line[i] == 'r' || line[i] == 'R'){ // ok
					horizontal(j, k, 2, 0);
					vertical(j, k, 2, 0);
				} else if(line[i] == 'q' || line[i] == 'Q'){ // ok
					diagonalNO(j, k, 2, 0);
					diagonalNE(j, k, 2, 0);
					horizontal(j, k, 2, 0);
					vertical(j, k, 2, 0);
				}
			}
			k++;
		}
		FOR(i, 8) FOR(j, 8) if(board[i][j] == 1) count++;
		cout << count << endl;
	}
  return 0;
}





