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
const double EPS = 1e-9;

using namespace std;

int bs(int offset, int head, int tail, int value, vector<int> v){
	int body;
	while(head <= tail){
		body = (head+tail)/2;
		if(v[body] == value){
			if(body == offset || v[body-1] != v[body]) return body;
			else tail = body-1;
		} else if(v[body] > value) tail = body-1;
		else head = body+1;
	}
	return -1;
}

int main(){
	int n;
	while(~scanf("%d", &n)){
		int num, diff = INF, f, s;
		vector<int> v(n);
		REP(i, n) scanf("%d", &v[i]);
		sort(all(v));
		scanf("%d", &num);
		REP(i, n){
			if(num-v[i] > 0){
				int idx = bs(i, i, n-1, num-v[i], v);
				if(idx != -1 && diff > abs(v[i]-v[idx])){
					f = v[i]; s = v[idx];
					diff = abs(v[i]-v[idx]);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", f, s);
	}
  return 0;
}
