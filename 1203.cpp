#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

class compare{
	public:
		bool operator() (tuple<int,int,int> a, tuple<int,int,int> b){ // query, actual, period
			if(get<1>(a) != get<1>(b)){
				return get<1>(a) > get<1>(b);
			} else return get<0>(a) > get<0>(b);
		}
};

int main(){
	int n;
	string line;
	priority_queue<int, vector< tuple<int,int,int> >, compare> pq;
	while(cin >> line && line != "#"){
		int q, f;
		cin >> q >> f;
		pq.push(make_tuple(q,f,f));
	}
	scanf("%*c%d", &n);
	while(n){
		int top = get<1>(pq.top());
		while(get<1>(pq.top()) == top && n){
			cout << get<0>(pq.top()) << endl;
			tuple<int,int,int> temp = pq.top();
			get<1>(temp) += get<2>(temp);
			pq.pop();
			pq.push(temp);
			n--;
		}
	}
  return 0;
}









