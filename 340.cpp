#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  int n, game = 1;
  while(cin >> n && n){
    printf("Game %d:\n", game++);
    int c[n], g[n];
    for(int i = 0; i < n; i++)
      cin >> c[i];
    while(1){
      vector<int> temp(c, c + sizeof(c)/sizeof(int));
      vector<int>::iterator it;
      int strong = 0, weak = 0;
      for(int i = 0; i < n; i++)
        cin >> g[i];
      if(!g[0]) break;
      for(int i = 0; i < n; i++){
        if(g[i] == c[i]) {
          strong++;
          for(it = temp.begin(); it != temp.end(); it++){
            if(*it == g[i]){
              temp.erase(it);
              break;
            }
          }
          g[i] = 0;
        }
      }
      for(int i = 0; i < n; i++){ 
        if(g[i]){
          for(it = temp.begin(); it != temp.end(); it++){
            if(*it == g[i]){
              weak++;
              temp.erase(it);
              break;
            }
          }
        }
      }
      printf("    (%d,%d)\n", strong, weak);
    }
  }
  return 0;
}
