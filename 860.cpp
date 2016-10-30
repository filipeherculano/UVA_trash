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
	map<string, double> msi;
	map<string, double>::iterator it;
	while(getline(cin,line) && line != "****END_OF_INPUT****"){
		if(line == "****END_OF_TEXT****"){
			if(msi.empty()) printf("%d %.1lf %.0lf\n",0,0.0,0.0);
			else {
				double lambda = 0.0, sum = 0.0, n = msi.size(), ent, entrel;
				for(it = msi.begin(); it != msi.end(); it++) lambda += it->second;
				for(it = msi.begin(); it != msi.end(); it++) sum += it->second*(log10(lambda) - log10(it->second));
				ent = sum / lambda;
				entrel = ent / (log10(lambda));
				printf("%d %.1lf %.0lf\n", (int)lambda, ent, (entrel*100));
				msi.clear();
			}
		} else {
			string word;
			stringstream ss;
			REP(i, line.size()) {
				if(line[i] == ',' || line[i] == '.' || line[i] == ':' || line[i] == ';' || line[i] == '!' || line[i] == '?' || line[i] == '\"' ||
					line[i] == '\t' || line[i] == '(' || line[i] == ')' || line[i] == ' ' || line[i] == '\n') line[i] = ' ';
				else {
					if(isupper(line[i])) line[i] += ('a'-'A');
				}
			}
			ss << line;
			while(ss >> word){
				it = msi.find(word);
				if(it == msi.end()) msi.insert(make_pair(word, 1.0));
				else it->second++;
			}
		}
	}
  return 0;
}
