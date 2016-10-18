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
	int n, a, b;
	bool run = true;
	string m, t;
	scanf("%d%*c", &n);
	int matrix[n][n];
	REP(i, n){
		REP(j, n){
			if(j) matrix[i][j] = -1;
			else matrix[i][j] = i;
		}
	}
	while(cin >> m && m.compare("quit")){
		int xa, ya, xb, yb;
		bool present = false;
		cin >> a >> t >> b;
		REP(i, n){
			REP(j, n){
				if(matrix[i][j] == a) {xa = i; ya = j;}
				else if(matrix[i][j] == b) {xb = i; yb = j;}
				else if(matrix[i][j] == -1) break;
			}
		}
		if(a != b && xa != xb){
			if(!m.compare("move")){
				for(int i = n-1; matrix[xa][i] != a; i--){
					if(matrix[xa][i] != -1) {
						REP(j, n) {
							if(matrix[matrix[xa][i]][j] == -1) {
								swap(matrix[matrix[xa][i]][j], matrix[xa][i]); 
								break;
							}
						}
					}
				}
				if(!t.compare("onto")){
					for(int i = n-1; matrix[xb][i] != b; i--){
						if(matrix[xb][i] != -1) {
							REP(j, n) {
								if(matrix[matrix[xb][i]][j] == -1) {
									swap(matrix[matrix[xb][i]][j], matrix[xb][i]); 
									break;
								}
							}
						}
					}
					swap(matrix[xb][yb+1], matrix[xa][ya]);
				} else if(!t.compare("over")){
					REP(i, n){
						if(matrix[xb][i] == -1) {
							swap(matrix[xb][i], matrix[xa][ya]);
							break;
						}
					}
				}
			} else if(!m.compare("pile")){
				if(!t.compare("onto")){
					for(int i = n-1; matrix[xb][i] != b; i--){
						if(matrix[xb][i] != -1) {
							REP(j, n) {
								if(matrix[matrix[xb][i]][j] == -1) {
									swap(matrix[matrix[xb][i]][j], matrix[xb][i]); 
									break;
								}
							}
						}
					}
					for(int i = ya; matrix[xa][i] != -1; i++)
						swap(matrix[xb][yb+1+(i-ya)], matrix[xa][i]);
				} else if(!t.compare("over")){
					REP(i, n) if(matrix[xb][i] == -1) {yb = i; break;}
					for(int i = ya; matrix[xa][i] != -1; i++)
						swap(matrix[xb][yb+(i-ya)], matrix[xa][i]);
				}
			}
		}
	}
	REP(i, n){
		printf("%d:", i);
		REP(j, n){
			if(matrix[i][j] != -1) printf(" %d", matrix[i][j]);
			else break;
		}
		cout << endl;
	}
  return 0;
}


