#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int h1, h2, m1, m2;
	while(cin >> h1 >> m1 >> h2 >> m2 && (h1 || m1 || h2 || m2)){
		int start = h1*60 + m1, end = h2*60 + m2;
		if(start > end) printf("%d\n", (1440 - start + end));
		else printf("%d\n", (end-start));
	}
  return 0;
}
