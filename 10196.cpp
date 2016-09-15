#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  int game = 1;
  while(1){
    bool onlyDot = true, black = false, white = false;
    char matrix[8][8];
	pair<int,int> bcoor, wcoor;
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        cin >> matrix[i][j];
        if(matrix[i][j] != '.') onlyDot = false;
		if(matrix[i][j] == 'k') {bcoor.first = i; bcoor.second = j;}
		if(matrix[i][j] == 'K') {wcoor.first = i; wcoor.second = j;}
      }
    }
    if(onlyDot) break;
  	for(int j = bcoor.second+1; j < 8 && !black; j++){
		if(matrix[bcoor.first][j] != '.'){
			if(matrix[bcoor.first][j] == 'R' || matrix[bcoor.first][j] == 'Q') black = true;
			break;
		}
	} // right side
  	for(int j = bcoor.second-1; j >= 0 && !black; j--){
		if(matrix[bcoor.first][j] != '.'){
			if(matrix[bcoor.first][j] == 'R' || matrix[bcoor.first][j] == 'Q') black = true;
			break;
		}
	} // left side
  	for(int i = bcoor.first+1; i < 8 && !black; i++){
		if(matrix[i][bcoor.second] != '.'){
			if(matrix[i][bcoor.second] == 'R' || matrix[i][bcoor.second] == 'Q') black = true;
			break;
		}
	} // down
  	for(int i = bcoor.first-1; i >= 0 && !black; i--){
		if(matrix[i][bcoor.second] != '.'){
			if(matrix[i][bcoor.second] == 'R' || matrix[i][bcoor.second] == 'Q') black = true;
			break;
		}
	} // up
	for(int i = bcoor.first+1, j = bcoor.second+1; i < 8 && j < 8 && !black; i++){
		if(matrix[i][j] != '.'){
			if(i - bcoor.first == 1 && j - bcoor.second == 1 && matrix[i][j] == 'P') black = true;
			else if(matrix[i][j] == 'B' || matrix[i][j] == 'Q') black = true;
			break;
		}
		j++;
	} // south-east diagonal
	for(int i = bcoor.first+1, j = bcoor.second-1; i < 8 && j >= 0 && !black; i++){
		if(matrix[i][j] != '.'){
			if(i - bcoor.first == 1 && bcoor.second - j == 1 && matrix[i][j] == 'P') black = true;
			else if(matrix[i][j] == 'B' || matrix[i][j] == 'Q') black = true;
			break;
		}
		j--;
	} // south-west diagonal
	for(int i = bcoor.first-1, j = bcoor.second+1; i >= 0 && j < 8 && !black; i--){
		if(matrix[i][j] != '.'){
			if(matrix[i][j] == 'B' || matrix[i][j] == 'Q') black = true;
			break;
		}
		j++;
	} // north-east diagonal
	for(int i = bcoor.first-1, j = bcoor.second-1; i >= 0 && j >= 0 && !black; i--){
		if(matrix[i][j] != '.'){
			if(matrix[i][j] == 'B' || matrix[i][j] == 'Q') black = true;
			break;
		}
		j--;
	} // north-west diagonal
	if(bcoor.first-2 >= 0 && bcoor.second+1 < 8 &&  matrix[bcoor.first-2][bcoor.second+1] == 'N') black = true;
	if(bcoor.first-2 >= 0 && bcoor.second-1 >= 0 && matrix[bcoor.first-2][bcoor.second-1] == 'N') black = true;
	if(bcoor.first+1 < 8 &&  bcoor.second-2 >= 0 && matrix[bcoor.first+1][bcoor.second-2] == 'N') black = true;
	if(bcoor.first-1 >= 0 && bcoor.second-2 >= 0 && matrix[bcoor.first-1][bcoor.second-2] == 'N') black = true;
	if(bcoor.first+2 < 8 &&  bcoor.second+1 < 8 &&  matrix[bcoor.first+2][bcoor.second+1] == 'N') black = true;
	if(bcoor.first+2 < 8 &&  bcoor.second-1 >= 0 && matrix[bcoor.first+2][bcoor.second-1] == 'N') black = true;
	if(bcoor.first+1 < 8 &&  bcoor.second+2 < 8 &&  matrix[bcoor.first+1][bcoor.second+2] == 'N') black = true;
	if(bcoor.first-1 >= 0 && bcoor.second+2 < 8 &&  matrix[bcoor.first-1][bcoor.second+2] == 'N') black = true;
	// knight positions

  	for(int j = wcoor.second+1; j < 8 && !white; j++){
		if(matrix[wcoor.first][j] != '.'){
			if(matrix[wcoor.first][j] == 'r' || matrix[wcoor.first][j] == 'q') white = true;
			break;
		}
	} // right side
  	for(int j = wcoor.second-1; j >= 0 && !white; j--){
		if(matrix[wcoor.first][j] != '.'){
			if(matrix[wcoor.first][j] == 'r' || matrix[wcoor.first][j] == 'q') white = true;
			break;
		}
	} // left side
  	for(int i = wcoor.first+1; i < 8 && !white; i++){
		if(matrix[i][wcoor.second] != '.'){
			if(matrix[i][wcoor.second] == 'r' || matrix[i][wcoor.second] == 'q') white = true;
			break;
		}
	} // down
  	for(int i = wcoor.first-1; i >= 0 && !white; i--){
		if(matrix[i][wcoor.second] != '.'){
			if(matrix[i][wcoor.second] == 'r' || matrix[i][wcoor.second] == 'q') white = true;
			break;
		}
	} // up
	for(int i = wcoor.first+1, j = wcoor.second+1; i < 8 && j < 8 && !white; i++){
		if(matrix[i][j] != '.'){
			if(matrix[i][j] == 'b' || matrix[i][j] == 'q') white = true;
			break;
		}
		j++;
	} // south-east diagonal
	for(int i = wcoor.first+1, j = wcoor.second-1; i < 8 && j >= 0 && !white; i++){
		if(matrix[i][j] != '.'){
			if(matrix[i][j] == 'b' || matrix[i][j] == 'q') white = true;
			break;
		}
		j--;
	} // south-west diagonal
	for(int i = wcoor.first-1, j = wcoor.second+1; i >= 0 && j < 8 && !white; i--){
		if(matrix[i][j] != '.'){
			if(wcoor.first - i == 1 && j - wcoor.second == 1 && matrix[i][j] == 'p') white = true;
			else if(matrix[i][j] == 'b' || matrix[i][j] == 'q') white = true;
			break;
		}
		j++;
	} // north-east diagonal
	for(int i = wcoor.first-1, j = wcoor.second-1; i >= 0 && j >= 0 && !white; i--){
		if(matrix[i][j] != '.'){
			if(wcoor.first - i == 1 && wcoor.second - j == 1 && matrix[i][j] == 'p') white = true;
			else if(matrix[i][j] == 'b' || matrix[i][j] == 'q') white = true;
			break;
		}
		j--;
	} // north-west diagonal
	if(wcoor.first-2 >= 0 && wcoor.second+1 < 8 &&  matrix[wcoor.first-2][wcoor.second+1] == 'n') white = true;
	if(wcoor.first-2 >= 0 && wcoor.second-1 >= 0 && matrix[wcoor.first-2][wcoor.second-1] == 'n') white = true;
	if(wcoor.first+1 < 8 &&  wcoor.second-2 >= 0 && matrix[wcoor.first+1][wcoor.second-2] == 'n') white = true;
	if(wcoor.first-1 >= 0 && wcoor.second-2 >= 0 && matrix[wcoor.first-1][wcoor.second-2] == 'n') white = true;
	if(wcoor.first+2 < 8 &&  wcoor.second+1 < 8 &&  matrix[wcoor.first+2][wcoor.second+1] == 'n') white = true;
	if(wcoor.first+2 < 8 &&  wcoor.second-1 >= 0 && matrix[wcoor.first+2][wcoor.second-1] == 'n') white = true;
	if(wcoor.first+1 < 8 &&  wcoor.second+2 < 8 &&  matrix[wcoor.first+1][wcoor.second+2] == 'n') white = true;
	if(wcoor.first-1 >= 0 && wcoor.second+2 < 8 &&  matrix[wcoor.first-1][wcoor.second+2] == 'n') white = true;
	// knight positions
	
    if(black) printf("Game #%d: black king is in check.\n", game++);
    else if(white) printf("Game #%d: white king is in check.\n", game++);
    else printf("Game #%d: no king is in check.\n", game++);
	scanf("%*c");
  }
  return 0;
}
