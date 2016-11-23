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

int main(){
	int c, n;
	int mat[1001];
	for(int i = 1; i < 1001; i++){
		int res = INF;
		for(int a = 1; a*a <= i; a++){
			if(i%a == 0){
				for(int b = 1; b*b <= i/a; b++){
					if((i/a)%b == 0){
						int c = (i/a)/b;
						res = min(res, 2*(a*b + a*c + b*c));
					}
				}
			}
		}
		mat[i] = res;
	}
	scanf("%d", &c);
	while(c--){
		int n;
		scanf("%d", &n);
		printf("%d\n", mat[n]);
	}
  return 0;
}











