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
	int n;
	scanf("%d%*c", &n);
	map<ll, string> msll;
	while(n--){
		ll d, m, a, total = 0;
		string name;
		cin >> name >> d >> m >> a;
		total += d + m*30 + 365*a;
		msll.insert(std::pair<ll, string>(total, name));
	}
	cout << msll.rbegin()->second << endl;
	cout << msll.begin()->second << endl;
  return 0;
}
