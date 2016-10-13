#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool compare(tuple<int, int> a, tuple<int, int> b){
	if(get<1>(a) < get<1>(b)) return true;
	else if(get<1>(a) > get<1>(b)) return false;
	else{
		if(((get<0>(a))&1) && !((get<0>(b))&1)) return true;
		else if(!((get<0>(a))&1) && ((get<0>(b))&1)) return false;
		else if(((get<0>(a))&1) && ((get<0>(b))&1)) return (get<0>(a) > get<0>(b));
		else return (get<0>(a) < get<0>(b));
	}
}

int main(){
	int n, m;
	while(cin >> n >> m && (n || m)){
		int aux;
		vector< tuple<int, int> > vt;
		REP(i, n) {
			cin >> aux;
			vt.pb(make_tuple(aux, aux % m));
		}
		sort(all(vt), compare);
		printf("%d %d\n", n, m);
		REP(i, vt.size()) cout << get<0>(vt[i]) << endl;
	}
	printf("%d %d\n", n, m);
  return 0;
}
