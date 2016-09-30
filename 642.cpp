#include <bits/stdc++.h>

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i,n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

map<char, int> alphabet;

bool compare(string a, string b){
	bool lower;
	REP(i, a.size()) {
		if(a[i] != b[i]){
			if(alphabet[a[i]] < alphabet[b[i]]) lower = true;
			else lower = false;
			break;
		}
	}
	return lower;
}

int main(){
	int t = 0;
	for(int i = 65; i <= 90; i++){
		alphabet.insert(std::pair<char, int>((char)i, t));
		t += 2;
	}
	t = 1;
	for(int i = 97; i <= 122; i++){
		alphabet.insert(std::pair<char, int>((char)i, t));
		t += 2;
	}
	string line;
  vector<string> ss;
  vector<string> vs;
  while(getline(cin, line) && line.compare("XXXXXX")) ss.pb(line);
  sort(all(ss), compare);
  REP(i, ss.size()){
  	string temp = ss[i];
  	sort(all(temp));
  	vs.pb(temp);
  }
  while(getline(cin, line) && line.compare("XXXXXX")){
  	bool found = false;
  	sort(all(line));
  	REP(i, vs.size()) {
  		if(!line.compare(vs[i])) {
  			cout << ss[i] << endl;
  			found = true;
  		}
  	}
  	if(!found) printf("NOT A VALID WORD\n");
  	cout << "******" << endl;
  }
  return 0;
}
