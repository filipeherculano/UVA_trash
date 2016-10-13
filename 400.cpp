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
	while(scanf("%d%*c", &t) != EOF){
		int M = 0, c, z = 0;
  	vector<string> vs;
  	string aux;
  	REP(i, t){
  		getline(cin, aux);
  		vs.pb(aux);
  		M = max(M, (int)aux.size());
  	}
  	sort(all(vs));
  	c = 60/(M+2);
  	if((60 % (M+2)) >= M) c++;
		string mat[(t+c-1)/c][c];
		REP(i, c) REP(j, (t+c-1)/c) if(z < vs.size()) mat[j][i] = vs[z++];
		printf("------------------------------------------------------------\n");
		REP(i, (t+c-1)/c) {
			REP(j, c) {
				if(mat[i][j].size()){
					cout.width(M);
					if(j) printf("  ");
					cout << std::left << mat[i][j];
				}
			}
  		cout << endl;
  	}
  }
  return 0;
}
