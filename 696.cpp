#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int m, n;
	while(cin >> m >> n && (m || n)){
		int ans;
		if(min(n,m) == 1) ans = max(n,m);
		else if(min(n,m) == 2) ans = min(n,m)*((2*((max(n,m)+3)/4)) - (max(n,m) % 4 == 1 ? 1 : 0));
		else ans = ((n*m)+1)/2; 
		printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
  	}
	return 0;
}
