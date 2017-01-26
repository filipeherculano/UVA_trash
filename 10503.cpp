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

int n, m;
vector< pair<int,int> > pieces;
vector<int> used;
pair<int,int> a, b;

bool _backtrack(int l, int remain){
	REP(i, pieces.size()){
		if(!used[i]){
			if(remain == 1){
				if((l == pieces[i].first && pieces[i].second == b.first) ||
					(l == pieces[i].second && pieces[i].first == b.first))
					return true;	
			} else {
				if(l == pieces[i].first){
					used[i] = 1;
					if(_backtrack(pieces[i].second, remain-1)) return true;
					used[i] = 0;
				} else if(l == pieces[i].second){
					used[i] = 1;
					if(_backtrack(pieces[i].first, remain-1)) return true;
					used[i] = 0;
				}
			}
		}
	}
	return false;
}

int main(){
	while(scanf("%d", &n) && n){
		scanf("%d", &m);
		scanf("%d %d", &a.first, &a.second);
		scanf("%d %d", &b.first, &b.second);
		pieces.clear(); used.clear();
		REP(i, m){
			pair<int,int> temp;
			scanf("%d %d", &temp.first, &temp.second);
			pieces.pb(temp);
			used.pb(0);
		}
		printf("%s", _backtrack(a.second, n) ? "YES\n":"NO\n");
	}
  return 0;
}
