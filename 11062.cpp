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
	bool isBroken = false;
	string aux, fh;
	set<string> dic;
	string line;
	while(getline(cin, line)){
		stringstream ss;
		REP(i, line.size()) if(((line[i] < 'A' || line[i] > 'Z') && (line[i] < 'a' || line[i] > 'z')) && line[i] != '-') line[i] = ' ';
		REP(i, line.size()) if(line[i] >= 'A' && line[i] <= 'Z') line[i] += ('a' - 'A');
		ss << line;
		while(ss >> aux){
			if(isBroken){
				fh.append(aux);
				aux = fh;
				isBroken = false;
			}
			if(aux.back() != '-') dic.insert(aux);
			else {
				fh = aux;
				fh.pop_back();
				isBroken = true;
			}
		}
	}
	for(set<string>::iterator it = dic.begin(); it != dic.end(); it++)
		cout << *it << endl;	
  return 0;
}
