#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int a, b, aux;
	while(cin >> a >> b && (a || b)){
		int asize, bsize, same;
		set<int> alice, betty;
		FOR(i, a){
			cin >> aux;
			alice.insert(aux);
		}
		asize = alice.size(); // 1
		FOR(i, b){
			cin >> aux;
			betty.insert(aux);
		}
		bsize = betty.size(); // 1
		for(set<int>::iterator it = betty.begin(); it != betty.end(); it++) alice.insert(*it); // 1
		same = betty.size() - (alice.size() - asize);// 1 - (1 - 1) = 1
		asize -= same;// 1 - 1 = 0
		bsize -= same;// 1 - 1 = 0
		cout << min(asize, bsize) << endl;
	}
  return 0;
}
