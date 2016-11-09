#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n], b[n-1] = {0}, sum = 0;
		REP(i,n) scanf("%d", &a[i]);
		FOR(i, 1, n)
			REP(j, i) b[i-1] += (a[j] <= a[i]);
		REP(i, n-1) sum += b[i];
		printf("%d\n", sum);
	}
  return 0;
}
