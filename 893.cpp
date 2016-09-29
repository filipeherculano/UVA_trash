#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	long long t, d, m, a;
	while(cin >> t >> d >> m >> a && (t || d || m || a)){
		long long mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		long long total = d, index = 0;
		
		FOR(i, m-1){
			if((!(a % 400) ^ (!(a % 4) && a % 100)) && i == 1) total++;
			total += mon[i];
		}
		
		while(t > 365){
			if(!(a % 400) ^ (!(a % 4) && a % 100)) t--;
			t -= 365;
			a++;
		}
		
		if(!(a % 400) ^ (!(a % 4) && a % 100)){
			t += total;
			if(t > 366) {
				a++;
				t -= 366;
			}
			if(!(a % 400) ^ (!(a % 4) && a % 100)) mon[1]++;
			FOR(i, 12) {
				index = i;
				if(mon[i] >= t) break;
				t -= mon[i];
			}
		} else{
			t += total;
			if(t > 365) {
				a++;
				t -= 365;
			}
			if(!(a % 400) ^ (!(a % 4) && a % 100)) mon[1]++;
			FOR(i, 12) {
				index = i;
				if(mon[i] >= t) break;
				t -= mon[i];
			}
		}
		printf("%lld %lld %lld\n", t, index+1, a);
	}
  return 0;
}
