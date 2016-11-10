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

int cnt;

void merge(int s[], int e[], int i, int j, int size){
	if(i == j) return;
	
	merge(s, e, i, (i+j)/2, size);
	merge(s, e, (1+(i+j)/2), j, size);
	
	vector<int> a, b;
	for(int z = i; z < (1+(i+j)/2); z++) a.pb(s[z]);
	for(int z = (1+(i+j)/2); z <= j; z++) b.pb(s[z]);
	
	for(int tl = 0, tr = 0, index = 0; tl < a.size() && tr < b.size();){
		if(e[index] == a[tl]) tl++;
		else if(e[index] == b[tr]){
			int left, right;
			REP(z, size) if(a[tl] == s[z]) left = z;
			REP(z, size) if(b[tr] == s[z]) right = z;
			for(int k = right; k > left; k--){
				swap(s[k], s[k-1]);
				cnt++;
			}
			tr++;
		}
		index++;
	}
}

int main(){
	int n;
	while(~scanf("%d", &n)){
		int s[n], e[n];
		cnt = 0;
		REP(i,n) scanf("%d", &s[i]);
		REP(i,n) scanf("%d", &e[i]);
		merge(s, e, 0, n-1, n);
		printf("%d\n", cnt);
	}
  return 0;
}
