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
	int t;
	scanf("%d", &t);
	while(t--){
		int n, low, high, q, price;
		string name;
		map<string, pair<int,int> > msii;
		map<string, pair<int,int> >::iterator it;
		scanf("%d%*c", &n);
		REP(i,n){
			cin >> name >> low >> high;
			msii.insert(make_pair(name, make_pair(low,high)));
		}
		scanf("%d", &q);
		REP(i,q){
			string res = "UNDETERMINED";
			scanf("%d", &price);
			for(it = msii.begin(); it != msii.end(); it++){
				if(price >= it->second.first && price <= it->second.second){
					if(res == "UNDETERMINED") res = it->first;
					else {
						res = "UNDETERMINED";
						break;
					}
				}
			}
			cout << res << endl;
		}
		if(t) cout << endl;
	}
  return 0;
}


