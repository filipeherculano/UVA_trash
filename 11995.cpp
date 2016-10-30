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
	int n, op, num;
	while(cin >> n){
		int bitmask = 7;
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		for(int i = 0; i < n; i++){
			cin >> op >> num;
			if(op == 1){
				q.push(num);
				s.push(num);
				pq.push(num);
			} else if(op == 2){
				if(!q.empty() && bitmask&1 && q.front() == num) q.pop();
				else bitmask &= ~1;
				if(!s.empty() && bitmask&2 && s.top() == num) s.pop();
				else bitmask &= ~2;
				if(!pq.empty() && bitmask&4 && pq.top() == num) pq.pop();
				else bitmask &= ~4;
			}
		}
		switch(bitmask){
			case 0:
				cout << "impossible" << endl;
				break;
			case 1:
				cout << "queue" << endl;
				break;
			case 2:
				cout << "stack" << endl;
				break;
			case 4:
				cout << "priority queue" << endl;
				break;
			default:
				cout << "not sure" << endl;
				
		}
	}
	return 0;
}
