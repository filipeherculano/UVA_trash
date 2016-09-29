#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int t, m, d;
	map<int, string> mis;
	int mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	mis[3] = "Monday"; mis[4] = "Tuesday"; mis[5] = "Wednesday";
	mis[6] = "Thursday"; mis[0] = "Friday"; mis[1] = "Saturday";
	mis[2] = "Sunday";
	cin >> t;
	while(t--){
		cin >> m >> d;
		int days = d;
		FOR(i, m-1) days += mes[i];
		days %= 7;
		cout << mis[days] << endl;
	}
  return 0;
}
