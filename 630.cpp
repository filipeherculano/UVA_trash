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
	int t, w;
	scanf("%d", &t);
	while(t--){
		if(!isFirst) cout << endl;
		isFirst = false;
		string aux;
		scanf("%*c");
		cin >> w;
		vector<string> vs, anam;
		REP(i, w){
			cin >> aux;
			vs.pb(aux);
		}
		REP(i, w){
			aux = vs[i];
			sort(all(aux));
			anam.pb(aux);
		}
		while(cin >> aux && aux.compare("END")){
			int temp = 1;
			bool found = false;
			string aux2;
			printf("Anagrams for: ");
			cout << aux << endl;
			aux2 = aux;
			sort(all(aux));
			REP(i, w){
				if(!aux.compare(anam[i])){
					found = true;
					printf("  %d) ", temp++);
					cout << vs[i] << endl;
				}			
			}
			if(!found) {
				printf("No anagrams for: ");
				cout << aux2 << endl;	
			}
		}
	}
  return 0;
}








