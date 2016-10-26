#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
	if(a.second != b.second) return a.second > b.second;
	else return lexicographical_compare(all(a.first), all(b.first));
}

int main(){
	string line, source;
	set<string>::iterator jit;
	map<string, set<string> > Map;
	map<string, set<string> > student;
	map<string, set<string> >::iterator it, zit;
	vector< pair<string, int> > vm;
	while(getline(cin,line) && line[0] != '0'){
		if(line[0] == '1'){
			for(it = Map.begin(); it != Map.end(); it++) {
				int cnt = 0;
				for(jit = it->second.begin(); jit != it->second.end(); jit++) if(student[*jit].size() == 1) cnt++;
				vm.pb(make_pair(it->first, cnt));
			}
			sort(all(vm), compare);
			REP(i, vm.size()) cout << vm[i].first << " " << vm[i].second << endl;
			Map.clear();
			student.clear();
			vm.clear();
		} else{
			if(isupper(line[0])) {
				source = line;
				Map.insert(make_pair(source, std::set<string>()));
			} else {
				it = Map.find(source);
				it->second.insert(line);
				zit = student.find(line);
				if(zit == student.end()) {
					set<string> ss;
					ss.insert(source);
					student.insert(make_pair(line, ss));
				} else zit->second.insert(source);
			}
		}
	}
  return 0;
}
