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
	int q;
	string s;
	getline(cin, s);
	vector<int> letter[52];
	vector<int>::iterator it;
	REP(i, s.size()){
		int idx = s[i] - (isupper(s[i]) ? 'A':('a'-26));
		letter[idx].pb(i);
	}
	scanf("%d%*c", &q);
	REP(i, q){
		int f, s, last = -1;
		bool ok = true;
		string ss;
		getline(cin, ss);
		for(int j = 0; j < ss.size() && ok; j++){
			int idx = ss[j] - (isupper(ss[j]) ? 'A':('a'-26));;
			if(!letter[idx].empty() && last <= letter[idx][letter[idx].size()-1]){
				it = upper_bound(all(letter[idx]), last);
				if(it != letter[idx].end()) {
					last = *it;
					if(j == 0) f = *it;
					if(j == ss.size()-1) s = *it;
				} else ok = false;
			} else ok = false;
		}
		if(ok) printf("Matched %d %d\n", f, s);
		else printf("Not matched\n");
	}
  return 0;
}












