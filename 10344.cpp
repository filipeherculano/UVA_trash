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

bool _backtrack(deque<int> qi, int op){
	bool res;
	
	int a = qi.front(); qi.pop_front();
	int b = qi.front(); qi.pop_front();
	
	switch(op){
		case 1:
			qi.push_front(a+b);
			break;
		case 2:
			qi.push_front(a-b);
			break;
		case 3:
			qi.push_front(a*b);
			break;
	}
	
	if(qi.size() == 1){
		printf("%d\n", qi.front());
		if(qi.front() == 23) res = true;
		else res = false;
	} else{
		res = _backtrack(qi, 1);
		if(!res) res = _backtrack(qi, 2);
		if(!res) res = _backtrack(qi, 3);
	}
	return res;
}

bool backtrack(deque<int> qi){
	bool ok;
	ok = _backtrack(qi, 1);
	if(!ok) ok = _backtrack(qi, 2);
	if(!ok) ok = _backtrack(qi, 3);
	return ok;
}

int main(){
	do{
		int aux;
		deque<int> qi;
		REP(i, 5)	{
			scanf("%d", &aux);
			qi.pb(aux);
		}
		if(!aux) break;
		printf("%s", backtrack(qi) ? "Possible\n" : "Impossible\n");
  } while(1);
  return 0;
}
