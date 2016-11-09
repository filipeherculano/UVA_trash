#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;

using namespace std;

bool cmp(pair<string,int> i, pair<string,int> j){
	if(i.second == j.second) return i.first < j.first;
	else return i.second < j.second;
}

int main(){
	int v[9];
	while(~scanf("%d %d %d %d %d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6], &v[7], &v[8])){
		string res;
		char c[] = {'B','G','C'};
		int perm[] = {0,1,2};
		int sum[3] = {0,0,0};
		vector< pair<string,int> > vsi;
		REP(i, 9) {
			if(i < 3) sum[0] += v[i];
			else if(i < 6) sum[1] += v[i];
			else sum[2] += v[i];
		}
		do{
			int tot = (sum[0]-v[perm[0]])+(sum[1]-v[3+perm[1]])+(sum[2]-v[6+perm[2]]);
			res.clear();
			res.pb(c[perm[0]]); res.pb(c[perm[1]]); res.pb(c[perm[2]]);
			vsi.pb(make_pair(res,tot));
		} while(next_permutation(perm, perm+3));
		sort(all(vsi), cmp);
		cout << vsi[0].first << " " << vsi[0].second << endl;
  }
  return 0;
}
