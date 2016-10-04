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
	int s, b, l, r;
	while(scanf("%d %d", &s, &b) && (s || b)){
		set<int> soldiers;
		set<int>::iterator fir = soldiers.begin(), sec;
		for(int i = 1; i <= s; i++)
			soldiers.insert(fir, i);	// O(1)	

		for(int i = 0; i < b; i++){
			scanf("%d %d", &l, &r);
			fir = soldiers.find(l);		// O(log n)
			sec = soldiers.find(r);		// O(log n)
			sec++;
			if(fir == soldiers.begin()) printf("* ");
			else {
			  fir--;
			  int temp = *fir;
			  printf("%d ", temp);
			  fir++;
			}
			if(sec == soldiers.end()) printf("*\n");
			else {
				int temp = *sec;
				printf("%d\n", temp);
			}
			soldiers.erase(fir, sec);	// O(n)
		}
		printf("-\n");
	}
	return 0;
}
