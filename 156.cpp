#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line, word;
	vector<string> unique;
	vector<int> vi(26);
	vector< vector<int> > vvi;
	vector<string> vs;
	while(getline(cin, line) && line[0] != '#'){
		stringstream ss;
		ss << line;
		while(ss >> word){
			FOR(i, 26) vi[i] = 0;
			FOR(i, word.size()) {
				if(word[i] >= 'a' && word[i] <= 'z') vi[word[i]-'a']++;
				else if(word[i] >= 'A' && word[i] <= 'Z') vi[word[i]-'A']++;
			}
			vvi.push_back(vi);
			vs.push_back(word);
		}
	}
	for(int i = 0; i < vvi.size(); i++){
		bool hasAnam = false;
		for(int j = 0; j < vvi.size(); j++){
			if(i != j){
				bool ok = true;
				for(int k = 0; k < 26; k++){
					if(vvi[i][k] != vvi[j][k]) ok = false;
				}
				if(ok) hasAnam = true;
			}
		}
		if(!hasAnam) unique.push_back(vs[i]);
	}
	sort(unique.begin(), unique.end());
	for(int i = 0; i < unique.size(); i++)
		cout << unique[i] << endl;
  return 0;
} 
