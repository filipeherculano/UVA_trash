#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs<rhs);
    else return (lhs>rhs);
  }
};

int main(){
	int n;
	while(cin >> n && n){
		int cnt = 0, aux;
		priority_queue<int, vector<int>, mycomparison> pq;
		REP(i, n) {
			cin >> aux;
			pq.push(aux);
		}
		while(pq.size() >= 2){
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			cnt += a+b;
			pq.push(a+b);
		}
		cout << cnt << endl;
	}
  return 0;
}
