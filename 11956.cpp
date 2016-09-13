#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, caso = 1;
	scanf("%d%*c", &t);
	while(t--){
		unsigned char led[100];
		memset(led , 0, 100);
		int index = 0;
		string line;
		getline(cin, line);
		for(int i = 0; i < line.size(); i++){
			if(line[i] == '>'){
				if(index == 99) index = 0;
				else index++;
			} else if(line[i] == '<'){
				if(index == 0) index = 99;
				else index--;
			} else if(line[i] == '+') led[index]++;
			else if(line[i] == '-') led[index]--;
		}
		printf("Case %d: ", caso++);
		for(int i = 0; i < 100; i++){
			if(led[i] < 16) printf("1");
			printf("%X%c", led[i], i == 99 ? '\n': ' ');
		}
	}	
	return 0;
}
