#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;


int mat[3][3];
		
void change(){
	int temp[3][3];
	REP(i, 3){
		REP(j, 3){
			int sum = 0;
			if(i) sum += mat[i-1][j];
			if(i != 2) sum += mat[i+1][j];
			if(j) sum += mat[i][j-1];
			if(j != 2) sum += mat[i][j+1];
			temp[i][j] = sum % 2;
		}
	}
	REP(i, 3) REP(j, 3) mat[i][j] = temp[i][j];
}
		
bool isFinite(){
	int sum = 0;
	REP(i, 3) REP(j, 3) sum += mat[i][j];
	return sum;
}

int main(){
	int t;
	scanf("%d%*c", &t);
	while(t--){
		int index = -1;
		string line;
		REP(i, 3) {
			cin >> line;
			REP(j, line.size()) mat[i][j] = line[j] - '0';
		}
		while(isFinite()){
			change();
			index++;
		}
		cout << index << endl;
	}
  return 0;
}





