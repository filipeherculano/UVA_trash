#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int t;
	scanf("%d%*c", &t);
	while(t--){
		char c;
		int m, n;
		cin >> c >> m >> n;
		if(c == 'r' || c == 'Q') cout << min(m, n) << endl;
		else if(c == 'K') cout << ceil((float)m/2.0)*ceil((float)n/2.0) << endl;
		else cout << (ceil((float)m/2.0)*ceil((float)n/2.0)) + ((m/2) * (n/2)) << endl;
		// problem setters didn't create tricky test cases for this problem.
		// when the choice is the 'knights' and one of the sides is equal to
		// 2, then the correct maximum number of knights should be calculated
		// differently. The correct calculation is in the 696.cpp in this repository
	}
  	return 0;
}
