#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int t, h, m;
	cin >> t;
	while(t--){
		int total;
		scanf("%d:%d", &h, &m);
		total = 60*h + m;
		total %= 720;
		total = 720 - total;
		if(total/60 < 10 && total/60) printf("0");
		if(total/60) printf("%d:", total/60);
		else printf("12:");
		if(total % 60 < 10) printf("0");
		printf("%d\n", total % 60);
	}
  return 0;
}
