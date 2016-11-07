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
	int t;
	cin >> t;
	while(t--){
		string line;
		int l, m, aux, cnt = 0, side = 1;
		queue<int> left, right;
		cin >> l >> m;
		l *= 100;
		scanf("%*c");
		REP(i, m){
			cin >> aux >> line;
			if(!line.compare("right")) right.push(aux);
			else if(!line.compare("left")) left.push(aux);
		}
		while(!left.empty() || !right.empty()){
			int size = l;
			if(side){
				while(!left.empty() && left.front() <= size){
					size -= left.front();
					left.pop();
				}
				side = (++side)%2;
				cnt++;
			} else {
				while(!right.empty() && right.front() <= size){
					size -= right.front();
					right.pop();
				}
				side = (++side)%2;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
  return 0;
}







