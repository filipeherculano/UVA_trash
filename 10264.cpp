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
	int n;
	while(cin >> n){
		int pot = pow(2,n), maximum = -1;
		vector<int> v(pot), sum(pot);
		REP(i, pot) cin >> v[i];
		REP(i, pot) sum[i] = 0;
		REP(i, pot){
			REP(j, n){
				int next = i;
				next ^= (1 << j);
				sum[i] += v[next];
			}
		}
		REP(i, pot){
			REP(j, n){
				int next = i;
				next ^= (1 << j);
				maximum = max(maximum, sum[i]+sum[next]);
			}
		}
		cout << maximum << endl;
	}
  return 0;
}
