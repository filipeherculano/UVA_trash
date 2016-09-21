#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int a, b, c;
	while(cin >> a >> b >> c){
		int matrix[8][8];
		FOR(i, 8) FOR(j, 8) matrix[i][j] = 0;
		matrix[b/8][b%8] = -1;
		matrix[a/8][a%8] = -2;
		for(int i = (b%8); i < 8; i++) {matrix[b/8][i] = matrix[b/8][i] == -2 ? -2 : 1; break;}
		for(int i = (b%8); i >= 0; i--) {matrix[b/8][i] = matrix[b/8][i] == -2 ? -2 : 1; break;}
		for(int i = (b/8); i >= 0; i-=8) {matrix[i][b%8] = matrix[i][b%8] == -2 ? -2 : 1; break;}
		for(int i = (b/8); i < 63; i+=8) {matrix[i][b%8] = matrix[i][b%8] == -2 ? -2 : 1; break;}
		// kings missing yet
		if(a == b) cout << "Illegal state\n";
		else if(!((b % 8 == c % 8) || (b/8 == c/8)) || b == c) cout << "Illegal move\n";
		else if(c == (a-8) || c == (a+8) || c == (a-1) || c == (a+1)) cout << "Move not allowed\n";
		else if((a == 0 && c == 9) || (a == 7 && c == 14) || (a == 56 && c == 49) || (a == 63 && c == 54)) cout << "Stop\n";
		else cout << "Continue\n";
	}
  return 0;
}
