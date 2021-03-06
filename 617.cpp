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

bool pass(int i, vector< tuple<double,int,int,int,int> > vp){
	vector< tuple<double,int,int,int,int> >::iterator it;
	for(it = vp.begin(); it != vp.end(); it++){
		double dt = (get<0>(*it)*3600)/i;
		if(fmod(dt, get<4>(*it)) > (get<1>(*it)+get<2>(*it))) {
			return false;
		}
	}
	return true;
}

int main(){
	string line;
	int n, caso = 1;
	while(scanf("%d", &n) && n != -1){
		int g, y, r;
		double l;
		vector< tuple<double,int,int,int,int> > vp;
		vector<int> acc;
		REP(i,n){
			scanf("%lf %d %d %d", &l, &g, &y, &r);
			tuple<double,int,int,int,int> aux;
			get<0>(aux) = l;
			get<1>(aux) = g; get<2>(aux) = y;
			get<3>(aux) = r; get<4>(aux) = (g+y+r);
			vp.pb(aux);
		}
		getline(cin, line);
		for(int i = 30; i <= 60; i++)
			if(pass(i, vp))
				acc.pb(i);		
				
		printf("Case %d:", caso++);
		
		if(acc.size()){
			int pt1 = 0, pt2 = 0;
			while(pt1 < acc.size()){
				while(pt2 != acc.size()-1 && abs(acc[pt2]-acc[pt2+1]) == 1) pt2++;
				if(pt1 == pt2) printf("%s%d",  pt1 == 0 ? " ":", ", acc[pt1]);
				else printf("%s%d-%d", pt1 == 0 ? " ":", " , acc[pt1], acc[pt2]);
				pt1 = pt2+1; pt2++;
			}
		} else printf(" No acceptable speeds.");
		cout << endl;
	}
  return 0;
}












