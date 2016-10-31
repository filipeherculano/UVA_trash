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
	int n, m, k, v, aux;
	while(cin >> n >> m){
		map<int, vector<int> > index;
		map<int, vector<int> >::iterator it;
		for(int i = 0; i < n; i++){
			cin >> aux;
			it = index.find(aux);
			if(it == index.end()){
				vector<int> v;
				v.push_back(i+1);
				index.insert(std::pair<int, vector<int> >(aux ,v));
			} else it->second.push_back(i+1);
		}
		for(int i = 0; i < m; i++){
			cin >> k >> v;
			it = index.find(v);
			if(it == index.end()) cout << "0\n";
			else{
				if(it->second.size() < k) cout << "0" << endl;
				else cout << it->second[k-1] << endl;
			}
		}
	}
	return 0;
}
