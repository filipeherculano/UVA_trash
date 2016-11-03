#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

class SegmentTree{
private:
	vector<int> st, A, pot, pos;
	int n;
	int left(int p) {return p << 1;}
	int right(int p) {return (p << 1) + 1;}

	int cmp(int i, int j){
		if(A[pos[i]] == A[pos[j]]) {
			pos[i/2] = pos[j];
			return st[i]+st[j];
		} else{
			if(pot[pos[i]] > pot[pos[j]]){
				pos[i/2] = pos[i];
				return st[i];
			} else{
				pos[i/2] = pos[j];
				return st[j];	
			}
		}
	}
	
	void build(int p, int L, int R){
		if(L == R) {
			st[p] = 1;
			pos[p] = L;
		} else{
			build(left(p), L, (L+R) / 2);
			build(right(p), ((L+R) / 2) + 1, R);
			st[p] = cmp(left(p), right(p)); 
		}
	}
	
	int rmq(int p, int L, int R, int i, int j){
		if(i > R || j < L) return -1;
		if(i <= L && j >= R) return st[p];

		int p1 = rmq(left(p), L, ((L+R) / 2), i, j);
		int p2 = rmq(right(p), ((L+R) / 2) + 1, R, i, j);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return cmp(left(p), right(p));
	}

public:
	SegmentTree(const vector<int> &_A){
		A = _A;
		n = (int)_A.size();
		st.assign(4*n, 0);
		pos.assign(4*n, 0);
		pot.assign(n, 0);
		vector<int> decres(n, 0);
		vector<int> cres(n, 0);
		REP(i, n){
			if(i){
				if(A[i] == A[i-1]) cres[i] = cres[i-1] + 1;
				else cres[i] = 1;
			} else cres[i] = 1;
		}
		for(int i = n-1; i >= 0; i--){
			if(i == n-1) decres[i] = 1;
			else {
				if(A[i] == A[i+1]) decres[i] = decres[i+1] + 1;
				else decres[i] = 1;
			}
		}
		REP(i, n) pot[i] = cres[i] + decres[i];
		build(1, 0, n-1);
	}

	int rmq(int i, int j) {return rmq(1, 0, n-1, i, j);}
};

int main(){
	int n, q, i, j;
	while(cin >> n && n){
		cin >> q;
		vector<int> arr(n);
		REP(z, n) cin >> arr[z];
		SegmentTree st(arr);
		REP(z, q){
			cin >> i >> j;
			printf("%d\n", st.rmq(i-1, j-1));
		}
	}
	return 0;
}
