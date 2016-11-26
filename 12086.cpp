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

vector<int> bit;

int rsq(int b){
	int sum = 0;
	for(; b; b -= LSOne(b)) sum += bit[b];
	return sum;
}

int rsq(int a, int b){
	return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}

void adjust(int k, int v){
	for(; k < (int)bit.size(); k += LSOne(k))
		bit[k] += v;
}

int main(){
	bool isFirst = true;
	int n, aux, caso = 1;
	while(scanf("%d", &n) && n){
		if(!isFirst) cout << endl;
		isFirst = false;
		string line;
		int v[n];
		bit.clear();
		bit.pb(0);
  	REP(i, n) {
  		scanf("%d", &v[i]);
  		bit.pb(0);
  	}
  	scanf("%*c");
  	REP(i, n) adjust(i+1, v[i]);
  	printf("Case %d:\n", caso++);
  	while(getline(cin, line) && line != "END"){
  		int s, e;
  		char op;
  		stringstream ss;
  		ss << line;
  		ss >> op >> s >> e;
  		if(op == 'M') printf("%d\n", rsq(s,e));
  		else if(op == 'S') {
  			adjust(s, -rsq(s,s));
  			adjust(s, e);
  		}
  	}
  }
  return 0;
}
