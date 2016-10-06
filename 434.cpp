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
	int t, k;
	cin >> t;
	while(t--){
		cin >> k;
		bool isA = true;
		int sumA = 0, sumB = 0, minimal = 0, maximal = 0;
		vector<int> front(k), right(k);
		set<int> si;
		set<int>::iterator it;
		REP(i, k) {
			cin >> front[i];
			sumA += front[i];
		}
		REP(i, k) {
			cin >> right[i];
			sumB += right[i];
		}
		REP(i, k) si.insert(front[i]);
		REP(i, k) si.insert(right[i]);
		REP(i, k){
			REP(j, k){
				if(front[i] > right[j]) maximal += right[j];
				else maximal += front[i];
			}
		}
		for(it = si.begin(); it != si.end(); it++){
			int A = 0, B = 0;
			REP(i, k) if(*it == front[i]) A++;
			REP(i, k) if(*it == right[i]) B++;
			minimal += *it*max(A,B);
		}
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", minimal, maximal-minimal);
	}
  return 0;
}
