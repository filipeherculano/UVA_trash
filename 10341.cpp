#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

double p, q, r, s, t, u;

double eq(double x){
	return (p* exp(-x) )+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*x*x)+(u);
}

double bs(double h, double t){
	double b;
	while(h + EPS < t){
		b = (h+t) / 2;
		if(eq(h) * eq(b) <= 0) t = b;
		else h = b;
	}
	return b;
}

int main(){
	while(~scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u)){
		if(eq(0.0) * eq(1.0) > 0) cout << "No solution\n";
		else printf("%.4lf\n", bs(0.0, 1.0));	
	}	
  return 0;
}
