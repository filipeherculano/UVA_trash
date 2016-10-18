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
	int r, c, n, caso = 1;
	while(cin >> r >> c >> n && (r || c || n)){
		int x, y, count = 0;
		vector< pair<int,int> > vii;
		vector< pair<int,int> > escape;
		vector< pair<int,int> >::iterator esc, it;
		REP(i, n){
			cin >> x >> y;
			vii.pb(std::pair<int,int>(x,y));
		}
		cin >> x >> y;
		escape.pb(std::pair<int,int>(x,y));
		if(x) escape.pb(std::pair<int,int>(x-1,y));
		if(x < r-1) escape.pb(std::pair<int,int>(x+1,y));
		if(y) escape.pb(std::pair<int,int>(x,y-1));
		if(y < c-1) escape.pb(std::pair<int,int>(x,y+1));
		for(esc = escape.begin(); esc != escape.end(); esc++){
			for(it = vii.begin(); it != vii.end(); it++){
				if(it->first == esc->first || it->second == esc->second){
					count++;
					break;
				}
			}
		}
		if(escape.size() != count) printf("Case %d: Escaped again! More 2D grid problems!\n", caso++);
		else printf("Case %d: Party time! Let's find a restaurant!\n", caso++);
	}
  return 0;
}
