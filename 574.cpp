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

bool cmp(int i, int j){
	return i >= j;
}

int main(){
	int t, n;
	while(scanf("%d %d", &t, &n) && (t || n)){
		bool found = false;
		int v[n];
		set< vector<int> > perm;
		REP(i, n) scanf("%d", &v[i]);
		for(int bitmask = 1; bitmask < (1 << n); bitmask++){
			int sum = 0;
			vector<int> temp;
			REP(i, n){
				if(bitmask&(1 << i)){
					sum += v[i];
					temp.pb(v[i]);
				}
			}
			if(sum == t){
				found = true;
				sort(all(temp), cmp);
				perm.insert(temp);
			}
		}
		printf("Sums of %d:\n", t);
		if(!found) printf("NONE\n");
		else{
			for(set< vector<int> >::reverse_iterator rit = perm.rbegin(); rit != perm.rend(); rit++){
				vector<int> temp = *rit;
				REP(i, temp.size())	printf("%d%c", temp[i], i == temp.size()-1 ? '\n':'+');
			}
		}
	}
  return 0;
}
