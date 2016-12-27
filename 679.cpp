#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

using namespace std;

int left(int x){
	return (x << 1);
}

int right(int x){
	return left(x) + 1;
}

int find(int n, int i, int lvl){
	if(lvl == 0) return i;
	
	if(n&1) return find((n+1)/2, left(i), lvl-1);
	else return find(n/2, right(i), lvl-1);
}

int main(){
	int l;
	scanf("%d", &l);
	while(l--){
		int d, i, aux, lvl;
		cin >> d;
		if(d == -1) return 0;
		cin >> i;
		lvl = d-1; aux = i;
		while(aux > (1 << lvl)){
			aux -= (1 << lvl);
			lvl--;
		}
		cout << find(i, 1, lvl) << endl;
	}
  return 0;
}
