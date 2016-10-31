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
	int k, caso = 1;
	cin >> k;
	while(k--){
		int n, aux, qt;
		double total = 0.0;
		map<int,int> global;
		map<int,int>::iterator mit;
		map<int, set<int> > mii;
		map<int, set<int> >::iterator it;
		cin >> n;
		REP(i, n){
			cin >> qt;
			set<int> m;
			REP(i, qt) {
				cin >> aux;
				m.insert(aux);
			}
			for(set<int>::iterator sit = m.begin(); sit != m.end(); sit++) {
				mit = global.find(*sit);
				if(mit == global.end()) global.insert(make_pair(*sit, 1));
				else mit->second++;
			}
			mii.insert(make_pair(i, m));
		}
		for(mit = global.begin(); mit != global.end(); mit++)
			if(mit->second == 1) total += 1.0;
				
		printf("Case %d:", caso++);
		for(it = mii.begin(); it != mii.end(); it++){
			double subtotal = 0.0;
			for(set<int>::iterator sit = it->second.begin(); sit != it->second.end(); sit++) 
				if(global[*sit] == 1)
					subtotal += 1.0/(double)total;
			printf(" %lf%%", subtotal*100.0);
		}
		cout << endl;
	}
  return 0;
}
