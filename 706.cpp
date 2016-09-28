#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string num;
	int s;
	char matrix[10][5][3];
	FOR(i, 10) FOR(j, 5) FOR(z, 3) matrix[i][j][z] = ' ';
	matrix[0][0][1] = '-'; matrix[0][4][1] = '-';
	matrix[0][1][0] = '|'; matrix[0][1][2] = '|';
	matrix[0][3][0] = '|'; matrix[0][3][2] = '|';
	
	matrix[1][1][2] = '|'; matrix[1][3][2] = '|';
	
	matrix[2][0][1] = '-'; matrix[2][2][1] = '-'; matrix[2][4][1] = '-';
	matrix[2][3][0] = '|'; matrix[2][1][2] = '|';
	
	matrix[3][0][1] = '-'; matrix[3][2][1] = '-'; matrix[3][4][1] = '-';
	matrix[3][3][2] = '|'; matrix[3][1][2] = '|';

	matrix[4][2][1] = '-';
	matrix[4][1][0] = '|'; matrix[4][1][2] = '|'; matrix[4][3][2] = '|';

	matrix[5][0][1] = '-'; matrix[5][2][1] = '-'; matrix[5][4][1] = '-';
	matrix[5][3][2] = '|'; matrix[5][1][0] = '|';
	
	matrix[6][0][1] = '-'; matrix[6][2][1] = '-'; matrix[6][4][1] = '-';
	matrix[6][1][0] = '|'; matrix[6][3][0] = '|'; matrix[6][3][2] = '|';
	
	matrix[7][0][1] = '-';
	matrix[7][1][2] = '|'; matrix[7][3][2] = '|';
	
	matrix[8][0][1] = '-'; matrix[8][2][1] = '-'; matrix[8][4][1] = '-';
	matrix[8][1][0] = '|'; matrix[8][1][2] = '|';
	matrix[8][3][0] = '|'; matrix[8][3][2] = '|';	
	
	matrix[9][0][1] = '-'; matrix[9][2][1] = '-'; matrix[9][4][1] = '-';
	matrix[9][1][0] = '|'; matrix[9][1][2] = '|'; matrix[9][3][2] = '|';	
	while(cin >> s && s){
		scanf("%*c");
		cin >> num;
		FOR(i, 5){
			bool found = false;
			FOR(z, num.size()){
				FOR(j, 3){
					if(i&1){
						cout << matrix[num[z]-'0'][i][j];
						if(j && j != 2 && matrix[num[z]-'0'][i][j] == ' ') FOR(k, s-1) cout << matrix[num[z]-'0'][i][j];
					} else {
						cout << matrix[num[z]-'0'][i][j];
						if(j == 1 && matrix[num[z]-'0'][i][j] == ' ') FOR(k, s-1) cout << matrix[num[z]-'0'][i][j];
						if(matrix[num[z]-'0'][i][j] == '-') FOR(k, s-1) cout << matrix[num[z]-'0'][i][j];
					}
				}
				printf("%c", z == num.size()-1 ? '\n':' ');
			}
			if(i&1 && s > 1){
				FOR(g, s-1){
					FOR(z, num.size()){
						FOR(j, 3){
							cout << matrix[num[z]-'0'][i][j];
							if(j && j != 2 && matrix[num[z]-'0'][i][j] == ' ') FOR(k, s-1) cout << matrix[num[z]-'0'][i][j];
						}
						printf("%c", z == num.size()-1 ? '\n':' ');
					}
				}
			}
		}
		cout << endl;
	}
  return 0;
}













