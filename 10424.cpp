#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  string a, b;
  while(getline(cin, a)){
    int sumA = 0, sumB = 0;
    getline(cin, b);
    for(int i = 0; i < a.size(); i++){
      if(a[i] >= 65 && a[i] <= 90) sumA += a[i] - 'A' + 1;
      else if(a[i] >= 97 && a[i] <= 122) sumA += a[i] - 'a' + 1;
    }
    for(int i = 0; i < b.size(); i++){
      if(b[i] >= 65 && b[i] <= 90) sumB += b[i] - 'A' + 1;
      else if(b[i] >= 97 && b[i] <= 122) sumB += b[i] - 'a' + 1;
    }
    while(sumA/10 > 0){
      int auxA = 0;
      while(sumA){
        auxA += sumA % 10;
        sumA /= 10;
      }
      sumA = auxA;
    }
    while(sumB/10 > 0){
      int auxB = 0;
      while(sumB){
        auxB += sumB % 10;
        sumB /= 10;
      }
      sumB = auxB;
    }
    if(sumA > sumB) printf("%.2lf %%", ((double)sumB/(double)sumA)*100.0);
    else if(sumA < sumB) printf("%.2lf %%",((double)sumA/(double)sumB)*100.0);
    else if(sumA == sumB && sumA) printf("100.00 %%");
    cout << endl;
  }
  return 0;
}
