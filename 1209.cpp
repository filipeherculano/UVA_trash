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
	string line;
	while(getline(cin, line)){
		string res;
		vector<int> vi;
		int largestmin = 0;
		REP(i, 10) prev_permutation(all(line));
		REP(i, 21){
			int localmin = 30;
			REP(j, line.size()-1) localmin = min(localmin, abs(line[j]-line[j+1]));
			if(largestmin < localmin){
				largestmin = localmin;
				res = line;
			}
			next_permutation(all(line));
		}
		cout << res << largestmin << endl;
	}
  return 0;
}
