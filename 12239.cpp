#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n, b;
	while(cin >> n >> b && (n || b)){
		bool ok = true;
		int v[b], num[n+1];
		memset(num, 0, sizeof(int)*(n+1));
		FOR(i, b) cin >> v[i];
		FOR(i, b) FOR(j, b) num[abs(v[j]-v[i])] = 1;
		FOR(i, n+1) if(!num[i]) ok = false;
		printf("%c\n", ok ? 'Y': 'N');
	}
  return 0;
}
