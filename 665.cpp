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
	int m, n, k;
	scanf("%d", &m);
	while(m--){
		if(!isFirst) cout << endl;
		isFirst = false;
		scanf("%d %d%*c", &n, &k);
		int v[n], M = -300;
		REP(i, n) v[i] = -200;
		REP(i, k){
			int aux;
			char c;
			string line;
			stringstream ss;
			vector<int> vi;
			
			getline(cin, line);
			ss << line;
			while(ss >> aux) vi.pb(aux);
			scanf("%c%*c", &c);
			if(c == '<'){
				for(int j = 1; j <= vi[0]; j++) {
					if(v[vi[j]-1]) {
						if(v[vi[j]-1] == -200) v[vi[j]-1] = -1;
						else v[vi[j]-1]--;
					}
				}
				for(int j = vi[0]+1; j < vi.size(); j++) {
					if(v[vi[j]-1]) {
						if(v[vi[j]-1] == -200) v[vi[j]-1] = 1;
						else v[vi[j]-1]++;
					}
				}
			} else if(c == '>'){
				for(int j = 1; j <= vi[0]; j++) {
					if(v[vi[j]-1]) {
						if(v[vi[j]-1] == -200) v[vi[j]-1] = 1;
						else v[vi[j]-1]++;
					}
				}
				for(int j = vi[0]+1; j < vi.size(); j++) {
					if(v[vi[j]-1]) {
						if(v[vi[j]-1] == -200) v[vi[j]-1] = -1;
						else v[vi[j]-1]--;
					}
				}
			} else if(c == '='){
				for(int j = 1; j <= vi[0]; j++) v[vi[j]-1] = 0;
				for(int j = vi[0]+1; j < vi.size(); j++) v[vi[j]-1] = 0;
			}
		}
		int count = 0, index = -1;
		//REP(i, n) cout << v[i] << " ";
		//cout << endl;
		REP(i, n) M = max(M, abs(v[i]));
		REP(i, n) {
			if(M == abs(v[i])) {
				count++;
				if(index == -1) index = i+1;
			}
		}
		if(count == 1) printf("%d\n", index);
		else printf("0\n");
	}
  return 0;
}





