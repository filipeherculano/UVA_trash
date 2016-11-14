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

int main(){
	int n;
	while(scanf("%d: ", &n) && n){
		bool ok = true;
		vector<int> vi(n);
		map<int,int> mii;
		REP(i,n) cin >> vi[i];
		for(int i = 0; i < n; i++) mii.insert(make_pair(vi[i], i));
		for(int i = 0; i < n-2 && ok; i++){
			for(int j = i+1; j < n-1 && ok; j++){
				int diff = vi[j]-vi[i];
				if(mii.find(diff+vi[j]) != mii.end()) ok = false;
			}
		}
		printf("%s", ok ? "yes\n":"no\n");
	}
  return 0;
}
