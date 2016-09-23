#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line;
	while(getline(cin, line) && line.compare("DONE")){
		string curr;
		bool ok = true;
		FOR(i, line.size()) {
			if((line[i] >= 'a' && line[i] <= 'z')) 
				curr.push_back(line[i]); 
			else if(line[i] >= 'A' && line[i] <= 'Z')
				curr.push_back(line[i]+32);
		}
		int i = 0, j = curr.size()-1;
		while(i < j){
			if(curr[i] != curr[j]) ok = false;
			i++; j--;
		}
		if(ok) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}
  return 0;
}
