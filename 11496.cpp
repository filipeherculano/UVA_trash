#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int v[n+2], count = 0;
		for(int i = 1; i <= n; i++)
			cin >> v[i];
		v[0] = v[n];
		v[n+1] = v[1];
		for(int i = 1; i <= n; i++)
			if((v[i-1] > v[i] && v[i+1] > v[i]) || (v[i-1] < v[i] && v[i+1] < v[i]))
				count++;
		cout << count << endl;
	}
	return 0;
}
