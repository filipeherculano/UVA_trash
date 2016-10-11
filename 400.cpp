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
	while(scanf("%d%*c", &t)){
		int M = 0, c;
  	set<string> ss;
  	set<string>::iterator it;
  	string aux;
  	REP(i, t){
  		getline(cin, aux);
  		ss.insert(aux);
  		M = max(M, (int)aux.size());
  	}
  	if(M < 58) c = 60/(M+2);
		else c = 1;
		string mat[t/c][c];
		it = ss.begin();
		REP(i, c) REP(j, t/c) {mat[j][i] = *it; it++;}
		printf("------------------------------------------------------------\n");
		REP(i, t/c) {
			REP(j, c) cout << mat[i][j]; cout << setfill(' ') << setw(M+2-(mat[i][j].size()));
  		cout << endl;
  	}
  }
  return 0;
}
