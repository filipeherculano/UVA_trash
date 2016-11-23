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
	int n, t;
	while(~scanf("%d %d", &n, &t)){
		int v[t], tracks = 0, sum = 0;
		vector<int> res;
		REP(i, t) scanf("%d", &v[i]);
		for(int bitmask = 1; bitmask <= ((1 << t) - 1); bitmask++){
			vector<int> temp;
			int inTracks = 0, inSum = 0;
			for(int i = 0; i < t; i++){
				if(bitmask&(1 << i)) {
					inSum += v[i];
					inTracks++;
					temp.pb(v[i]);
				}
			}
			if(inSum <= n){
				if(inSum > sum){
					tracks = inTracks;
					sum = inSum;
					res = temp;
				} else if(inSum == sum){
					if(inTracks > tracks){
						tracks = inTracks;
						sum = inSum;
						res = temp;
					}
				}
			}
		}
		REP(i, res.size()) printf("%d ", res[i]);
		printf("sum:%d\n", sum);
	}
  return 0;
}
