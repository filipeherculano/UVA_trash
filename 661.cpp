#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, c, caso = 1;
	while(cin >> n >> m >> c && (n || m || c)){
		int dev[n], bitmask = 0, aux, max = 0;
		bool OK = true;
		for(int i = 0; i < n; i++)
			cin >> dev[i];
	
		for(int i = 0; i < m; i++){
			int sum = 0;
			cin >> aux;
			if(bitmask&(1 << (aux-1))) bitmask &= ~(1 << (aux-1));
			else bitmask |= (1 << (aux-1));
			for(int j = 0; j < n; j++)
				if(bitmask&(1 << j)) sum += dev[j];
			if(max < sum) max = sum;
			if(sum > c) OK = false;
		}
		if(OK) printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n", caso++, max);	
		else printf("Sequence %d\nFuse was blown.\n", caso++);
		cout << endl;
	}		
	return 0;
}
