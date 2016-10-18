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
	int n, m;
	while(cin >> n >> m && (n || m)){
		bool conflict = false;
		int v[1000000], start, end, rep;
		REP(i, 1000000) v[i] = 0;
		REP(i, n){
			cin >> start >> end;
			if(!conflict){
				for(int j = start; j < end && !conflict; j++) {
					if(v[j]) conflict = true;
					else v[j]++;
				}
			}
		}
		REP(i, m){
			cin >> start >> end >> rep;
			if(!conflict){
				for(int j = start; j < 1000000 && !conflict; j+=rep){
					for(int z = j; z < (j+end-start) && z < 1000000 && !conflict; z++){
						if(v[z]) conflict = true;
						else v[z]++;
					}
				}
			}
		}
		printf("%s\n", conflict ? "CONFLICT":"NO CONFLICT");
	}
  return 0;
}








