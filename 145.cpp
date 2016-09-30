#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	char c;
	double matrix[5][3] = {0.1, 0.06, 0.02,
												 0.25,0.15, 0.05,
												 0.53,0.33, 0.13,
												 0.87,0.47, 0.17,
												 1.44,0.8, 	0.3};
	while(cin >> c && c != '#'){
		int h1, h2, m1, m2, start, end, D = 8*60, E = 18*60, N = 22*60;
		int w[3] = {0};
		E -= D; N -= D;
		string num;
		cin >> num >> h1 >> m1 >> h2 >> m2;
		start = (h1*60 + m1) - D + 1;
		end = (h2*60 + m2) - D;
		D = 0;
		cout << "  " << num << " ";
		FOR(i, start, end+1) {
			if(i > D && i <= E) w[0]++;
			else if(i > E && i <= N) w[1]++;
			else if(i > N || i == 0) w[2]++;
			i %= 1440;
		}
		printf("%5d%5d%5d  %c%5.2lf\n", w[0], w[1], w[2], c, matrix[c-'A'][0]*(double)w[0] + matrix[c-'A'][1]*(double)w[1] + matrix[c-'A'][2]*(double)w[2]);
	}
  return 0;
}


