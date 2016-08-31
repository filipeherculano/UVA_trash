#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, set = 1;
  while(cin >> n && n){
    int sum = 0, h[n], moves = 0;
    for(int i = 0; i < n; i++){
      cin >> h[i];
      sum += h[i];
    }
    sum /= n;
    for(int i = 0; i < n; i++)
      if(h[i] > sum)
        moves += h[i] - sum;

    printf("Set #%d\nThe minimum number of moves is %d.\n\n", set++, moves);
  }
  return 0;  
}
