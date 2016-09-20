#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
		bool isFirst = true;
		int t, r, c ,n;
		cin >> t;
		while(t--){
				if(!isFirst) cout << endl;
				isFirst = false;
				cin >> r >> c >> n;
				scanf("%*c");
				char matrix[r][c], temp[r][c];
				FOR(i, r) FOR(j, c) cin >> matrix[i][j];
				while(n--){
						FOR(i, r){
								FOR(j, c){
										bool lose = false;
										if(matrix[i][j] == 'R'){ // ROCK
												if((i-1) >= 0){
														if(matrix[i-1][j] == 'P') lose = true;
														else if(matrix[i-1][j] == 'S') temp[i-1][j] = 'R';
												}
												if((j-1) >= 0){
														if(matrix[i][j-1] == 'P') lose = true;
														else if(matrix[i][j-1] == 'S') temp[i][j-1] = 'R';
												}
												if(i+1 < r){
														if(matrix[i+1][j] == 'P') lose = true;
														else if(matrix[i+1][j] == 'S') temp[i+1][j] = 'R';
												}
												if(j+1 < c){
														if(matrix[i][j+1] == 'P') lose = true;
														else if(matrix[i][j+1] == 'S') temp[i][j+1] = 'R';
												}
												if(lose) temp[i][j] = 'P';
                        else temp[i][j] = 'R';

										} else if(matrix[i][j] == 'P'){ // PAPER
												if((i-1) >= 0){
														if(matrix[i-1][j] == 'S') lose = true;
														else if(matrix[i-1][j] == 'R') temp[i-1][j] = 'P';
												}
												if((j-1) >= 0){
														if(matrix[i][j-1] == 'S') lose = true;
														else if(matrix[i][j-1] == 'R') temp[i][j-1] = 'P';
												}
												if(i+1 < r){
														if(matrix[i+1][j] == 'S') lose = true;
														else if(matrix[i+1][j] == 'R') temp[i+1][j] = 'P';
												}
												if(j+1 < c){
														if(matrix[i][j+1] == 'S') lose = true;
														else if(matrix[i][j+1] == 'R') temp[i][j+1] = 'P';
												}
												if(lose) temp[i][j] = 'S';
                        else temp[i][j] = 'P';

										} else if(matrix[i][j] == 'S'){ // SCISSOR
												if((i-1) >= 0){
														if(matrix[i-1][j] == 'R') lose = true;
														else if(matrix[i-1][j] == 'P') temp[i-1][j] = 'S';
												}
												if((j-1) >= 0){
														if(matrix[i][j-1] == 'R') lose = true;
														else if(matrix[i][j-1] == 'P') temp[i][j-1] = 'S';
												}
												if(i+1 < r){
														if(matrix[i+1][j] == 'R') lose = true;
														else if(matrix[i+1][j] == 'P') temp[i+1][j] = 'S';
												}
												if(j+1 < c){
														if(matrix[i][j+1] == 'R') lose = true;
														else if(matrix[i][j+1] == 'P') temp[i][j+1] = 'S';
												}
												if(lose) temp[i][j] = 'R';
                        else temp[i][j] = 'S';
										}
								}			
						}
						FOR(i, r) FOR(j, c) matrix[i][j] = temp[i][j];
				}
			  FOR(i, r) {
          FOR(j, c) cout << matrix[i][j];
          cout << endl;
        }
		}
		return 0;
}
