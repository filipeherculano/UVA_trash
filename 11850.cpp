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
	while(cin >> n && n){
		int aux;
		bool ok = true;
		vector<int> dist;
		REP(i, n){
			cin >> aux;
			dist.pb(aux);
		}
		if(dist.size() < 8) ok = false;
		else{
			sort(all(dist));
			REP(i, n-1)
				if(dist[i+1]-dist[i] > 200) ok = false;
			if(dist[n-1] < 1322) ok = false;
		}
		printf("%s\n", ok ? "POSSIBLE":"IMPOSSIBLE");
 	}
  return 0;
}
