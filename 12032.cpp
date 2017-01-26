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

vector<int> jumps;

bool can(int k){
	bool ok = true;
	for(int i = 0; i < jumps.size(); i++){
		if(jumps[i] == k) k--;
		else if(jumps[i] > k) ok = false;
	}
	return ok;
}

int bs(){
	int h = 1, t = 10000000, b;
	while(h <= t){
		b = (h+t)/2;
		if(can(b)){
			if(b == 1 || !can(b-1)) return b;
			else t = b - 1;
		} else h = b + 1;
	}
}

int main(){
	int t, caso = 1, n;
	scanf("%d", &t);
	while(t--){
		jumps.clear();
		scanf("%d", &n);
		int v[n], curr = 0;
		REP(i, n){
			scanf("%d", &v[i]);
			jumps.pb(abs(curr-v[i]));
			curr = v[i];
		}
		printf("Case %d: %d\n", caso++, bs());
	}
  return 0;
}
