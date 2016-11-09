#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define EPS 1e-9

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	double vt, vz;
	while(scanf("%lf %lf", &vt, &vz) && (vt || vz)){
		int pos, cnt = 0;
		double size = -1.0;
		vector<double> res;
		for(int i = 1; (vt/(double)i) > vz; i++){
			res.pb(i*(0.3*(sqrt((vt/(double)i) - vz))));
			size = max(size, i*(0.3*(sqrt((vt/(double)i) - vz))));
		}
		REP(i,res.size()) {
			if(fabs(res[i] - size) < EPS) {
				cnt++;
				pos = i+1;
			}
		}
		if(cnt == 1) cout << pos << endl;
		else cout << "0\n"; 
	}
  return 0;
}
