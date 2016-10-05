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
	int n, pat = 1;
	while(scanf("%d%*c", &n)){
		bool notFound = true;
		string o[n], r[n];
		REP(i, n) cin >> o[i] >> r[i];
		printf("Pattern %d was ", pat++);
		REP(i, n) REP(j, n) if(o[i][j] != r[i][j]) notFound = false;
		if(!notFound){
			notFound = true;
			
		} printf("preserved.\n");
	}
  return 0;
}
preservation < 90dg < 180dg < 270dg < VR < VR&C90 < VR&C180 < VR&C270
