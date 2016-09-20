#include <bits/stdc++.h>

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		bool found = false;
		int bingo[2][5][5], aux, number;
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(i == 2 && j == 2) {
					bingo[0][i][j] = -1;
					bingo[1][i][j] = 1;
				} else {
					cin >> bingo[0][i][j];
					bingo[1][i][j] = 0;
				}
			}
		}
		for(int k = 0; k < 75; k++){
			cin >> aux;
			for(int i = 0; i < 5 && !found; i++){
				for(int j = 0; j < 5 && !found; j++){
					if(bingo[0][i][j] == aux){
						bingo[1][i][j] = 1;
						int count = 0;
						for(int z = 0; z < 5; z++) if(bingo[1][i][z]) count++;
						if(count == 5) {
							number = k+1;
							found = true;
						}
						count = 0;
						for(int z = 0; z < 5; z++) if(bingo[1][z][j]) count++;
						if(count == 5) {
							number = k+1;
							found = true;
						}
						count = 0;
						for(int z = 0; z < 5; z++) if(bingo[1][z][z]) count++;
						if(count == 5) {
							number = k+1;
							found = true;
						}
						count = 0;
						for(int z = 0; z < 5; z++) if(bingo[1][4-z][z]) count++;
						if(count == 5) {
							number = k+1;
							found = true;
						}
					}				
				}
			}
		}
		printf("BINGO after %d numbers announced\n", number);
	}
  return 0;
}
