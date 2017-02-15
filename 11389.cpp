#include <bits/stdc++.h>

#define X first
#define Y second
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n,d,r;
	while(scanf("%d %d %d", &n, &d, &r) && n){
		int cnt = 0;
		vector<int> v(n), w(n);
		REP(i,n) scanf("%d", &v[i]);
		REP(i,n) scanf("%d", &w[i]);
		sort(all(v));
		sort(all(w));
		for(int i = 0; i < n; i++) cnt += max(0,(v[i]+w[n-1-i]) - d);
		cout << r*cnt << endl;
	}
	return 0;
}
