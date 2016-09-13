#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  long double h, u, d, f;
  while(cin >> h >> u >> d >> f && h){
    int day = 1;
    long double ini = 0.0, fatigue = u*(f/100.0);
    while(1){
      if(u > 0.0) ini += u;
      if(ini > h) break;
      ini -= d;
      if(ini < 0.0) break;
      day++;
      u -= fatigue;
    }
    printf("%s on day %d\n", ini < 0.0 ? "failure" : "success", day);
  }
  return 0;
}
