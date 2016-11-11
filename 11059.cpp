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

using namespace std;

class SegTree{
private:
	vector<ll> st, A;
	int n;
	int left(int p) {return p << 1;}
	int right(int p) {return (p << 1)+1;}
	
	void build(int p, int L, int R){
		if(L == R) st[p] = A[L];
		else {
			build(left(p), L, (L+R)/2);
			build(right(p), 1+((L+R)/2), R);
			ll p1 = st[left(p)], p2 = st[right(p)];
			st[p] = p1*p2;
		}
	}
	
	ll _rq(int p, int L, int R, int i, int j){
		if(i > R || j < L) return 1;
		else if(i <= L && j >= R) return st[p];
		
		ll p1 = _rq(left(p), L, (L+R)/2, i, j);
		ll p2 = _rq(right(p), 1 + (L+R)/2, R, i, j);
		
		if(p1 == 1) return p2;
		if(p2 == 1) return p1;
		return p1*p2;
	} 

public:
	SegTree(const vector<ll> &_A){
		A = _A; n = (int)A.size();
		st.assign(4*n, 0);
		build(1, 0, n-1);
	}
	
	ll rq(int i, int j) {return _rq(1, 0, n-1, i, j);}
	
};


int main(){
	int n, caso = 1;
	while(~scanf("%d", &n)){
		ll m = 0;
		vector<ll> v(n);
		REP(i, n) cin >> v[i];
		SegTree st(v);
		for(int i = 0 ; i < n; i++)
			for(int j = i; j < n; j++)
				m = max(m, st.rq(i,j));
		printf("Case #%d: The maximum product is %lld.\n\n", caso++, m);
	}
  return 0;
}
