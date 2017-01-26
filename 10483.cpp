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
const double EPS = 1e-9;

using namespace std;

bool cmp(tuple<double,double,double,double> i, tuple<double,double,double,double> j){
	if(get<0>(i) == get<0>(j)){
		if(get<1>(i) == get<1>(j)){
			if(get<2>(i) == get<2>(j)) return get<3>(i) < get<3>(j);
			else return get<2>(i) < get<2>(j);
		} else return get<1>(i) < get<1>(j);
	} else return get<0>(i) < get<0>(j);
}

int main(){
  double start, end;
  while(~scanf("%lf %lf", &start, &end)){
    vector< tuple<double,double,double,double> > vt;
    for(int a = 1; 3*a <= end*100; a++){
      for(int b = a; a + 2*b <= end*100; b++){
        int p = a*b, s = a+b;
  
        if(p > 10000){
          ll c = (10000)*s / (p - 10000);

          if(c < b || c + s > end*100 || c + s < start*100) continue;
          
          if(fabs(((a+b+c)/100.0)-((a*b*c)/1000000.0)) < EPS)
            vt.pb(make_tuple((c + s)/100.0, a/100.0, b/100.0, c/100.0));
        } else continue;
      }
    }
    sort(all(vt), cmp);
    REP(i, vt.size()){
      printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",
        get<0>(vt[i]), get<1>(vt[i]), get<2>(vt[i]), get<3>(vt[i]), get<1>(vt[i]), get<2>(vt[i]), get<3>(vt[i]));
    }
  }
  return 0;
}
