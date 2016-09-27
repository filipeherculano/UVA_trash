#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int x, y, puzz = 1;
	bool isFirst = true;
	while(cin >> x && x){
		scanf("%d%*c", &y);
		if(!isFirst) cout << endl;
		isFirst = false;
		string temp;
		vector<string> across, down;
		int numbers[x][y], num = 1;
		char m[x][y];
		FOR(i, x) FOR(j, y) cin >> m[i][j];
		FOR(i, x) {
			FOR(j, y){
				if(m[i][j] != '*'){
					if(!i || !j || m[i-1][j] == '*' || m[i][j-1] == '*'){
						numbers[i][j] = num;
						num++;
					} else numbers[i][j] = 0;
				} else numbers[i][j] = 0;
			}
		}
		printf("puzzle #%d:\nAcross\n", puzz++);
		FOR(i, x){
			FOR(j, y){
				if(m[i][j] != '*') {
					if(temp.size() == 0) printf("%s%d.", numbers[i][j] < 10 ? "  ": " ", numbers[i][j]);
					temp.push_back(m[i][j]);
				}
				if((m[i][j] == '*' || j == y-1) && temp.size() > 0){
					across.push_back(temp);
					cout << temp << endl;
					temp.clear();
				}
			}
		}
		printf("Down\n");
		FOR(i, x){
			FOR(j, y){
				int z = i;
				if(m[z][j] != '*'){
					while(m[z][j] != '*' && z != x-1){
						if(temp.size() == 0) printf("%s%d.", numbers[z][j] < 10 ? "  ": " ", numbers[z][j]);
						temp.push_back(m[z][j]);
						m[z][j] = '*';
						z++;
					}
					if(z == x-1 && m[z][j] != '*'){
						if(temp.size() == 0) printf("%s%d.", numbers[z][j] < 10 ? "  ": " ", numbers[z][j]);
						temp.push_back(m[z][j]);
						m[z][j] = '*';
					}
					down.push_back(temp);
					cout << temp << endl;
					temp.clear();
				}
			}
		}
	}
  return 0;
}


