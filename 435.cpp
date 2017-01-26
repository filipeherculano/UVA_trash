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
	int t;
	scanf("%d", &t);
	while(t--){
			int p, sum = 0, aux, win;
			vector<int> party;
			scanf("%d", &p);
			int v[p] = {0};
			REP(i, p) {
				scanf("%d", &aux);
				party.pb(aux);
				sum += aux;
			}
			win = (sum/2) + 1;
			FOR(bitmask, 1, (1 << p)){
				vector<int> idx;
				sum = 0;
				REP(i, p){
					if(bitmask&(1 << i)){
						sum += party[i];
						idx.pb(i);
					}
				}
				if(sum >= win){
					REP(i, idx.size()){
						if(sum-party[idx[i]] < win){
							v[idx[i]]++;
						}
					}
				}
			}
			REP(i, p) printf("party %d has power index %d\n", i+1, v[i]);
			printf("\n");
	}
  return 0;
}









