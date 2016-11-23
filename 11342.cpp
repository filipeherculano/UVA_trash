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
	scanf("%d", &n);
	map<int, vector<int> > mii;
	map<int, vector<int> >::iterator it;
	for(int a = 0; a <= 224; a++){
		for(int b = a; b <= 224 && ((a*a) + (b*b)) <= 50000; b++){
			for(int c = b; c <= 224 && ((a*a) + (b*b) + (c*c)) <= 50000; c++){
				int sum = (a*a) + (b*b) + (c*c);
				if(sum >= 1 && sum <= 50000){
					if(mii.find(sum) == mii.end()){
						vector<int> temp(3);
						temp[0] = a; temp[1] = b; temp[2] = c;
						mii.insert(make_pair(sum, temp));
					}
				}
			}
		}
	}
	while(n--){
		int k;
		scanf("%d", &k);
		it = mii.find(k);
		if(it == mii.end()) printf("-1\n");
		else printf("%d %d %d\n", (it->second)[0], (it->second)[1], (it->second)[2]);
	}
  return 0;
}























