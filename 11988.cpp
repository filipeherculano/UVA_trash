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
	while(cin >> line){
		bool isFront = false;
		list<char> lc;
		list<char>::iterator it = lc.begin();
		REP(i, line.size()){
			if(line[i] == '[') it = lc.begin();
			else if(line[i] == ']') it = lc.end();
			else {
				it = lc.insert(it, line[i]);
				it++;
			}
		}
		for(list<char>::iterator it = lc.begin(); it != lc.end(); it++)
			cout << *it;
		cout << endl;
	}
  return 0;
}
