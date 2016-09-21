#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		bool lost = false;
		int matrix[n][n];
		vector<int> vii;
		FOR(i, n) FOR(j, n) matrix[i][j] = 0; // 2500 op.
		FOR(i, 2*n){ // 100 op.
			int lin, col;
			char c;
			cin >> lin >> col >> c;
			scanf("%*c");
			if(!lost){
				bool valid = false;
				lin--; col--;
				if(c == '+') matrix[lin][col] = 1;
				else if(c == '-') matrix[lin][col] = 0;
				FOR(j, n) FOR(k, n) if(matrix[j][k]) valid = true; // 2500 op.
				if(valid){
					for(int z = 0; z < vii.size(); z+=(n*n)){
						int count = 0;
						FOR(j, n) FOR(k, n) if(matrix[j][k] == vii[z+(j*n)+k]) count++; //2500 op.
						if(count == n*n) {
							lost = true;
							printf("Player %d wins on move %d\n", i&1 ? 1 : 2, i+1);
							break;
						}
					}
					if(!lost){
						FOR(j, n) FOR(k, n)	vii.push_back(matrix[j][k]); //2500 op.
						FOR(j, n) FOR(k, n) vii.push_back(matrix[(n-1)-k][j]); //2500 op.
						FOR(j, n) FOR(k, n) vii.push_back(matrix[(n-1)-j][(n-1)-k]); //2500 op.
						FOR(j, n) FOR(k, n) vii.push_back(matrix[k][(n-1)-j]); //2500 op.
					}
				}
			}
		}
		if(!lost) printf("Draw\n");
	}
  return 0;
}
