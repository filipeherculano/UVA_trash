#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n;
	scanf("%d%*c", &n);
	while(n--){
		string line;
		cin >> line;
		ll count = 0;
		bool ok = false;
		while(!ok){
			int i = 0, j = line.size()-1;
			while(i < j){
				if(line[i] != line[j]) break;
				i++; j--;
			}
			if(i >= j) ok = true;
			else{
				i = 0; j = line.size()-1; count++;
				ll temp = stoll(line);
				while(i < j) swap(line[i++], line[j--]);
				temp += stoll(line);
				string rev = to_string(temp);
				line.swap(rev);
			}
		}
		cout << count << " " << line << endl;
	}
  return 0;
}
