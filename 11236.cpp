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

int main(){
	vector<int> vi;
	set< vector<int> > s;
	for(int a = 1; 4*a <= 2000; a++){
		for(int b = a; a + 3*b <= 2000; b++){
			for(int c = b; a + b + 2*c <= 2000; c++){
				ll p = a*b*c, s = a+b+c;

				if(p > 1000000){
					ll d = (1000000*s) / (p - 1000000);

					if(d < c || d + s > 2000) continue;

					if(fabs(((a+b+c+d)/100.0)-((a*b*c*d)/100000000.0)) < EPS)
						printf("%.2lf %.2lf %.2lf %.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
				} else continue;
			}
		}
	}
  return 0;
}
