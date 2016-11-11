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
	int n;
	while(~scanf("%d%*c", &n)){
		int m = 0, aux;
		string line;
		vector< pair<int,int> > coor1, coor3;
		REP(i, n) {
			getline(cin, line);
			REP(j, line.size()) {
				if(line[j]-'0' == 1) coor1.pb(make_pair(i,j));
				else if(line[j]-'0' == 3) coor3.pb(make_pair(i,j)); 
			}
		}
		REP(i, coor1.size()){
			int mi = INF;
			REP(j, coor3.size())
				mi = min(mi, (abs(coor1[i].first-coor3[j].first)+abs(coor1[i].second-coor3[j].second)));
			m = max(m, mi);
		}
		cout << m << endl;
	}
  return 0;
}
