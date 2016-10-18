#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool compare(tuple<string ,string, string, string, string, string, string, string> a, tuple<string ,string, string, string, string, string, string, string> b){
	return ((get<0>(a)) < (get<0>(b)));
}

int main(){
	int n;
	vector< tuple<string ,string, string, string, string, string, string, string> > teach; 
	scanf("%d%*c", &n);
	while(n--){
		string dep, line;
		getline(cin, dep);
		while(getline(cin, line)){
			if (line.empty()) break;
			string first, home, hp, wp, cb, title, last;
			stringstream ss;
			int count = 0;
			REP(i, line.size()){
				if(line[i] == ',') line[i] = ' ';
				else if(line[i] == ' ') line[i] = '_';
			}
			ss << line;
			ss >> title >> first >> last >> home >> hp >> wp >> cb;
			REP(i, title.size()) if(title[i] == '_') title[i] = ' ';
			REP(i, first.size()) if(first[i] == '_') first[i] = ' ';
			REP(i, last.size()) if(last[i] == '_') last[i] = ' ';
			REP(i, home.size()) if(home[i] == '_') home[i] = ' ';
			REP(i, hp.size()) if(hp[i] == '_') hp[i] = ' ';
			REP(i, wp.size()) if(wp[i] == '_') wp[i] = ' ';
			REP(i, cb.size()) if(cb[i] == '_') cb[i] = ' ';
			teach.pb(make_tuple(last, home, dep, hp, wp, cb, title, first));
		}
	}
	sort(all(teach), compare);
	REP(i, teach.size()){
		printf("----------------------------------------\n");
		cout << get<6>(teach[i]) << " " << get<7>(teach[i]) << " " << get<0>(teach[i]) << endl;
		cout << get<1>(teach[i]) << endl;
		cout << "Department: " << get<2>(teach[i]) << endl;
		cout << "Home Phone: " << get<3>(teach[i]) << endl;
		cout << "Work Phone: " << get<4>(teach[i]) << endl;
		cout << "Campus Box: " << get<5>(teach[i]) << endl;
	}
  return 0;
}








