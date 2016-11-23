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

using namespace std;

int main(){
	double ini, fim;
	scanf("%lf %lf", &ini, &fim);
	if(ini > fim) swap(ini,fim);
	ini *= 1000000; fim *= 1000000;
	
	for(ll i = ini; i <= fim; i += 10000){
		if(i%3 == 0){
			for(ll a = 1; a*a*a <= i; a++){
				if(i%a == 0){
					for(ll b = a; b*b <= (i/a); b++){
						if((i/a)%b == 0){
							ll c = (i/a)/b;
							if(i == (a+b+c)*10000){
								printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",
									(double)i/1000000.0, (double)a/100.0, (double)b/100.0, (double)c/100.0,(double)a/100.0, (double)b/100.0, (double)c/100.0);
							}
						}
					}
				}
			}
		}
	}
  return 0;
}
