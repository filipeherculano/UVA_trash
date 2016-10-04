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
	int t, s, caso = 1;
	cin >> t;
	while(t--){
		int v[10001][3], one[2] = {0, 1}, two[2] = {0, 2}, three[2] = {0, 3};
		int index;
		REP(i, 10001) REP(j, 3) v[i][j] = 0;
		REP(j, 3){
			cin >> s;	
			REP(i, s){
				cin >> index;
				v[index][j] = 1; 
			}
		}
		REP(i, 10001){
			if((v[i][0] + v[i][1] + v[i][2]) == 1){
				if(v[i][0]) one[0]++;
				if(v[i][1]) two[0]++;
				if(v[i][2]) three[0]++;
			}
		}
		int M = max(max(one[0], two[0]), three[0]);
		printf("Case #%d:\n", caso++);
		if(one[0] == M){
			printf("%d %d", one[1], M);
			REP(i, 10001)
				if(v[i][0] == 1 && !v[i][1] && !v[i][2])
					printf(" %d", i);
			cout << endl;
		}
		if(two[0] == M){
			printf("%d %d", two[1], M);
			REP(i, 10001)
				if(v[i][1] == 1 && !v[i][0] && !v[i][2])
					printf(" %d", i);
			cout << endl;
		}
		if(three[0] == M){
			printf("%d %d", three[1], M);
			REP(i, 10001)
				if(v[i][2] == 1 && !v[i][1] && !v[i][0])
					printf(" %d", i);
			cout << endl;
		}
	}
  return 0;
}











