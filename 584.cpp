#include <bits/stdc++.h>

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line;
	while(getline(cin, line) && line.compare("Game Over")){
		int count = 0;
		vector<int> vi;
		for(int i = 0; i < line.size(); i+=2) {
			if(line[i] == 'X') vi.push_back(-1);
			else if(line[i] >= '0' && line[i] <= '9') {
				vi.push_back(line[i]-'0');
				i += 2;
				if(line[i] >= '0' && line[i] <= '9') vi[vi.size()-1] += line[i]-'0';
				else if(line[i] == '/') vi[vi.size()-1] = -2;
			}
		}
		for(int i = 0; i < vi.size(); i++) cout << vi[i] << " ";
		cout << endl;
		for(int i = vi.size()-1; i >= 0; i--){
			if(vi[i] == -1){
				vi[i] = 10;
				if(i+1 < vi.size() && i+2 < vi.size()) count += vi[i] + vi[i+1] + vi[i+2];
			} else if(vi[i] == -2){
				vi[i] = 10;
				if(i+1 < vi.size()) count += vi[i] + vi[i+1];
			} else if(i+1 < vi.size() && i+2 < vi.size()) count += vi[i];
		}
		for(int i = 0; i < vi.size(); i++) cout << vi[i] << " ";
		cout << endl;
		cout << count << endl;
	}
  return 0;
}
