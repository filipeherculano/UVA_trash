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

class SegTree{
public:
	vector<int> A, st, dir, esq;
	int n;
	int left(int x) {return x << 1;}
	int right(int x) {return left(x) + 1;}
	
	void build(int p, int L, int R){
		if(L == R) st[p] = 1;
		else{
			build(left(p), L, (L+R)/2);
			build(right(p), 1 + ((L+R)/2), R);
			
			int p1 = st[left(p)];
			int p2 = st[right(p)];
				
			st[p] = max(p1, p2);

			if(A[(L+R)/2] == A[1 + ((L+R)/2)]){
				int mid = (L+R)/2;
				st[p] = max(st[p], min(mid - L + 1, esq[mid]) + min(R - mid, dir[mid+1]));
			}
		}
	}

	int _rmq(int p, int L, int R, int i, int j){
		if(i > R || j < L) return -1;
		if(L >= i && R <= j) return st[p];

		int p1 = _rmq(left(p), L, (L+R)/2, i, j);
		int p2 = _rmq(right(p), 1+((L+R)/2), R, i, j);	 

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		
		int ans = max(p1, p2);

		if(A[(L+R)/2] == A[1 + ((L+R)/2)]){
			int mid = (L+R)/2;
			ans = max(ans, min(mid - i + 1, esq[mid]) + min(j - mid, dir[mid+1]));
		}
		return ans;
	}

public:
	SegTree(const vector<int> &_A){
		A = _A; n = (int)A.size();
		st.assign(4*n, 0);
		dir.assign(n, 1);
		esq.assign(n, 1);
		for(int i = 1; i < n; i++) if(A[i] == A[i-1]) esq[i] += esq[i-1];
		for(int i = n-1; i >= 0; i--) if(A[i] == A[i+1]) dir[i] += dir[i+1];
		build(1, 0, n-1);
	}

	int rmq(int i, int j){
		return _rmq(1, 0, n-1, i, j);
	}
};

int main(){
	int n, m;
	while(scanf("%d", &n) && n){
		scanf("%d", &m);
		vector<int> A(n);
		REP(i, n) cin >> A[i];
		SegTree st(A);
		REP(z, m){
			int i, j;
			scanf("%d %d", &i, &j);
			cout << st.rmq(i-1, j-1) << endl;
		}
	}
  return 0;
}


















