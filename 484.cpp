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
	map<int, pair<int,int> > miii;
	map<int, pair<int,int> >::iterator it;
	int i = 0, aux;
	string line;
	while(getline(cin, line)){
		stringstream ss;
		ss << line;
		while(ss >> aux){
			it = miii.find(aux);
			if(it == miii.end()) miii.insert(make_pair(aux, make_pair(1, i++)));
			else it->second.first++;
		}
	}
	int v[miii.size()][2];
	for(it = miii.begin(); it != miii.end(); it++){
		v[it->second.second][0] = it->first;
		v[it->second.second][1] = it->second.first;
	}
	REP(j, miii.size()) printf("%d %d\n", v[j][0], v[j][1]);
  return 0;
}
