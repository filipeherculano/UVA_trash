#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

map<char, int> alphabet;

bool compare(string a, string b){
	bool lower;
	FOR(i, a.size()) {
		if(a[i] != b[i]){
			if(alphabet[a[i]] < alphabet[b[i]]) lower = true;
			else lower = false;
			break;
		}
	}
	return lower;
}

int main(){
	int n, temp = 0;
	string line;
	scanf("%d%*c", &n);
	for(int i = 65; i <= 90; i++){
		alphabet.insert(std::pair<char, int>((char)i, temp));
		temp += 2;
	}
	temp = 1;
	for(int i = 97; i <= 122; i++){
		alphabet.insert(std::pair<char, int>((char)i, temp));
		temp += 2;
	}
	while(n--){
		set<string> ss;
		vector<string> vs;
		cin >> line;
		sort(line.begin(), line.end());
		do{
			ss.insert(line);
		}while(next_permutation(line.begin(), line.end()));
		
		for(set<string>::iterator it = ss.begin(); it != ss.end(); it++)
			vs.push_back(*it);
			
		/*for(int i = 0; i < vs.size()-1; i++){
			for(int j = i+1; j < vs.size(); j++){
				if(compare(vs[i], vs[j]))
					swap(vs[i], vs[j]);
			}
		}*/
		sort(vs.begin(), vs.end(), compare);
		FOR(i, vs.size()) cout << vs[i] << endl;
	}
  return 0;
}
