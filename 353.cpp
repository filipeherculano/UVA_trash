#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

bool isPal(string line){
	int i = 0, j = line.size()-1;
	bool ok = true;
	while(i < j){
		if(line[i] != line[j]) ok = false;
		i++; j--;
	}
	return ok;
}

int main(){
	string line;
	while(getline(cin, line)){
		set<string> ss;
		int count = 0;
		for(int offset = 0; offset < line.size(); offset++){
			for(int i = 0; i < line.size() - offset; i++){
				char v[offset+2];
				line.copy(v, offset+2, i);
				v[offset+1] = '\0';
				string temp(v);
				if(isPal(temp)) ss.insert(temp);
			}
		}
		cout << "The string '" << line << "' contains " << ss.size() << " palindromes." << endl;
	}
  return 0;
}
