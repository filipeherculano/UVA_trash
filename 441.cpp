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
	int k;
	bool isfirst = true;
	while(cin >> k && k){
		if(!isfirst) cout << endl;
		isfirst = false;
		int v[k];
		REP(i, k) cin >> v[i];
		for(int a = 0; a < k-5; a++)
			for(int b = a+1; b < k-4; b++)
				for(int c = b+1; c < k-3; c++)
					for(int d = c+1; d < k-2; d++)
						for(int e = d+1; e < k-1; e++)
							for(int f = e+1; f < k; f++)
								printf("%d %d %d %d %d %d\n", v[a],v[b],v[c],v[d],v[e],v[f]);
	}
  return 0;
}
