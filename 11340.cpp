#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, m;
	cin >> n;
	while(n--){
		map<char, int> values;
		double sum = 0.0;
		char chave;
		int valor;

		scanf("%d%*c", &k);
		for(int i = 0; i < k; i++){
			cin >> chave >> valor;
			values.insert(std::pair<char, int>(chave, valor));
		}	
		
		scanf("%d%*c", &m);
		for(int i = 0; i < m; i++){
			string line;
			getline(cin, line);
			for(int j = 0; j < line.size(); j++){
				map<char, int>::iterator it = values.find(line[j]);
				if(it != values.end()) sum += it->second;
			}
		}
		
		printf("%.2lf$\n", sum/100.0);
	}
	return 0;
}
