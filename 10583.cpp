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
	int n, m, caso = 1;
	while(scanf("%d %d", &n, &m) && (n || m)){
		int reg[n], cnt = 0;
		REP(i, n) reg[i] = i;
		REP(i, m){
			int a, b, repA, repB;
			scanf("%d", &a);
			scanf("%d", &b);
			if(a > b) swap(a, b);
			a--; b--; repA = a; repB = b;
			while(reg[repA] != repA) repA = reg[repA];
			while(reg[repB] != repB) repB = reg[repB];
			if(repA != repB) {
				reg[repB] = repA;
				cnt++;
			}
		}
		printf("Case %d: ", caso++);
		cout << n-cnt << endl;
	}
  return 0;
}

