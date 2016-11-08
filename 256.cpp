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
	int n;
	vector< vector<string> > vvs(4);
	vvs[0] = {"00","01","81"};
	vvs[1] = {"0000","0001", "2025","3025", "9801"};
	vvs[2] = {"000000","000001","088209", "494209", "998001"};
	vvs[3] = {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729", "99980001"};
	while(~scanf("%d", &n)){
		REP(i, vvs[(n/2)-1].size()) cout << vvs[(n/2)-1][i] << endl;
	}
  return 0;
}
