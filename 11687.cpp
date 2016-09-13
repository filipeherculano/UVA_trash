#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;
	while(cin >> line && line.compare("END")){
		vector<int> p;
		p.push_back(line.size());
		if(!line.compare("1")) cout << "1\n";
		else{
			do{
				int aux = p.back(), count = 0;
				while(aux/10){
					aux /= 10;
					count++;
				}
				if(aux > 0) count++;
				p.push_back(count);
			} while(p[p.size()-2] != p[p.size()-1]);
			cout << p.size() << endl;
		}
	}	
	return 0;
}
