#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, m, c, r;
	while(cin >> k && k){
		bool OK = true;
		cin >> m;
		scanf("%*c");
		string fred[k], aux;
		for(int i = 0; i < k; i++)
			cin >> fred[i];
		for(int i = 0; i < m; i++){
			int count = 0;
			cin >> c >> r;
			for(int j = 0; j < c; j++){
				cin >> aux;
				for(int x = 0; x < k; x++)
					if(!fred[x].compare(aux)) count++;
			}
			if(count < r) OK = false;
		}
		printf("%s\n", OK ? "yes": "no");
	}		
	return 0;
}
