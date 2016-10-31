#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

// To fix floating point uncertainty, just multiply everything by 10 and compare the integers.

int main(){
	int p, g, f, s;
	string partie, line;
	map<string, int> msd;
	map<string, int>::iterator it;
	scanf("%d %d%*c", &p, &g);
	REP(i, p){
		cin >> partie;
		scanf("%d.%d", &f, &s);
		msd.insert(make_pair(partie, (f*10)+s));
	}
	scanf("%*c");
	REP(i, g){
		stringstream ss;
		printf("Guess #%d was ", i+1);
		int total = 0, cmp;
		getline(cin, line);
		ss << line;
		while(ss >> partie){
			if(partie == "<" || partie == ">" || partie == "<=" || partie == ">=" || partie == "=") {
				ss >> cmp;
				cmp *= 10;
				if(partie == "<") printf("%s", total < cmp ? "correct.\n":"incorrect.\n");
				else if(partie == ">") printf("%s", total > cmp ? "correct.\n":"incorrect.\n");
				else if(partie == "<=") printf("%s", total <= cmp ? "correct.\n":"incorrect.\n");
				else if(partie == ">=") printf("%s", total >= cmp ? "correct.\n":"incorrect.\n");
				else if(partie == "=") printf("%s", total == cmp ? "correct.\n":"incorrect.\n");
			} else if(partie != "+") {
				it = msd.find(partie);
				if(it != msd.end()) total += it->second;
			}
		}
	}
  return 0;
}
