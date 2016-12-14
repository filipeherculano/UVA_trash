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

int main(){
  int caso = 1;
  ll p, c;
  while(scanf("%lld %lld%*c", &p, &c) && (p || c)){
    char car;
    ll num;
    bool passed = false;
    deque<ll> rmv, q;
		deque<ll>::iterator it;
		for(ll i = 1; i <= min(p,c); i++) q.pb(i);
    
		printf("Case %d:\n", caso++);
    	
		REP(i, c){
      cin >> car;
			if(car == 'N'){
				if(passed) {
					cout << rmv.front() << endl;
					rmv.pb(rmv.front());
					rmv.pop_front();
				} else {
					while(1){
						bool found = false;
						for(it = rmv.begin(); it != rmv.end(); it++){
							if(!q.empty() && *it == q.front()){
								q.pop_front();
								if(q.back() < p) q.push_back(q.back()+1);
								found = true;
								break;
							}
						}
						if(!found) break;
					}
					if(	q.empty()){
						passed = true;
						cout << rmv.front() << endl;
						rmv.pb(rmv.front());
						rmv.pop_front();
					} else{
						cout << q.front() << endl;
						rmv.pb(q.front());
						q.pop_front();
					}
				}
			} else {
				scanf("%lld%*c", &num);
				if(passed) {
					for(it = rmv.begin(); it != rmv.end(); it++){
						if(*it == num){
							rmv.erase(it);
							break;
						}
					}
					rmv.push_front(num);
				} else {
					for(it = q.begin(); it != q.end(); it++){
						if(*it == num){
							q.erase(it);
							break;				
						}
					}
					q.push_front(num);
				}
			}
    }
  }  
  return 0;
}













