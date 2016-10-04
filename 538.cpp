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
	int n, t, money, indexG, indexR, caso = 1;
	while(cin >> n >> t && (n || t)){
		scanf("%*c");
		int matrix[n], sum = 0;
		REP(i, n) matrix[i] = 0;
		vector<string> vs;
		string giver, receiver; 
		REP(i, n) {
			cin >> giver;
			vs.pb(giver);
		}
		REP(i, t){
			cin >> giver >> receiver >> money;
			REP(j, n){
				if(!giver.compare(vs[j])) matrix[j] -= money;
				if(!receiver.compare(vs[j])) matrix[j] += money;
			}
		}
		printf("Case #%d\n", caso++);
		do{
			int delta = 500000;
			bool zero = true;
			indexG = -1; indexR = -1;
			REP(i, n) if(matrix[i] > 0) indexG = i;
			REP(i, n) {
				if(matrix[i] < 0){
					if(abs(matrix[indexG] - abs(matrix[i])) < delta){
						indexR = i;
						delta = abs(matrix[indexG] - abs(matrix[i]));
					}
				}
			}
			cout << vs[indexG] << " " << vs[indexR] << " ";
			if(matrix[indexG] >= abs(matrix[indexR])){
				printf("%d\n", abs(matrix[indexR]));
				matrix[indexG] += matrix[indexR];
				matrix[indexR] = 0;
			} else if(matrix[indexG] < abs(matrix[indexR])){
				printf("%d\n", abs(matrix[indexG]));
				matrix[indexR] += matrix[indexG];
				matrix[indexG] = 0;
			} 
			REP(i, n) if(matrix[i]) zero = false;
			if(zero) break;
		} while(1);
		cout << endl;
	}
  return 0;
}






