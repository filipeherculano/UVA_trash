#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	string line, word;
	while(getline(cin, line)){
		stringstream ss;
		ss << line;
		vector<int> w;
		int n = 0, c = INF;
		bool found = false;
		
		while(ss >> word){
			int sum = 0;
			n++;
			REP(i, word.size()) sum = (sum << 5) + (word[i]-'a'+1);
			w.pb(sum);
		}
		
		REP(i, w.size()) c = min(c, w[i]);
		
		while(!found){
			found = true;
			for(int i = 0; i < n && found; i++){
				for(int j = i+1; j < n && found; j++){
					if((c/w[i])%n == (c/w[j])%n){
						c = min((c/w[i]+1)*w[i], (c/w[j]+1)*w[j]);
						found = false;
					}
				}
			}
		}
		cout << line << endl;
		printf("%d\n\n", c);
	}
  return 0;
}








