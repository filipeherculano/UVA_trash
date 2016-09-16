#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  bool isFirst = true;
  int t, d;
  scanf("%d%*c%*c", &t);
  while(t--){
    scanf("%d%*c", &d);
    bool touched = false;
    if(!isFirst) cout << endl;
    isFirst = false;
    char matrix[d][d], c;
    for(int i = 0; i < d; i++)
      for(int j = 0; j < d; j++)
        cin >> matrix[i][j];

    for(int i = 0; i < d; i++){
      for(int j = 0; j < d; j++){
        if(matrix[i][j] == '.') matrix[i][j] = '0';
        if(matrix[i][j] == '*'){
          if(i-1 >= 0 && j-1 >= 0) {
            if(matrix[i-1][j-1] == '.') matrix[i-1][j-1] = '1';
            else if(matrix[i-1][j-1] >= 48) matrix[i-1][j-1]++;
          }
          if(i-1 >= 0 && j >= 0){
            if(matrix[i-1][j] == '.') matrix[i-1][j] = '1';
            else if(matrix[i-1][j] >= 48) matrix[i-1][j]++;
          }    
          if(i-1 >= 0 && j+1 < d){
            if(matrix[i-1][j+1] == '.') matrix[i-1][j+1] = '1';
            else if(matrix[i-1][j+1] >= 48) matrix[i-1][j+1]++;
          }   
          if(i+1 < d && j-1 >= 0) {
            if(matrix[i+1][j-1] == '.') matrix[i+1][j-1] = '1';
            else if(matrix[i+1][j-1] >= 48) matrix[i+1][j-1]++;
          }  
          if(i+1 < d && j >= 0) {
            if(matrix[i+1][j] == '.') matrix[i+1][j] = '1';
            else if(matrix[i+1][j] >= 48) matrix[i+1][j]++;
          }    
          if(i+1 < d && j+1 < d) {
            if(matrix[i+1][j+1] == '.') matrix[i+1][j+1] = '1';
            else if(matrix[i+1][j+1] >= 48) matrix[i+1][j+1]++;
          }   
          if(i >= 0 && j+1 < d) {
            if(matrix[i][j+1] == '.') matrix[i][j+1] = '1';
            else if(matrix[i][j+1] >= 48) matrix[i][j+1]++;
          }  
          if(i >= 0 && j-1 >= 0) {
            if(matrix[i][j-1] == '.') matrix[i][j-1] = '1';
            else if(matrix[i][j-1] >= 48) matrix[i][j-1]++;
          }   
        }	
      }
    }
    for(int i = 0; i < d; i++){
      for(int j = 0; j < d; j++){
        cin >> c;
        if(c == 'x' && matrix[i][j] == '*') touched = true;
        else if(c == '.' && matrix[i][j] != '*') matrix[i][j] = '.';
      }
    }
    for(int i = 0; i < d; i++)
      for(int j = 0; j < d; j++)
        if(matrix[i][j] == '*' && !touched) matrix[i][j] = '.';

    for(int i = 0; i < d; i++){
      for(int j = 0; j < d; j++)
        cout << matrix[i][j];
      cout << endl;
    }
  }
  return 0;
}




