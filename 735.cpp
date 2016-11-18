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
	int points;
	set<int> score;
	set<int>::iterator it, jit, zit;
	REP(i, 21){
		score.insert(i);
		score.insert(i*2);
		score.insert(i*3);
	}
	score.insert(50);
	while(scanf("%d", &points) && points > 0){
		set< vector<int> > svi;
		int perm = 0;
		for(it = score.begin(); it != score.end(); it++){
			for(jit = score.begin(); jit != score.end(); jit++){
				for(zit = score.begin(); zit != score.end(); zit++){
					if(*it + *zit + *jit == points){
						vector<int> vi;
						vi.pb(*it); vi.pb(*jit); vi.pb(*zit);
						sort(all(vi));
						svi.insert(vi);
						perm++;
					}
				}
			}
		}
		if(svi.size()){
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %lu.\n", points, svi.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", points, perm);
		} else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", points);
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
  return 0;
}
