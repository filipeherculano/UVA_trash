#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line;
	while(cin >> line){
		//cout << line << endl;
		long long h1, h2, m1, m2, s1, s2, c1, c2, t1, t2;
		h1 = (line[0]-'0')*10 + (line[1]-'0'); h1 = h1*60*60*100;
		m1 = (line[2]-'0')*10 + (line[3]-'0'); m1 = m1*60*100;
		s1 = (line[4]-'0')*10 + (line[5]-'0'); s1 = s1*100;
		c1 = (line[6]-'0')*10 + (line[7]-'0');
		t1 = (h1 + m1 + s1 + c1);
		t1 /= 0.864;
		printf("%lld", t1/1000000);
		t1 %= 1000000;
		if(t1/10000 < 10) printf("0");
		printf("%lld", t1/10000);
		t1 %= 10000;
		if(t1/100 < 10) printf("0");
		printf("%lld", t1/100);
		t1 %= 100;
		if(t1 < 10) printf("0");
		printf("%lld\n", t1);
	}
  return 0;
}
