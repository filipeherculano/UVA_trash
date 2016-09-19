#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int n;
	while(scanf("%d%*c", &n) && n){
		string move;
		int top = 1, up = 2, left = 3, temp;
		for(int i = 0; i < n; i++){
			cin >> move;
			if(!move.compare("north")){
				temp = top;
				top = 7-up;
				up = temp;
			} else if(!move.compare("south")){
				temp = top;
				top = up;
				up = 7-temp;
			} else if(!move.compare("west")){
				temp = top;
				top = 7-left;
				left = temp;
			} else if(!move.compare("east")){
				temp = top;
				top = left;
				left = 7-temp;
			}
		}
		cout << top << endl;
	}  
	return 0;
}
