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

using namespace std;

int main(){
	int f, r;
	while(scanf("%d %d", &f, &r) && f){
		double front[f], rear[r], m = 0.0;
		vector<double> vi;	
		REP(i,f) scanf("%lf", &front[i]);
		REP(i,r) scanf("%lf", &rear[i]);
		REP(i, f) REP(j, r) vi.pb(rear[j]/front[i]);
		sort(all(vi));
		FOR(i, 1, vi.size()) m = max(m, (vi[i]/vi[i-1]));
		printf("%.2lf\n", m);
	}
  return 0;
}
