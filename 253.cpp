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

using namespace std;

int main(){
	string line;
	int pos[24][6] = 
		{1,2,3,0,0,0,
		 1,4,2,0,0,0,
		 1,5,4,0,0,0,
		 1,3,5,0,0,0,
		 2,3,1,0,0,0,
		 2,4,6,0,0,0,
		 2,1,4,0,0,0,
		 2,6,3,0,0,0,
		 3,1,2,0,0,0,
		 3,5,1,0,0,0,
		 3,6,5,0,0,0,
		 3,2,6,0,0,0,
		 4,2,1,0,0,0,
		 4,1,5,0,0,0,
		 4,5,6,0,0,0,
		 4,6,2,0,0,0,
		 5,4,1,0,0,0,
		 5,1,3,0,0,0,
		 5,3,6,0,0,0,
		 5,6,4,0,0,0,
		 6,2,4,0,0,0,
		 6,3,2,0,0,0,
		 6,4,5,0,0,0,
		 6,5,3,0,0,0};
	REP(i, 24) {
		pos[i][3] = 7-pos[i][2];
		pos[i][4] = 7-pos[i][1];
		pos[i][5] = 7-pos[i][0];
	}
	while(getline(cin, line)){
		bool ok = false;
		string a, b;
		REP(i, line.size()){
			if(i < 6) a.pb(line[i]);
			else b.pb(line[i]);
		}
		for(int i = 0; i < 24 && !ok; i++){
			string temp;
			REP(j, 6) temp.pb(a[pos[i][j]-1]);
			if(!temp.compare(b)) ok = true;
		}
		printf("%s\n", ok ? "TRUE":"FALSE");
	}
  return 0;
}







