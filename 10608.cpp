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
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, large = 1;
		scanf("%d %d", &n, &m);
		vector<int> p(n), qt(n);
		REP(i, n){
			p[i] = i;
			qt[i] = 1;
		}
		REP(i, m){
			int a, b, rep1, rep2;
			scanf("%d %d", &a, &b);
			if(a > b) swap(a, b);
			a--; b--; rep1 = a; rep2 = b;
			while(p[rep1] != rep1) rep1 = p[rep1];
			while(p[rep2] != rep2) rep2 = p[rep2];
			if(rep1 != rep2){
				p[rep2] = rep1;
				qt[rep1] += qt[rep2];
				large = max(large, qt[rep1]);
			}
		}
		cout << large << endl;
	}
	return 0;
}
