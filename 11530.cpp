#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int caso = 1, n;
	string line;
	map<char, int> kb;
	kb['a'] = 1; kb['b'] = 2; kb['c'] = 3; 
	kb['d'] = 1; kb['e'] = 2; kb['f'] = 3; 
	kb['g'] = 1; kb['h'] = 2; kb['i'] = 3; 
	kb['j'] = 1; kb['k'] = 2; kb['l'] = 3; 
	kb['m'] = 1; kb['n'] = 2; kb['o'] = 3; 
	kb['p'] = 1; kb['q'] = 2; kb['r'] = 3; kb['s'] = 4;
	kb['t'] = 1; kb['u'] = 2; kb['v'] = 3; 
	kb['w'] = 1; kb['x'] = 2; kb['y'] = 3; kb['z'] = 4;
	kb[' '] = 1;
	scanf("%d%*c", &n);
	while(n--){
		int count = 0;
		getline(cin, line);
		FOR(i, line.size())	count += kb[line[i]];
		printf("Case #%d: %d\n", caso++, count);
	}
  return 0;
}
