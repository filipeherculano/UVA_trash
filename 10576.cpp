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
	int s, d, res;
	while(~scanf("%d %d", &s, &d)){
	
		if(4*s < d) res = 10*s - 2*d;
		else if(3*s < 2*d) res = 8*s - 4*d;
		else if(2*s < 3*d) res = 6*s - 6*d;
		else if(s < 4*d) res = 3*s - 9*d;
		else res = -1;
		
		if(res < 0) printf("Deficit\n");
		else printf("%d\n", res);
	}
  return 0;
}
