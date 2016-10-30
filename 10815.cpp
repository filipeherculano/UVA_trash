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
	set<string> s;
	string line;
	while(getline(cin, line)){
		string aux;
		stringstream ss;
		REP(i, line.size()) if((line[i] < 'a' || line[i] > 'z') && (line[i] < 'A' || line[i] > 'Z')) line[i] = ' ';
		ss << line;
		while(ss >> aux){
			REP(i, aux.size()) if(aux[i] >= 'A' && aux[i] <= 'Z') aux[i] += ('a'-'A');
			s.insert(aux);
		}
	}
	for(set<string>::iterator it = s.begin(); it != s.end(); it++) cout << *it << endl;
  return 0;
}
