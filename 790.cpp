#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b){
	if(get<1>(a) < get<1>(b)) return false;
	else if(get<1>(a) > get<1>(b)) return true;
	else {
		if(get<2>(a) < get<2>(b)) return true;
		else if(get<2>(a) > get<2>(b)) return false;
		else return get<0>(a) < get<0>(b);
	}
}

int main(){
	int n;
	cin >> n;
	scanf("%*c%*c");
	while(n--){
		string line;
		int p[25][7], team, h, m, M = 0;
		char ver, quest;
		REP(i, 25) REP(j, 7) p[i][j] = -1;
		vector< tuple<int, int, int> > vt;
		while(getline(cin, line) && line.size()){
			REP(i, line.size()) if(line[i] == ':') line[i] = ' ';
			stringstream ss;
			ss << line;
			ss >> team >> quest >> h >> m >> ver;
			M = max(M, team);
			int pen = (h*60) + m;
			if(ver == 'Y'){
				if(p[team-1][quest-'A'] < 0){
					if(p[team-1][quest-'A'] == -1) p[team-1][quest-'A'] = pen;
					else p[team-1][quest-'A'] = pen + abs(p[team-1][quest-'A']);
				}
			} else if(ver == 'N'){
				if(p[team-1][quest-'A'] < 0){
					if(p[team-1][quest-'A'] == -1) p[team-1][quest-'A'] = -20;
					else p[team-1][quest-'A'] -= 20;
				}
			}
		}
		REP(i, M){
			int total = 0, qnt = 0;
			REP(j, 7){
				if(p[i][j] > 0){
					total += p[i][j];
					qnt++;
				}
			}
			vt.pb(make_tuple(i+1, qnt, total));
		}
		sort(all(vt), compare);
		printf("RANK TEAM PRO/SOLVED TIME\n");
		int j = 0;
		REP(i, vt.size()){
			if(!i || (get<1>(vt[i]) != get<1>(vt[i-1]) || get<2>(vt[i]) != get<2>(vt[i-1]))) j = i+1;
			cout.width(4); cout << std::right << j;
			cout.width(5); cout << std::right << get<0>(vt[i]);
			if(get<1>(vt[i])) {cout.width(5); cout << std::right << get<1>(vt[i]);}
			if(get<2>(vt[i])) {cout.width(11); cout << std::right << get<2>(vt[i]);}
			cout << endl;
		}
		cout << endl;
	}
  return 0;
}

















