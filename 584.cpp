#include <bits/stdc++.h>

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line;
	while(getline(cin, line) && line.compare("Game Over")){
		int count = 0, points[12][3], index = 0;
		for(int i = 0; i < 12; i++)
			for(int j = 0; j < 3; j++)
				points[i][j] = -1;

		for(int i = 0; i < line.size(); i++) {
			if(line[i] != ' '){
				if(line[i] == 'X') {
					points[index][0] = 2;
					points[index][1] = 10;
					points[index][2] = -1;
					index++;
				} else if(line[i] >= '0' && line[i] <= '9') {
					points[index][1] = line[i] - '0';
					while(line[++i] == ' ');
					if(line[i] >= '0' && line[i] <= '9') {
						points[index][2] = line[i] - '0';
						points[index][0] = 0;
					} else if(line[i] == '/')	{
						points[index][2] = 10 - points[index][1];
						points[index][0] = 1;
					}
					index++;
				}
			}
		}
		for(int i = 0; i < 10; i++){
			int roll = points[i][0];
			if(points[i][0] == 2) count += points[i][1];
			else count += points[i][1] + points[i][2];
			for(int j = i+1; j < 12 && roll; j++){
				for(int k = 1; k < 3 && roll; k++){
					if(points[j][k] != -1 && roll){
						count += points[j][k];
						roll--;						
					}
				}
			}
		}
		cout << count << endl;
	}
  return 0;
}
