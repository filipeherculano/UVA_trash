#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n, caso = 1;
	double c, f;
	cin >> n;
	while(n--){
		cin >> c >> f;
		c += (((f-32.0)*5.0)/9.0) - (((0.0-32.0)*5.0)/9.0);
		printf("Case %d: %.2lf\n", caso++, c);
	}
  return 0;
}
