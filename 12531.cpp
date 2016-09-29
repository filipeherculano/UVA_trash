#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int h = 0, m = 0, i = 0, a;
	set<double> ang;
	set<double>::iterator it;
	while(h != 360){
		double ang1, ang2;
		i++;
		ang1 = abs(m-h);
		ang2 = 360-ang1;
		ang.insert(min(ang1, ang2));
		if(i == 12){
			h += 6;
			i = 0;
		}
		m += 6; m %= 360;
	}
	while(cin >> a){
		it = ang.find(a);
		if(it == ang.end()) cout << "N\n";
		else cout << "Y\n";
	}
  return 0;
}
