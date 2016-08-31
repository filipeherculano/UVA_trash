#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, tail, size;
	while(scanf("%d%*c", &n) && n){
		string line;
		cin >> line;
		size = line.size() / n;
		for(int cluster = 0; cluster < line.size(); cluster += size){
			tail = cluster + size - 1;
			for(int head = cluster; head < tail; head++){
				swap(line[head], line[tail]);
				tail--;
			}
		}
		cout << line << endl;
	}
	return 0;
}
