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
	while(cin >> n && n){
		bool isA = true;
		int a = 0, b = 0, bit = 0;
		while(n && bit != 32){
			if(n&(1 << bit)){
				if(isA) a |= 1 << bit;
				else b |= 1 << bit;
				isA = !isA;
			}
			bit++;
		}
		cout << a << " " << b << endl;
	}
  return 0;
}
