#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n, caso = 1;
	cin >> n;
	while(n--){
		int mil = 0;
		Lf close = 0.0, aux;
		FOR(i, 12){
			cin >> aux;
			close += aux/12.0;
		}
		printf("%d $", caso++);
		mil = close/1000.0;
		if(close >= 1000.0) printf("%d,", mil);
		close -= mil*1000.0;
		if(mil && close < 100.0) printf("0");
		if(mil && close < 10.0) printf("0");
		printf("%.2Lf\n", close);
	}
  return 0;
}
