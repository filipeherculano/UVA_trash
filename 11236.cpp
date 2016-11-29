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

int main(){
	map<int, pair<int,int> > m;
	set< vector<int> > s;
	for(int a = 1; a <= 2000; a++){
		for(int b = a; b <= 2000 && a*b <= 8000000000; b++){
			for(int c = b; c <= 2000 && a*b*c <= 8000000000; c++){
				for(int d = c; d <= 2000 && a*b*c*d <= 8000000000; d++){
					printf("%d %d %d %d\n", a, b, c, d);
				}
			}
		}
	}
	/*for(int c = 1; c <= 300; c++){
		for(int d = c; d <= 300; d++){
			else m.insert(make_pair(c*d, make_pair(c, d)));
		}
	}
	for(int a = 1; a <= 2000; a++){
		for(int b = a; b <= 2000; b++){
			if(m.find(a+b) != m.end()){
				vector<int> temp = {a, b, m[a+b].first, m[a+b].second};
				sort(all(temp));
				s.insert(temp);
			}
		}
	}*/
  return 0;
}
