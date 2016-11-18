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
	int n;
	while(scanf("%d: ", &n) && n){
		bool ok = true;
		vector<int> vi(n);
		vector<int> mii(n);
		REP(i,n) cin >> vi[i];
		for(int i = 0; i < n; i++) mii[vi[i]] = i;
		for(int i = 0; i < n-2 && ok; i++){
			int diff = n/2;
			for(int j = -diff; (vi[i]+(2*j)) < n && ok; j++){	
				if(j && ((vi[i]+j < n && vi[i]+j >= 0) && (vi[i]+(2*j) < n && vi[i]+(2*j) >= 0))) {
					int a, b;
					a = mii[vi[i]+j];
					b = mii[vi[i]+(2*j)];	
					if(a < b && i < a) ok = false;
				}
			}
		}
		printf("%s", ok ? "yes\n":"no\n");
	}
  return 0;
}
