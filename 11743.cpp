#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int DS(int a){
	while(a >= 10){
		int sum = 0;
		while(a){
			sum += (a % 10);
			a /= 10;
		}
		a = sum;
	}
	return a;
}

int main(){
	string line;
	int n;
	scanf("%d%*c", &n);
	while(n--){
		int sum = 0;
		vector<int> vi;
		getline(cin, line);
		FOR(i, line.size()) if(line[i] != ' ') vi.push_back(line[i]-'0');
		FOR(i, vi.size()) if(!(i&1)) vi[i] *= 2;
		FOR(i, vi.size()) sum += DS(vi[i]);
		printf("%s\n", sum % 10 ? "Invalid":"Valid"); 
	}
  return 0;
}
