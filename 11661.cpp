#include <bits/stdc++.h>

using namespace std;

int main(){
	int l;
	while(scanf("%d%*c", &l) && l){
		string line;
		long long r= -2000001, d = 2000001, z = -2000001, min = 2000001;
		cin >> line;
		for(int i = 0; i < l; i++){
			if(line[i] == 'R') r = i;
			else if(line[i] == 'D') d = i;
			else if(line[i] == 'Z'){
				cout << "0" << endl;
				break;
			}
			if(min > llabs(r-d)) min = llabs(r-d);
			if(i == l-1) cout << min << endl;
		}
	}	
	return 0;
}
