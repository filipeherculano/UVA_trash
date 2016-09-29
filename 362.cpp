#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int ds = 1;
	long double bytes;
	while(cin >> bytes && bytes){
		printf("Output for data set %d, %d bytes:\n", ds++, (int)bytes);
		long double sum = 0.0, aux;
		int i = 0;
		vector<long double> bpersec;
		while(bytes) {
			i++;
			cin >> aux;
			sum += aux;
			bytes -= aux;
			if(!(i%5)){
				printf("   Time remaining: ");
				if(sum != 0.0) printf("%d seconds\n", (int)ceil((bytes * 5.0)/sum));
				else printf("stalled\n");
				sum = 0.0;
			}
		}
		printf("Total time: %d seconds\n\n", i);
	}
  return 0;
}



