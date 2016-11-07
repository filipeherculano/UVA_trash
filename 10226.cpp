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
	int n;
	bool isFirst = true;
	scanf("%d%*c", &n);
	scanf("%*c");
	while(n--){
		if(!isFirst) cout << endl;
		string line;
		int total = 0;
		map<string, int> trees;
		map<string, int>::iterator it;
		while(getline(cin, line) && line.size()){
			it = trees.find(line);
			if(it == trees.end()) trees.insert(std::pair<string, int>(line, 1));
			else it->second++;
			total++;
		}
		if(trees.size()){
			for(it = trees.begin(); it != trees.end(); it++){
				cout << it->first << " ";
				printf("%.4lf\n", ((double)it->second/(double)total) * 100.0);
			}
		}
		isFirst = false;
	}
	return 0;
}
