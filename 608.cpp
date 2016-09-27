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
		string left, right, res;
		int v[12] = {0};
		FOR(z, 3){
			cin >> left >> right >> res;
			if(!res.compare("even")){
				FOR(i, left.size()) v[left[i]-'A'] = -10;
				FOR(i, right.size()) v[right[i]-'A'] = -10;
			} else if(!res.compare("up")){
				FOR(i, left.size())
					if(v[left[i]-'A'] != -10) 
						v[left[i]-'A']--;
				FOR(i, right.size())
					if(v[right[i]-'A'] != -10) 
						v[right[i]-'A']++;
			} else if(!res.compare("down")){
				FOR(i, left.size())
					if(v[left[i]-'A'] != -10) 
						v[left[i]-'A']++;
				FOR(i, right.size())
					if(v[right[i]-'A'] != -10) 
						v[right[i]-'A']--;
			}
		}
		bool found = false;
		FOR(i, 12) {
			if(v[i] == 3){
				printf("%c is the counterfeit coin and it is light.\n", (char)(i+'A'));
				found = true;
				break;
			}
		}
		if(!found){
			FOR(i, 12) {
				if(v[i] == -3){
					printf("%c is the counterfeit coin and it is heavy.\n", (char)(i+'A'));
					found = true;
					break;
				}
			}
		}
		if(!found){
			FOR(i, 12) {
				if(v[i] == 2){
					printf("%c is the counterfeit coin and it is light.\n", (char)(i+'A'));
					found = true;
					break;
				}
			}
		}
		if(!found){
			FOR(i, 12) {
				if(v[i] == -2){
					printf("%c is the counterfeit coin and it is heavy.\n", (char)(i+'A'));
					found = true;
					break;
				}
			}
		}
		if(!found){
			FOR(i, 12) {
				if(v[i] == 1){
					printf("%c is the counterfeit coin and it is light.\n", (char)(i+'A'));
					found = true;
					break;
				}
			}
		}
		if(!found){
			FOR(i, 12) {
				if(v[i] == -1){
					printf("%c is the counterfeit coin and it is heavy.\n", (char)(i+'A'));
					found = true;
					break;
				}
			}
		}
		if(!found){
			FOR(i, 12) {
				if(v[i] == 0){
					printf("%c is the counterfeit coin and it is heavy.\n", (char)(i+'A'));
					break;
				}
			}
		}
	}
  return 0;
}



