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
	int c;
	cin >> c;
	while(c--){
		int n, t, m, time, side = 1, curr = 0;
		string pos;
		cin >> n >> t >> m;
		queue< pair<int,int> > left, right;
		vector<int> vp(m);
		int total = m;
		REP(i, m){
			cin >> time >> pos;
			if(!pos.compare("left")) left.push(make_pair(time, i));
			else if(!pos.compare("right")) right.push(make_pair(time, i));
		}
		while(!left.empty() || !right.empty()){
			if(!left.empty() && !right.empty()){
				if(right.front().first > curr && left.front().first > curr) curr = min(left.front().first, right.front().first);
			} else if(!left.empty()){
				if(left.front().first > curr) curr = left.front().first;
			} else if(!right.empty()){
				if(right.front().first > curr) curr = right.front().first;
			}
			int max = n;
			if(side){ // left side
				while(!left.empty() && left.front().first <= curr && max){
					vp[left.front().second] = curr+t;
					left.pop();
					max--;
				}
				side = 0;
				curr += t;
			} else{
				while(!right.empty() && right.front().first <= curr && max){
					vp[right.front().second] = curr+t;
					right.pop();
					max--;
				}
				side = 1;
				curr += t;
			}
		}
		REP(i, vp.size()) cout << vp[i] << endl;
		if(c) cout << endl;
	}
  return 0;
}







