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
	int set = 1;
	string line;
	while(getline(cin, line)){
		int aux, size, sync = -1, sec[3601], M = 4000;
		REP(i, 3601) sec[i] = 0;
		vector<int> vi;
		stringstream ss;
		ss << line;
		while(ss >> aux) {
			vi.pb(aux);
			M = min(M, aux);
		}
		size = vi.size();
		REP(i, size)
			for(int j = 0; j < 3601; j += (2*vi[i]))
				for(int z = j; (z-j) < (vi[i]-5) && z < 3601; z++)  
					sec[z]++;
		
		FOR(i, M-4, 3601) {
			if(sec[i] == size){
				sync = i;
				break;
			}
		}
		if(sync == -1) printf("Set %d is unable to synch after one hour.\n", set++);
		else printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", set++, sync/60, sync % 60);
	}
  return 0;
}










