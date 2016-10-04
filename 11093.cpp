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
	int t, caso = 1;
	scanf("%d", &t);
	while(t--){
		int g, curr = 0;
		scanf("%d", &g);
		int p[g], q[g], sum = 0;
		REP(i, g) scanf("%d", &p[i]);
		REP(i, g) scanf("%d", &q[i]);
		REP(i, g) sum += (p[i] - q[i]);
		if(sum >= 0){
			int index;
			REP(i, g){
				int curr = 0;
				bool first = true, found = true;
				for(int j = i; found; j = (j+1)%g){
					if(!first && j == i){
						index = i;
						break;
					}
					curr += p[j];
					if(curr < q[j]) found = false; 
					curr -= q[j];
					first = false;
				}
				if(found) break;
			}
			printf("Case %d: Possible from station %d\n", caso++, index+1);
		} else printf("Case %d: Not possible\n", caso++);
	}
  return 0;
}
