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
	bool isFirst = true;
	int n;
	scanf("%d%*c", &n);
	while(n--){
		if(!isFirst) cout << endl;
		isFirst = false;
		int t;
		string line;
		map<string, int> msi;
		map<string, int>::iterator it;
		scanf("%d%*c", &t);
		REP(j, t){
			string res;
			getline(cin, line);
			if(line.size() < 7) getline(cin, line);
			REP(i, line.size()){
				if(line[i] == 'A' || line[i] == 'B' || line[i] == 'C') res.pb('2');
				else if(line[i] == 'D' || line[i] == 'E' || line[i] == 'F') res.pb('3');
				else if(line[i] == 'G' || line[i] == 'H' || line[i] == 'I') res.pb('4');
				else if(line[i] == 'J' || line[i] == 'K' || line[i] == 'L') res.pb('5');
				else if(line[i] == 'M' || line[i] == 'N' || line[i] == 'O') res.pb('6');
				else if(line[i] == 'P' || line[i] == 'R' || line[i] == 'S') res.pb('7');
				else if(line[i] == 'T' || line[i] == 'U' || line[i] == 'V') res.pb('8');
				else if(line[i] == 'W' || line[i] == 'X' || line[i] == 'Y') res.pb('9');
				else if(line[i] >= '0' && line[i] <= '9') res.pb(line[i]);
			}
			it = msi.find(res);
			if(it == msi.end()) msi.insert(std::pair<string, int>(res, 1)); 
			else it->second++;
		}
		bool ok = false;
		for(it = msi.begin(); it != msi.end(); it++){
			if(it->second > 1){
				ok = true;
				REP(i, it->first.size()){
					printf("%c", it->first[i]);
					if(i == 2) printf("-");
				}
				printf(" %d\n", it->second);
			}
		}
		if(!ok) printf("No duplicates.\n");
	}
  return 0;
}



