#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define offset 600

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int s, day = 1;
	while(cin >> s){
		string line;
		int h1, h2, m1, m2, M = -1;
		int start, end;
		int count = 0;
		vector<int> vi;
		vector<int>::iterator it;
		FOR(i, 481) vi.push_back(i);
		FOR(i, s){
			bool found = false;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			getline(cin, line);
			start = (h1*60) + m1;
			end = (h2*60) + m2; 
			start -= offset;
			end -= offset;
			for(it = vi.begin(); it != vi.end(); it++){
				if(!found){
					if(*it == start) found = true;
					else if(*it > start){
						if(*it > end) break;
						else found = true;
					}
				}
				
				if(found){
					if(*it >= end) break;
					vi.erase(it);
					if(!found) break;
					it--;
				}
			}
		}
		//FOR(i, vi.size()) cout << vi[i] << " ";
		//cout << endl;
		FOR(i, vi.size()-1){ // LIS
			if(!count) end = i;
			if(vi[i] + 1 == vi[i+1]) {
				count++;
				if(i == vi.size()-2) {
					if(count > M){
						M = count;
						start = vi[end];
					}
				}
			} else {
				count++;
				if(count > M){
					M = count;
					start = vi[end];
				}
				count = 0;
			}
		}
		printf("Day #%d: the longest nap starts at %d:", day++, (start+offset)/60);
		if(((start+offset) % 60) < 10) printf("0");
		printf("%d and will last for ", ((start+offset) % 60));
		if(M >= 60) printf("%d hours and ", M/60);
		printf("%d minutes.\n", M % 60);
	}
  return 0;
}



