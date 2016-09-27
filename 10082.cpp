#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line;
	char v[47] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
	while(getline(cin, line)){
		for(int i = 0; i < line.size(); i++){
		      if(line[i] == ' ') cout << line[i];
		      else {
			for(int j = 0; j < 47; j++){
			    if(v[j] == line[i]) cout << v[j-1];
			}
		      }
		}
		cout << endl;
	}
	return 0;
}
