#include <bits/stdc++.h>

#define X first
#define Y second
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int t, caso = 1;
	scanf("%d%*c", &t);
	while(t--){
		int n, cnt =0 ;
		scanf("%d%*c", &n);
		string line;
		getline(cin,line);
		int i = 0;
		while(i < line.size()){
			if(line[i] == '.'){
				cnt++;
				i += 3;
			} else i++;
		}
		printf("Case %d: %d\n", caso++, cnt);
	}
	return 0;
}
