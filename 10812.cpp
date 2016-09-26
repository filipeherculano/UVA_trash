#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	llu n, sum, diff;
	cin >> n;
	while(n--){
		cin >> sum >> diff;
		if(diff > sum || (sum - diff)&1) cout << "impossible\n";
		else{
			llu a = diff, b = 0;
			llu offset = (sum - diff)/2;
			a += offset;
			b += offset;
			printf("%llu %llu\n", a, b);
		}
	}
  return 0;
}
