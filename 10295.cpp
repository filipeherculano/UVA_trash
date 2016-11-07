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
	int m, n;
	string name, line;
	unsigned long long value;

	while(scanf("%d %d%*c", &m, &n) != EOF){
		map<string, unsigned long long> mapa;
		map<string, unsigned long long>::iterator it;
		for(int i = 0; i < m; i++){
			cin >> name >> value;
			mapa.insert(std::pair<string, unsigned long long>(name, value));
		}
		for(int i = 0; i < n; i++){
			unsigned long long total = 0;
			while(cin >> line && line[0] != '.'){
				it = mapa.find(line);
				if(it != mapa.end()) total += it->second;
			}
			cout << total << endl;
		}
	}
	return 0;
}
