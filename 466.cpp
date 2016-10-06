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
	while(scanf("%d%*c", &n) != EOF){
		bool notFound = true;
		string o[n], r[n];
		REP(i, n) cin >> o[i] >> r[i];
		printf("Pattern %d was ", pat++);
		REP(i, n) REP(j, n) if(o[i][j] != r[i][j]) notFound = false;
		if(!notFound){
			notFound = true;
			REP(i, n) REP(j, n) if(o[n-1-j][i] != r[i][j]) notFound = false;
			if(!notFound){
				notFound = true;
				REP(i, n) REP(j, n) if(o[n-1-i][n-1-j] != r[i][j]) notFound = false;
				if(!notFound){
					notFound = true;
					REP(i, n) REP(j, n) if(o[j][n-1-i] != r[i][j]) notFound = false;
					if(!notFound){
						notFound = true;
						REP(i, n/2) swap(o[i], o[n-1-i]);
						REP(i, n) REP(j, n) if(o[i][j] != r[i][j]) notFound = false;
						if(!notFound){
							notFound = true;
							REP(i, n) REP(j, n) if(o[n-1-j][i] != r[i][j]) notFound = false;
							if(!notFound){
								notFound = true;
								REP(i, n) REP(j, n) if(o[n-1-i][n-1-j] != r[i][j]) notFound = false;
								if(!notFound){
									notFound = true;
									REP(i, n) REP(j, n) if(o[j][n-1-i] != r[i][j]) notFound = false;
									if(!notFound) printf("improperly transformed.\n");
									else printf("reflected vertically and rotated 270 degrees.\n");
								} else printf("reflected vertically and rotated 180 degrees.\n");
							} else printf("reflected vertically and rotated 90 degrees.\n");
						} else printf("reflected vertically.\n");
					} else printf("rotated 270 degrees.\n");
				} else printf("rotated 180 degrees.\n");
			} else printf("rotated 90 degrees.\n");
		} else printf("preserved.\n");
	}
  return 0;
}






