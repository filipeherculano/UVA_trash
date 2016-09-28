#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int h, m;
	while(scanf("%d:%d", &h, &m) && (h || m)){
		double horas, minutos;
		horas = h*30 + m*0.5; minutos = m*6;
		if(horas == 360) horas = 0;
		printf("%.3lf\n", min(abs(horas-minutos), 360.0 - abs(horas-minutos)));
	}
  return 0;
}
