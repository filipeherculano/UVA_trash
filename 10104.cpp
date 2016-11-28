#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

ll x, y, d;

void euclid(ll a, ll b){
  if(b == 0){
    x = 1;
    y = 0;
    d = a;
    return; 
  }
  euclid(b, a%b);
  ll x1 = y;
  ll y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}

int main(){
  ll a, b;
  while(~scanf("%lld %lld", &a, &b)){
    euclid(a, b);
    printf("%lld %lld %lld\n", x, y, d);
  }
  return 0;
}
