#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

bool div100(string a){
	bool ok = true;
	if(a[a.size()-1] != '0' || a[a.size()-2] != '0') ok = false;
	return ok;
}

bool div4(string a){
	bool ok = true;
	int tens = (a[a.size()-2]-'0');
	int ones = (a[a.size()-1]-'0');
	if(((tens*10) + ones) % 4) ok = false;
	return ok;
}

bool div400(string a){
	bool ok = true;
	ok = div100(a);
	if(ok){
		a.erase(a.size()-2, 2);
		ok = div4(a);
	}
	return ok;
}

bool div5(string a){
	bool ok = true;
	if(a[a.size()-1] != '0' && a[a.size()-1] != '5') ok = false;
	return ok;
}

bool div3(string a){
	bool ok = true;
	while(a.size() > 1){
		int sum = 0;
		FOR(i, a.size()) sum += a[i] - '0';
		a.clear();
		a = to_string(sum);
	}
	if((a[0] - '0') % 3) ok = false;
	return ok;
}

bool div15(string a){
	bool ok = true;
	ok = div5(a);
	if(ok) ok = div3(a);
	return ok;
}

bool div11(string a){
	bool ok = true;
	int sum = 0;
	FOR(i, a.size()){
		if(i&1) sum -= (a[i] - '0');
		else sum += (a[i] - '0');
	}
	if(sum % 11) ok = false;
	return ok;
}

bool div55(string a){
	bool ok = true;
	ok = div5(a);
	if(ok) ok = div11(a);
	return ok;
}



int main(){
	bool isFirst = true;
	string year;
	while(getline(cin, year)){
		if(!isFirst) cout << endl;
		isFirst = false;
		bool leap = false, hulu = false, bulu = false;
		if(div400(year) ^ (div4(year) && !div100(year))) leap = true;
		if(div15(year)) hulu = true;
		if(div55(year) && leap) bulu = true;
		
		if(leap) printf("This is leap year.\n");
		if(hulu) printf("This is huluculu festival year.\n");
		if(bulu) printf("This is bulukulu festival year.\n");
		if(!leap && !hulu && !bulu) printf("This is an ordinary year.\n");
	}
  return 0;
}
