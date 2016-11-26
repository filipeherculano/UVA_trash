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

vector<int> vi(5);

bool _backtrack(int sum, int idx, int op){
	bool res;
	
	switch(op){
		case 1:
			sum += vi[idx];
			break;
		case 2:
			sum -= vi[idx];
			break;
		case 3:
			sum *= vi[idx];
			break;
	}
	
	if(idx == 4) return (sum == 23);
	else {
		res = _backtrack(sum, idx+1, 1);
		if(!res) res = _backtrack(sum, idx+1, 2);
		if(!res) res = _backtrack(sum, idx+1, 3);
	}
	return res;
}

bool backtrack(){
	bool ok;
	ok = _backtrack(vi[0], 1, 1);
	if(!ok) ok = _backtrack(vi[0], 1, 2);
	if(!ok) ok = _backtrack(vi[0], 1, 3);
	return ok;
}

int main(){
	while(scanf("%d %d %d %d %d", &vi[0],&vi[1],&vi[2],&vi[3],&vi[4])){
		if(vi[0] == 0 && vi[1] == 0 && vi[2] == 0 && vi[3] == 0 && vi[4] == 0)
			return 0;
		bool ok = false;
		sort(all(vi));
		do{
			ok = backtrack();
			if(ok) break;
		} while(next_permutation(all(vi)));
		printf("%s", ok ? "Possible\n" : "Impossible\n");
  }
  return 0;
}








