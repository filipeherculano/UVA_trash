#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef std::vector<int> vi;
typedef std::vector< std::pair<int,int> > vii;
typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int aux, n, start, end;
	vi dies;
	while(cin >> aux && aux) dies.push_back(aux);
	while(cin >> n && n){
		bool found = false;
		int v[n], board[101], play[n], index = 0;
		memset(v, 0, sizeof(int)*n);
		FOR(i, 101) board[i] = -1;
		FOR(i, n) play[i] = 1;
		while(cin >> start >> end && (start || end)) board[start] = end;
		while(cin >> aux && aux){
			if(aux < 0) board[0-aux] = -2; // lose turn
			else if(aux > 0) board[aux] = -3; // extra turn
		}
		for(int i = 0; i < dies.size() && !found; i++){
			if(play[index] == 1){
				if(v[index] + dies[i] <= 100) {
					v[index] += dies[i];
					if(board[v[index]] == -2) play[index] = 0;
					else if(board[v[index]] >= 0) v[index] = board[v[index]];
					else if(v[index] == 100) {
						found = true;
						cout << index + 1 << endl;
					}
				}
			} else if(play[index] == 0) play[index] = 1;
			if(board[v[index]] != -3) index = (index + 1) % n;
		}
  }
  return 0;
}




