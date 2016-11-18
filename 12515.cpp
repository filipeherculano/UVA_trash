#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	int m, q, index, least = INF;
	scanf("%d %d%*c", &m, &q);
	vector<string> movie(m), clip(q);
	REP(i, m) getline(cin, movie[i]);
	REP(i, q) getline(cin, clip[i]);
	
	REP(i, q){
		int index, least = INF;
		REP(j, m){
			int temp = INF;
			if(movie[j].size() < clip[i].size()) continue;
			for(int k = 0; k <= movie[j].size()-clip[i].size() ; k++){
				int hd = 0;
				for(int z = 0; z < clip[i].size(); z++){
					int a = movie[j][z+k]-'0', b = clip[i][z]-'0';
					hd += a == b ? 0:1;
				}
				temp = min(temp, hd);
			}
			if(least > temp){
				least = temp;
				index = j+1;
			}
		}
		cout << index << endl;
	}
  return 0;
}
