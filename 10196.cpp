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
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        cin >> matrix[i][j];
        if(matrix[i][j] != '.') onlyDot = false;
      }
    }
    if(onlyDot) break;
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if(matrix[i][j] == 'p'){
        } else if(matrix[i][j] == 'P'){
        } else if(matrix[i][j] == 'n'){
        } else if(matrix[i][j] == 'N'){
        } else if(matrix[i][j] == 'b'){
        } else if(matrix[i][j] == 'B'){
        } else if(matrix[i][j] == 'r'){
        } else if(matrix[i][j] == 'R'){
        } else if(matrix[i][j] == 'q'){
        } else if(matrix[i][j] == 'Q'){
        } else if(matrix[i][j] == 'k'){
        } else if(matrix[i][j] == 'K'){
        }
      }
    }
    if(black) printf("Game #%d: black king is in check.\n", game++);
    else if(white) printf("Game #%d: white king is in check.\n", game++);
    else printf("Game #%d: no king is in check.\n", game++);
  }
  return 0;
}
