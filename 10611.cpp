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

int n;

int lower(int h, int t, int l, int v[]){
	int b;
	while(h <= t){
		b = (h+t) / 2;
		if(v[b] < l){
			if(b == n-1 || v[b+1] >= l) return v[b];
			else h = b + 1;
		} else t = b - 1;
	}
	return -1;
}

int upper(int h, int t, int l, int v[]){
	int b;
	while(h <= t){
		b = (h+t) / 2;
		if(v[b] > l){
			if(!b || v[b-1] <= l) return v[b];
			else t = b - 1;
		} else h = b + 1;
	}
	return -1;
}

int main(){
	int q;
	scanf("%d", &n);
	int v[n];
	REP(i, n) scanf("%d", &v[i]);
	scanf("%d", &q);
	while(q--){
		int luchu;
		scanf("%d", &luchu);
		int l = lower(0, n-1, luchu, v), u = upper(0, n-1, luchu, v);
		if(l != -1) cout << l;
		else cout << "X";
		printf(" ");
		if(u != -1) cout << u << endl;
		else cout << "X\n";
	}
  return 0;
}
