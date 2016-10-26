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
	cin >> n;
	while(n--){
		int b, sg, sb, aux;
		multiset<int> green, blue;
		cin >> b >> sg >> sb;
		REP(i, sg){
			cin >> aux;
			green.insert(aux);
		}
		REP(i, sb){
			cin >> aux;
			blue.insert(aux);
		}
		while(!green.empty() && !blue.empty()){
			vector<int> reB, reG;
			REP(i, b){
				if(green.empty() || blue.empty()) break;
				int B = *(--blue.end());
				int G = *(--green.end());
				green.erase((--green.end()));
				blue.erase((--blue.end()));
				if(B < G) reG.pb(G-B);
				else if(B > G) reB.pb(B-G);
			}
			REP(i, reB.size()) blue.insert(reB[i]);
			REP(i, reG.size()) green.insert(reG[i]);
		}
		
		if(green.empty() && blue.empty()) printf("green and blue died\n");
		else if(blue.empty()){
			printf("green wins\n");
			for(multiset<int>::reverse_iterator rit = green.rbegin(); rit != green.rend(); rit++)
				cout << *rit << endl;
		} else {
			printf("blue wins\n");
			for(multiset<int>::reverse_iterator rit = blue.rbegin(); rit != blue.rend(); rit++)
				cout << *rit << endl;
		}
		if(n) cout << endl;
	}
  return 0;
}
