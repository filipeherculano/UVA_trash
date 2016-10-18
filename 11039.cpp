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
	int t, n;
	cin >> t;
	while(t--){
		int cnt = 1, aux;
		bool curr;
		cin >> n;
		map<int, bool> mib;
		map<int, bool>::reverse_iterator rit;
		REP(i, n) {
			cin >> aux;
			bool pos = aux > 0 ? true:false;
			mib.insert(std::pair<int, bool>(abs(aux), pos));
		}
		for(rit = mib.rbegin(); rit != mib.rend(); rit++){
			if(rit == mib.rbegin()) curr = rit->second;
			else{
				if(curr != rit->second) cnt++;
				curr = rit->second;
			}
		}
		cout << cnt << endl;
	}
  return 0;
}







