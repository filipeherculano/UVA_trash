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
	vector<int> A, cres, decres;
	vector< pair<int,int> > st;
	int n;
	int left(int p) {return p << 1;}
	int right(int p) {return (p << 1) + 1;}

	pair<int,int> cmp(pair<int,int> i, pair<int,int> j, int L, int R){
		pair<int,int> temp;
		if(A[i.second] == A[j.second]) {
			temp.first = i.first + j.first;
			temp.second = j.second;
		} else{
			if(i.first == j.second){
			
			} else if(i.first > j.second){
				
			}
		}
		return temp;
	}
	
	void build(int p, int L, int R){
		if(L == R) {
			st[p].first = 1;
			st[p].second = L;
		} else{
			build(left(p), L, (L+R) / 2);
			build(right(p), ((L+R) / 2) + 1, R);
			pair<int,int> p1 = st[left(p)], p2 = st[right(p)];
			st[p] = cmp(p1, p2, L, R); 
		}
	}
/*	
	int rmq(int p, int L, int R, int i, int j){
		if(i > R || j < L) return -1;
		if(i <= L && j >= R) return st[p];

		int p1 = rmq(left(p), L, ((L+R) / 2), i, j);
		int p2 = rmq(right(p), ((L+R) / 2) + 1, R, i, j);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return cmp(left(p), right(p));
	}
*/
public:
	SegmentTree(const vector<int> &_A){
		A = _A;
		n = (int)_A.size();
		st.assign(4*n, 0);
		cres.assign(n, 0);
		decres.assign(n, 0);
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
