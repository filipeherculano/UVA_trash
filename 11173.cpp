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
	int N, n, k, pat[4] = {0,1,1,0};
	cin >> N;
	while(N--){
		int res = 0;
		cin >> n >> k;
		REP(bit, n) res |= (pat[(k/(int)(pow(2,bit))) % 4] << bit);
		cout << res << endl;
	}
  return 0;
}
