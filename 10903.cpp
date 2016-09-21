#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	bool isFirst = true;
	int n, k, p1, p2;
	string m1, m2;
	while(cin >> n && n){
		if(!isFirst) cout << endl;
		isFirst = false;
	  cin >> k;
	  int games = (k*n*(n-1)) / 2;
	  double v[2][n];
	  memset(v, 0, sizeof(double)*n*2);
	  FOR(i, games){
	  	cin >> p1 >> m1 >> p2 >> m2;
	  	scanf("%*c");
	  	if(!m1.compare("rock")){
	  		if(!m2.compare("scissors")) {v[0][p1-1]++; v[1][p2-1]++;}
	  		else if(!m2.compare("paper")) {v[0][p2-1]++; v[1][p1-1]++;}
	  	} else if(!m1.compare("paper")){
	  		if(!m2.compare("rock")) {v[0][p1-1]++; v[1][p2-1]++;}
	  		else if(!m2.compare("scissors")) {v[0][p2-1]++; v[1][p1-1]++;}
	  	} else if(!m1.compare("scissors")){
	  		if(!m2.compare("paper")) {v[0][p1-1]++; v[1][p2-1]++;}
	  		else if(!m2.compare("rock")) {v[0][p2-1]++; v[1][p1-1]++;}
	  	}
	  }
	  FOR(i, n){
	  	if((v[0][i] + v[1][i])){
	  		printf("%.3lf\n", v[0][i] / (v[0][i] + v[1][i]));
	  	} else printf("-\n");
	  }
	}
  return 0;
}
