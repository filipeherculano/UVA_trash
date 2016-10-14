#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

/*
	For this problem, we can easly define the best location
	by just getting the median of the columns and rows. This
	is because since we need to move horizontaly and verticaly,
	we can simply find the best column and row to move that is
	going to cost less moves for everybody, hence the median.
*/

int main(){
	int t;
	cin >> t;
	while(t--){
		int s, a, f, r, c;
		vector<int> row, col;
		cin >> s >> a >> f;
		REP(i, f){
			cin >> r >> c;
			row.pb(r);
			col.pb(c);
		}
		sort(all(row));
		sort(all(col));
		if(f&1) {
			r = row[f/2];
			c = col[f/2];
		} else {
			r = row[(f/2)-1];
			c = col[(f/2)-1];
		}
		printf("(Street: %d, Avenue: %d)\n", r, c);
	}
  return 0;
}









