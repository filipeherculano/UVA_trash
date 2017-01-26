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
const double EPS = 1e-9;

using namespace std;


bool cmp(tuple<string,int,int> i, tuple<string,int,int> j){
	if(get<1>(i) == get<1>(j)){
		if(get<2>(i) == get<2>(j)) return lexicographical_compare(all(get<0>(i)), all(get<0>(j)));
		else return get<2>(i) < get<2>(j);
	} return get<1>(i) > get<1>(j);
}

int main(){
	int t, caso = 1;
	scanf("%d%*c", &t);
	while(t--){
		vector< tuple<string, int, int> > team(10);
		int atk, def;
		string line;
		REP(i, 10){
			cin >> line >> atk >> def;
			team[i] = make_tuple(line, atk, def);
		}
		sort(all(team), cmp);
		printf("Case %d:\n", caso++);
		vector<string> names;
		REP(i, 10) names.pb(get<0>(team[i]));
		sort(names.begin(), names.begin()+5);
		sort(names.begin()+5, names.end());
		REP(i, 10){
			if(!i || i == 5) printf("(");
			else printf(", ");
			cout << names[i];
			if(i == 4 || i == 9) printf(")\n");
		}
	}
  return 0;
}
