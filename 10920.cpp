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
	unsigned long long sz, p;
	vector<unsigned long long> period;
	vector<unsigned long long>::iterator it;
	for(unsigned long long i = 0; i < 100000; i++) period.pb(6 + (i*8));
	FOR(i, 1, 100000) period[i] += period[i-1];
	while(cin >> sz >> p && (sz || p)){
		unsigned long long line = (sz+1)/2, col = (sz+1)/2, base = 1, T = 0;
		p--;
		it = upper_bound(all(period), p);
		T = it-period.begin();
		if(T) p -= period[T-1];
		line -= T; col += T;
		base += (2*T);
		if(p >= base){
			line += base;
			p -= base;
		} else {
			line += p;
			p = 0;
		}
		if(p >= base){
			col -= base;
			p -= base;
		} else {
			col -= p;
			p = 0;
		}
		base++;
		if(p >= base){
			line -= base;
			p -= base;
		} else {
			line -= p;
			p = 0;
		}
		if(p >= base){
			col += base;
			p -= base;
		} else {
			col += p;
			p = 0;
		}
		printf("Line = %d, column = %d.\n", line, col);
	}
  return 0;
}
