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

int ca, cb, n;
vector<int> path;
queue<int> bfs;
bool found;

void printPath(vector<int> v){
	REP(i, v.size()) printf("%d ", v[i]);
	cout << endl;
}

void backtrack(int a, int b){
	cout << a << " " << b << endl;
	//	printPath(path);
	if(found) return;
	if(a == n || b == n){
		printPath(path);
		found = true;
		return;
	}

	if(a < ca) bfs.push(1);
	if(b < cb) bfs.push(2);
	if(a){
		bfs.push(3);
		if(b != cb) bfs.push(5);
	}
	if(b){
		bfs.push(4);
		if(a != ca) bfs.push(6);
	}
	
	while(!bfs.empty()){
		int temp = bfs.front();
		bfs.pop();
		switch(temp){
			case 1:
				path.pb(temp);
				backtrack(ca, b);
				path.pop_back();
				break;
			case 2:
				path.pb(temp);
				backtrack(a, cb);
				path.pop_back();
				break;
			case 3:
				path.pb(temp);
				backtrack(0, cb);
				path.pop_back();
				break;
			case 4:
				path.pb(temp);
				backtrack(a, 0);
				path.pop_back();
				break;
			case 5:
				path.pb(temp);
				backtrack((cb-b >= a ? 0:a-(cb-b)), (cb-b >= a ? b+a:cb));
				path.pop_back();
				break;
			case 6:
				path.pb(temp);
				backtrack((ca-a >= b ? a+b:ca), (ca-a >= b ? 0:b-(ca-a)));
				path.pop_back();
				break;
		}
	}
}

int main(){
	while(~scanf("%d %d %d", &ca, &cb, &n)){
		found = false;
		backtrack(0,0);
  }
  return 0;
}



















