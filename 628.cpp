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

using namespace std;

vector<string> dic;

void backtrack(string rule, int i){
	if(rule.size() == i) {
		cout << rule << endl;
		return;
	}
	
	if(rule[i] == '0'){
		REP(j, 10) {
			rule[i] = '0'+j;
			backtrack(rule, i+1);
		}
	} else if(rule[i] == '#'){
		REP(z, dic.size()){
			string temp;
			REP(j, i) temp.pb(rule[j]);
			temp.append(dic[z]);
			FOR(j, i+1, rule.size()) temp.pb(rule[j]);
			backtrack(temp, i+dic[z].size());
		}
	}
}

int main(){
	int t, r;
	while(~scanf("%d%*c", &t)){
		vector<string> rules;
		string line;
		dic.clear();
		REP(i, t){
			getline(cin, line);
			dic.pb(line);
		}
		scanf("%d%*c", &r);
		REP(i, r){
			getline(cin, line);
			rules.pb(line);
		}
		printf("--\n");
		REP(i, rules.size()){
			backtrack(rules[i], 0);
		}
	}
  return 0;
}
