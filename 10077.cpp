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
	int m, n;
	while(scanf("%d %d", &m, &n) && (m != 1 || n != 1)){
		pair<int,int> l = {0,1}, h = {1,0};
		string res;
		bool found = false;
		while(!found){
			pair<int,int> med = {l.first + h.first,l.second + h.second};
			if(((double)med.first/(double)med.second) == ((double)m/(double)n)) found = true;
			else if(((double)med.first/(double)med.second) < ((double)m/(double)n)){
				l = med;
				res.pb('R');
			} else {
				h = med;
				res.pb('L');
			}
		}
		cout << res << endl;
	}
  return 0;
}
