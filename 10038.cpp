#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		bool jolly = true;
		vector<bool> v(n-1);
		for(int i = 0; i < n-1; i++) v[i] = false;
		int num[n];
		for(int i = 0; i < n; i++){
			cin >> num[i];
			if(i && abs(num[i-1] - num[i])-1 >= 0 && abs(num[i-1] - num[i])-1 <= n-2) v[abs(num[i-1] - num[i])-1] = true;
		}
		for(int i = 0; i < n-1; i++)
			if(!v[i]) jolly = false;
		printf("%s\n", jolly ? "Jolly" : "Not jolly");
	}
	return 0;
}
