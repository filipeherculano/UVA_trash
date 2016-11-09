#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;



int main(){	
	int t;
	scanf("%d", &t);
	while(t--){
		int n, p;
		scanf("%d %d", &n, &p);
		int v[p];
		bool found = false;
		REP(i, p) scanf("%d", &v[i]);
		for(int bitmask = 0; bitmask < (1 << p) && !found; bitmask++){
			int sum = 0;
			for(int i = bitmask; i; i -= i & (-i))
				sum += v[(int)log2((double)(i & (-i)))];
			if(sum == n) found = true;
		}
		printf("%s", found ? "YES\n":"NO\n");
	}
  return 0;
}
