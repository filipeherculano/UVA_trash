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
	cin >> t;
	while(t--){
		int n, m, cnt = 0, aux;
		map<int,int> mall;
		map<int,int>::iterator it;
		cin >> n >> m;
		REP(i, n){
			cin >> aux;
			it = mall.find(aux);
			if(it == mall.end()) mall.insert(make_pair(aux, 1));
			else it->second++;
		}
		REP(i, m){
			cin >> aux;
			it = mall.find(aux);
			if(it == mall.end()) mall.insert(make_pair(aux, -1));
			else it->second--;
		}
		for(it = mall.begin(); it != mall.end(); it++) cnt += abs(it->second);
		cout << cnt << endl;
	}
  return 0;
}
