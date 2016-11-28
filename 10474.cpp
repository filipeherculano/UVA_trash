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

int bs(vector<int> v, int num){
	int head = 0, tail = v.size()-1, body;
	while(head <= tail){
		body = (head+tail)/2;
		if(v[body] == num){
			if(body == 0 || v[body-1] != v[body]) return body;
			else tail = body-1;
		} else if(v[body] > num) tail = body-1;
		else head = body+1;
	}
	return -1;
}

int main(){
	int n, q, caso = 1;
	while(scanf("%d %d", &n, &q) && (n || q)){
		int index;
		vector<int> v(n);
		REP(i, n) scanf("%d", &v[i]);
		sort(all(v));
		printf("CASE# %d:\n", caso++);
		REP(i, q){
			int temp;
			scanf("%d", &temp);
			index = bs(v, temp);
			if(index == -1) printf("%d not found\n", temp);
			else printf("%d found at %d\n", temp, index+1);
		}
	}
  return 0;
}
