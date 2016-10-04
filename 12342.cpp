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
	ll caso = 1, t, income;
	cin >> t;
	while(t--){
		double tax = 0.0;
		cin >> income;
		if(income > 1180000) {
			tax += 0.25 * (income - 1180000);
			income = 1180000;
		}
		tax = ceil(tax);
		if(income > 880000){
			tax += 0.20 * (income - 880000);
			income = 880000;
		}
		tax = ceil(tax);
		if(income > 480000){
			tax += 0.15 * (income - 480000);
			income = 480000;
		}
		tax = ceil(tax);
		if(income > 180000){
			tax += 0.1 * (income - 180000);
			income = 180000;
		}
		tax = ceil(tax);
		if(tax < 2000 && tax != 0.0) tax = 2000;
		printf("Case %lld: %lld\n", caso++, (long long)tax);
	}
  return 0;
}
