#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define pf push_front

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main(){
	int t, n, m;
	cin >> t;
	while(t--){
		int aux, ptr = 0;
		deque< pair<int,bool> > di;
		vector<int> vi;
		cin >> n >> m;
		REP(i, n) {
			cin >> aux;
			di.pb(std::pair<int,bool>(aux, (i == m ? true:false)));
			vi.pb(aux);
		}
		sort(all(vi), compare);
		while(di.front().first != vi[ptr] || !di.front().second){
			if(di.front().first == vi[ptr]) {
				di.pop_front();
				ptr++;
			} else {
				di.pb(di.front());
				di.pop_front();
			}
		}
		cout << ptr+1 << endl;
	}
  return 0;
}
