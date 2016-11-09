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
  int t, n, iq;
  int result;

  cin >> t;

  while (t--) {
    int best = -1000000000;
    result = -1000000000;

    cin >> n;

    while (n--) {
      cin >> iq;

      if (best - iq > result)
        result = best - iq;

      if (iq > best)
        best = iq;
    }

    cout << result << endl;
}
  return 0;
}










