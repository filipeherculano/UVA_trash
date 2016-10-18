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
	while(scanf("%d%*c", &n) && n){
		int last = -1;
		string card, move;
		vector<string> vs(n);
		REP(i, n) vs[i] = "yep";
		REP(i, n){
			cin >> card >> move;
			int size = move.size();
			while(size){
				if(last == -1){
					last++;
					size--;
				} else{
					last = (last+1) % n;
					if(!vs[last].compare("yep")) size--;
				}
			}
			vs[last] = card;
		}
		REP(i, n) {
			cout << vs[i];
			printf("%c", i == n-1 ? '\n':' ');
		}
	}
  return 0;
}
