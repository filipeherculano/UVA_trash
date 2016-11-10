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
	int t, caso = 1;
	scanf("%d", &t);
	while(t--){
		string line;
		int n, k, cnt = 0;
		deque<char> dq;
		cin >> n >> k >> line;
		REP(i, line.size()){
			if(dq.size() > k) dq.pop_back();
			REP(j, dq.size()) {
				if(dq[j] == line[i]){
					cnt++;
					break;
				}
			}
			dq.push_front(line[i]);
		}
		printf("Case %d: %d\n", caso++, cnt);
	}
  return 0;
}
