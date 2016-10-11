#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
	if(get<1>(a) > get<1>(b)) return true;
	else if(get<1>(a) < get<1>(b)) return false;
	else{
		if(get<2>(a) > get<2>(b)) return false;
		else if(get<2>(a) < get<2>(b)) return true;
		else return get<0>(a) < get<0>(b);
	}
}

int main(){
	bool isFirst = true;
	int t;
	scanf("%d%*c", &t);
	while(t--){
		string line;
		set<int> id;
		int mat[100][9];
		REP(i, 100) REP(j, 9) mat[i][j] = -1;
		vector< tuple<int,int,int> > vt;
		while(getline(cin, line) && line.size() > 1){
			stringstream ss;
			ss << line;
			int c, q, t;
			char ver;
			ss >> c >> q >> t >> ver;
			c--; q--;
			id.insert(c);
			if(ver == 'I'){
				if(mat[c][q] <= 0){
					if(mat[c][q] == -1) mat[c][q] = -20;
					else if(mat[c][q] <= 0) mat[c][q] -= 20;
				}
			} else if(ver == 'C'){
				if(mat[c][q] == -1) mat[c][q] = t;
				else if(mat[c][q] <= 0) mat[c][q] = abs(mat[c][q]) + t;
			} else if(mat[c][q] == -1) mat[c][q] = 0;
		}
		for(set<int>::iterator it = id.begin(); it != id.end(); it++){
			int sum = 0, qt = 0;
			REP(i, 9){
				if(mat[*it][i] > 0) {
					qt++;
					sum += mat[*it][i];
				}
			}
			vt.pb(make_tuple(*it, qt, sum));
		}
		if(!vt.size()) t++;
		else{
			if(!isFirst) cout << endl;
			isFirst = false;
		}
		sort(all(vt), compare);
		REP(i, vt.size()) printf("%d %d %d\n", get<0>(vt[i])+1, get<1>(vt[i]), get<2>(vt[i]));
	}
  return 0;
}







