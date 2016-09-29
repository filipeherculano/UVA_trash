#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n, d, a;
	string line;
	map<string, int> h;
	h["pop"] 		= 0; 	h["no"] 		= 1; h["zip"]  = 2; h["zotz"] = 3; h["tzec"] 		=	4; 	h["xul"] 	= 5; 
	h["yoxkin"] = 6; 	h["mol"] 		= 7; h["chen"] = 8; h["yax"] 	= 9; h["zac"] 		= 10; h["ceh"] 	= 11; 
	h["mac"] 		= 12; h["kankin"] = 13;h["muan"] = 14;h["pax"]  = 15;h["koyab"] 	= 16; h["cumhu"]= 17; 
	h["uayet"] 	= 18;
	
	string t[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	cin >> n;
	cout << n << endl;
	while(n--){
		int mindex = 0, tempD, tempA;
		llu dias;
		scanf("%d%*c", &d);
		cin >> line;
		scanf("%d", &a);
		dias = a*365;
		dias += h[line]*20;
		dias += d;
		tempA = dias/260;
		dias %= 260;
		tempD = 1+(dias % 13);
		mindex = dias % 20;
		
		printf("%d ", tempD);
		cout << t[mindex];
		printf(" %d\n", tempA);
	}
  return 0;
}
