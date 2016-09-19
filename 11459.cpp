#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  	int t, a, b, c, bottom, top, die;
	cin >> t;
	while(t--){
		bool end = false;
		int v[100] = {0}, play = 0;
		cin >> a >> b >> c;
		int p[a];
		for(int i = 0; i < a; i++) p[i] = 0;
		for(int i = 0; i < b; i++){
			cin >> bottom >> top;
			v[bottom-1] = top-1;
		}
		for(int i = 0; i < c; i++){
			cin >> die;
			if(!end){
				p[play] += die;
				if(p[play] >= 99){
					p[play] = 99;
					end = true;
				} else if(v[p[play]]){
					 p[play] = v[p[play]];
					if(p[play] == 99) end = true;				
				}
			}
			play++;
			play %= a;
		}
		for(int i = 0; i < a; i++)
			printf("Position of player %d is %d.\n", i+1, p[i]+1);
	}
	return 0;
}
