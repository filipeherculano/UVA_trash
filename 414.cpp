#include <bits/stdc++.h>
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int n;
	string line;
	while(scanf("%d%*c", &n) && n){
		int sum = 0;
		string line;
		vector<int> vi;
		REP(j, n){
			int count = 0;
			getline(cin, line);
			REP(i, 25) 
				if(line[i] == ' ') count++;
			vi.pb(count);
		}
		sort(vi.begin(), vi.end());
		for(int i = vi.size()-1; i >= 0; i--) vi[i] -= vi[0];
		REP(i, vi.size()) sum += vi[i];
		cout << sum << endl; 
	}
  return 0;
}
