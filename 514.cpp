#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int aux;
		do{
			stack<int> ini;
			queue<int> fin;
			for(int i = 0; i < n; i++){
				cin >> aux;
				if(!aux) break;
				fin.push(aux);		
			}
			if(aux){
				for(int i = 1; i <= n; i++){
					ini.push(i);
					while(!fin.empty() && !ini.empty() && fin.front() == ini.top()){
						fin.pop();
						ini.pop();
					}
				}
				printf("%s\n", fin.empty() ? "Yes" : "No");
			}
		} while(aux);
		cout << endl;
	}
	return 0;
}
