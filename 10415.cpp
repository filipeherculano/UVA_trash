#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	int t;
	int matrix[14][10] = {0,1,1,0,0,0,0,0,0,0,					
												0,1,0,0,0,0,0,0,0,0,
												0,1,1,1,0,0,1,1,1,1,
												0,1,1,1,0,0,1,1,1,0,
												0,1,1,1,0,0,1,1,0,0,
												0,1,1,1,0,0,1,0,0,0,
												0,1,1,1,0,0,0,0,0,0,
												1,1,1,0,0,0,0,0,0,0,				
												1,1,0,0,0,0,0,0,0,0,
												0,0,1,0,0,0,0,0,0,0,
												1,1,1,1,0,0,1,1,1,0,
												1,1,1,1,0,0,1,1,0,0,
												1,1,1,1,0,0,1,0,0,0,
												1,1,1,1,0,0,0,0,0,0};
	
	string line;
	scanf("%d%*c", &t);
	while(t--){
		int v[10] = {0}, p[10] = {0};
		getline(cin, line);
		FOR(i, line.size()){
			int temp = (int)line[i];
			if(temp >= 97) temp -= 97;
			else temp -= 58;
			if(i){ 
				FOR(i, 10) if(!p[i] && matrix[temp][i]) v[i]++;
			} else FOR(i, 10) v[i] += matrix[temp][i];
			FOR(i, 10) p[i] = matrix[temp][i];
		}
		FOR(i, 10) printf("%d%c", v[i], i == 9 ? '\n':' ');
	}
  return 0;
}
