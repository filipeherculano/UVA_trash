#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int c, t, n;
	cin >> c;
	while(c--){
		int x1, y1, x2, y2;
		cin >> n;
		cin >> t;
		for(int i = 0; i < n; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			if(((abs(x1-x2)&1) && (abs(y1-y2)&1)) || (!(abs(x1-x2)&1) && !(abs(y1-y2)&1))){
				if(x1 == x2 && y1 == y2) cout << "0\n";
				else if(abs(x1-x2) == abs(y1-y2)) cout << "1\n";
				else cout << "2\n";
			} else cout << "no move\n";
		}
	}
	return 0;
}
