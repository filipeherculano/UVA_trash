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
	int t, n, m;
	cin >> t;
	while(t--){
		int cnt = 0, ind;
		cin >> n >> m;
		vector<int> vi(pow(2,n), 1);
		REP(i, m){
			cin >> ind;
			ind--;
			vi[ind] = 0;
		}
		ind = 0;
		while(ind+1 != vi.size()){
			if(vi[ind] ^ vi[ind+1]) cnt++;
			vi.pb((vi[ind] | vi[ind+1]));
			ind += 2;
		}
		cout << cnt << endl;
	}
  return 0;
}
