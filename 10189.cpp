#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	bool isFirst = true;
	int n, m, field = 1;
	while(cin >> n >> m && (n || m)){
		if(!isFirst) cout << endl;
		isFirst = false;
		scanf("%*c");	
		char matrix[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == '.') matrix[i][j] = '0';
				if(matrix[i][j] == '*'){
					if(i-1 >= 0 && j-1 >= 0) {
						if(matrix[i-1][j-1] == '.') matrix[i-1][j-1] = '1';
						else if(matrix[i-1][j-1] >= 48) matrix[i-1][j-1]++;
					}
					if(i-1 >= 0 && j >= 0){
						if(matrix[i-1][j] == '.') matrix[i-1][j] = '1';
						else if(matrix[i-1][j] >= 48) matrix[i-1][j]++;
					}    
					if(i-1 >= 0 && j+1 < m){
						if(matrix[i-1][j+1] == '.') matrix[i-1][j+1] = '1';
						else if(matrix[i-1][j+1] >= 48) matrix[i-1][j+1]++;
					}   
					if(i+1 < n && j-1 >= 0) {
						if(matrix[i+1][j-1] == '.') matrix[i+1][j-1] = '1';
						else if(matrix[i+1][j-1] >= 48) matrix[i+1][j-1]++;
					}  
					if(i+1 < n && j >= 0) {
						if(matrix[i+1][j] == '.') matrix[i+1][j] = '1';
						else if(matrix[i+1][j] >= 48) matrix[i+1][j]++;
					}    
					if(i+1 < n && j+1 < m) {
						if(matrix[i+1][j+1] == '.') matrix[i+1][j+1] = '1';
						else if(matrix[i+1][j+1] >= 48) matrix[i+1][j+1]++;
					}   
					if(i >= 0 && j+1 < m) {
						if(matrix[i][j+1] == '.') matrix[i][j+1] = '1';
						else if(matrix[i][j+1] >= 48) matrix[i][j+1]++;
					}  
					if(i >= 0 && j-1 >= 0) {
						if(matrix[i][j-1] == '.') matrix[i][j-1] = '1';
						else if(matrix[i][j-1] >= 48) matrix[i][j-1]++;
					}   
				}	
			}
		}
		printf("Field #%d:\n", field++);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j];
			cout << endl;
		}
	}
	return 0;
}
