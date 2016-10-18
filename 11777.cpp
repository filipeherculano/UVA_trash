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
	int t, caso = 1;
	cin >> t;
	while(t--){
		double t1, t2, f, a, total = 0.0;
		vector<double> c(3);
		cin >> t1 >> t2 >> f >> a;
		REP(i, 3) cin >> c[i];
		sort(all(c));
		total += t1 + t2 + f + a + (c[1] + c[2])/2.0;
		printf("Case %d: ", caso++);
		if(total >= 90) printf("A\n");
		else if(total >= 80 && total < 90) printf("B\n");
		else if(total >= 70 && total < 80) printf("C\n");
		else if(total >= 60 && total < 70) printf("D\n");
		else printf("F\n");
	}
  return 0;
}
