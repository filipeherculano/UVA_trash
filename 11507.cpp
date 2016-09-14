#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int t[6][4];
	t[0][0] = 2; t[0][1] = 3; t[0][2] = 5; t[0][3] = 4;
	t[1][0] = 3; t[1][1] = 2; t[1][2] = 4; t[1][3] = 5;
	t[2][0] = 1; t[2][1] = 0; t[2][2] = 2; t[2][3] = 2;
	t[3][0] = 0; t[3][1] = 1; t[3][2] = 3; t[3][3] = 3;
	t[4][0] = 4; t[4][1] = 4; t[4][2] = 0; t[4][3] = 1;
	t[5][0] = 5; t[5][1] = 5; t[5][2] = 1; t[5][3] = 0;
	int l;
	while(scanf("%d%*c", &l) && l){
		string index;
		int v[l-1], pos = 0;
		for(int i = 0; i < l-1; i++){
			cin >> index;
			if(!index.compare("+y")) v[i] = 0;
			else if(!index.compare("-y")) v[i] = 1; 
			else if(!index.compare("-z")) v[i] = 2;
			else if(!index.compare("+z")) v[i] = 3;
			else v[i] = 4;
		}
		for(int i = 0; i < l-1; i++) 
			if(v[i] != 4)
				pos = t[pos][v[i]];
		switch(pos){
			case 0: cout << "+x" << endl;
				break;
			case 1: cout << "-x" << endl;
				break;
			case 2: cout << "+y" << endl;
				break;
			case 3: cout << "-y" << endl;
				break;
			case 4: cout << "+z" << endl;
				break;
			case 5: cout << "-z" << endl;
				break;
		}
	}
	return 0;
}
