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
	while(getline(cin, line) && line[0] != '#'){
		if(next_permutation(all(line))) cout << line << endl;
		else printf("No Successor\n");
	}
  return 0;
}
