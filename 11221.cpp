#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n, v[101], caso = 1;
	string line;
	scanf("%d%*c", &n);
	FOR(i, 101) v[i] = i*i;
	while(n--){
			string temp;
			getline(cin, line);
			FOR(i, line.size())
				if(line[i] >= 'a' && line[i] <= 'z')temp.push_back(line[i]);
			int i = 0, j = temp.size()-1, index = -1;
			bool ok = true;
			while(i < j){ // test if is palindrome
				if(temp[i] != temp[j]) ok = false;
				i++; j--;
			}
			if(ok){ // test if is a perfect square
				FOR(i, 101) {
					if(v[i] == temp.size()) index = i;
					if(i == 100 && index == -1)	ok = false;
				}
			}
			
			if(ok) printf("Case #%d:\n%d\n", caso++, index);
			else printf("Case #%d:\nNo magic :(\n", caso++);
	}
  return 0;
}






