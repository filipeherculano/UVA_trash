#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define pow3(a) ((a)*(a)*(a))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	for(int a = 2; a <= 200; a++){
		for(int b = 2; b <= 200 && pow3(b) <= pow3(a); b++){
			for(int c = b; c <= 200 && pow3(b)+pow3(c) <= pow3(a); c++){
				for(int d = c; d <= 200 && pow3(b)+pow3(c)+pow3(d) <= pow3(a); d++){
					if(pow3(b)+pow3(c)+pow3(d) == pow3(a))
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
				}
			}
		}
	}
  return 0;
}
