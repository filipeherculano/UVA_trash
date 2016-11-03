#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

class UnionFind {
private:
	vector<int> p, rank, setSize;
	int numSet;
public:
	UnionFind(int N){
		numSet = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		setSize.assign(N, 1);
		REP(i, N) p[i] = i;
	}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			numSet--;
			if(rank[x] > rank[y]){
				p[y] = p[x];
				setSize[x] += setSize[y];
			} else{
				p[x] = p[y];
				setSize[y] += setSize[x];
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int numDisjointSets() {return numSet;}
	int sizeOfSet(int i) {return setSize[findSet(i)];}
};

class SegmentTree{
private:
	vector<int> st, A;
	int n, maxIndex = 0;
	int left(int p) {return p << 1;}
	int right(int p) {return (p << 1) + 1;}

	int cmp(int i, int j){
		return (A[i] < A[j]) ? i : j;
	}
	
	void build(int p, int L, int R){
		maxIndex = max(maxIndex, p);
		if(L == R) st[p] = L;
		else{
			build(left(p), L, (L+R) / 2);
			build(right(p), ((L+R) / 2) + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = cmp(p1, p2); 
		}
	}
	
	int rmq(int p, int L, int R, int i, int j){
		if(i > R || j < L) return -1;
		if(i <= L && j >= R) {
			return st[p];
		}

		int p1 = rmq(left(p), L, ((L+R) / 2), i, j);
		int p2 = rmq(right(p), ((L+R) / 2) + 1, R, i, j);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return cmp(p1, p2);
	}
	
	void _update(int p){
		if(!p) return;
		
		int p1 = -1, p2 = -1;
		
		if(left(p) <= maxIndex) p1 = st[left(p)];
		if(right(p) <= maxIndex) p2 = st[right(p)];
		
		if(p2 != -1) st[p] = cmp(p1, p2);
		else if(p1 != -1) st[p] = p1;
		
		_update(p/2);
	}

	int findIndex(int p, int L, int R, int i){
		if(i > R || i < L) return -1;
		if(i == L && i == R) return p;

		int p1 = findIndex(left(p), L, ((L+R) / 2), i);
		int p2 = findIndex(right(p), ((L+R) / 2) + 1, R, i);

		if(p1 == -1) return findIndex(right(p), ((L+R) / 2) + 1, R, i);
		if(p2 == -1) return findIndex(left(p), L, ((L+R) / 2), i);
	}

public:
	SegmentTree(const vector<int> &_A){
		A = _A;
		n = (int)_A.size();
		st.assign(4*n, 0);
		build(1, 0, n-1);
	}

	int rmq(int i, int j) {return rmq(1, 0, n-1, i, j);}
	
	void update(int i, int val){
		A[i] = val;
		_update((findIndex(1, 0, n-1, i)/2));		
	}
};

class FenwickTree{

};

int main(){
	int arr[] = {18,17,13,19,15,11,20};
	vector<int> vi(arr, arr+7);
	SegmentTree st(vi);
	printf("%d\n", st.rmq(0, 6));
	st.update(2, 99);
	printf("%d\n", st.rmq(0, 6));
  return 0;
}
