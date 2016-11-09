#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

double cmp(double a, double b){
	return ((a*b)/(a+b));
}

int solve(double x, double k){
	return (k*x)/(x-k);
}

int main(){
	int k;
	while(~scanf("%d", &k)){ 
		double x = 0.0, y;
		vector< pair<int,int> > vii;
		do{
			x += 1.0;
			y = solve(x, (double)k);
			if(y > 0.0 && cmp(x,y) == (double)k) vii.pb(make_pair((int)y, (int)x));
		} while(y != x);
		cout << vii.size() << endl;
		REP(i, vii.size()) printf("1/%d = 1/%d + 1/%d\n", k, vii[i].first, vii[i].second);
	}
  return 0;
}
