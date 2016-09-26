#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int h, num = 1;
		h = (n+3)/4;
		int matrix[h][4];
		FOR(i, h){
			matrix[i][1] = num;
			num++;
			matrix[i][2] = num;
			num++;
		}
		for(int i = h-1; i >= 0; i--){
			matrix[i][3] = num;
			num++;
			matrix[i][0] = num;
			num++;
		}
		FOR(i, h) FOR(j, 4) if(matrix[i][j] > n) matrix[i][j] = 0;
		printf("Printing order for %d pages:\n", n);
		FOR(i, h){
			FOR(j, 4){
				if(j == 0) {
					printf("Sheet %d, front: ", i+1);
					if(matrix[i][0] == 0) printf("Blank, ");
					else printf("%d, ", matrix[i][0]);
					cout << matrix[i][1] << endl;
				}
				if(j == 2){
					if(matrix[i][2] != 0 || matrix[i][3] != 0){
						printf("Sheet %d, back : ", i+1);
						cout << matrix[i][2];
						if(matrix[i][3] == 0) printf(", Blank\n");
						else printf(", %d\n", matrix[i][3]);
					}
				}
			}
		}
  }
  return 0;
}



