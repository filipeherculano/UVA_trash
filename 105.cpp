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
	vector<int> vi(10002, 0);
	int l, h, r, end = 0;
	while(~scanf("%d %d %d", &l, &h, &r)){
		for(int i = l; i < r; i++) if(vi[i] < h) vi[i] = h;
		end = max(end, r);
	}
	for(int i = 0; i <= end; i++)
		if(i && vi[i] != vi[i-1])
			printf("%d %d%c", i, vi[i], i == end ? '\n':' ');
  return 0;
}
