#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

// Just reverse the order of the 8-bit bytes.

int main(){
	int num;
	while(cin >> num){
		int res = 0, bytes[4] = {0};
		REP(i, 4) bytes[3-i] |= (num >> (i*8))&255;
		REP(i,4) res |= (bytes[i] << (i*8));
		printf("%d converts to %d\n", num, res);
	}
  return 0;
}
