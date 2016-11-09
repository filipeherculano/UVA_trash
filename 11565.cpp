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
	int n;
	cin >> n;
	while(n--){
		bool found = false;
		int a, b, c;
		cin >> a >> b >> c;
		for(int x = -100; x <= 100 && !found; x++){
			for(int y = -100; y <= 100 && !found; y++){
				for(int z = -100; z <= 100 && !found; z++){
					if((x + y + z) == a && x*y*z == b && ((x*x)+(y*y)+(z*z)) == c
						&& x != y && x != z && y != z){
						printf("%d %d %d\n", x, y, z);
						found = true;
					}
				}
			}
		}
		if(!found) printf("No solution.\n");
	}
  return 0;
}
