#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;


using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m = INF, pos = 0;
		scanf("%d", &n);
		int v[n];
		REP(i, n) cin >> v[i];
		REP(i, n){
			int sum = 0;
			REP(j, n) sum += abs(v[i]-v[j]);
			m = min(sum, m);
		}
		cout << m << endl;
	}
  return 0;
}
