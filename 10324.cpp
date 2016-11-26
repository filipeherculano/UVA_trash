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
	int caso = 1;
  string line;
  while(getline(cin, line)){
  	int v[line.size()], n;
  	REP(i, line.size()){
  		if(i) v[i] = line[i]-'0'+ v[i-1];
  		else v[i] = line[i]-'0';
  	}
  	scanf("%d", &n);
  	printf("Case %d:\n", caso++);
  	REP(i, n){
  		int a, b, head, tail, value;
  		scanf("%d %d%*c", &a, &b);	
  		head = min(a,b); tail = max(a,b);
  		value = v[tail] - (head ? v[head-1]:0);
  		if(value == abs(a-b)+1 || value == 0) printf("Yes\n");
  		else printf("No\n");
  	}
  }
  return 0;
}
