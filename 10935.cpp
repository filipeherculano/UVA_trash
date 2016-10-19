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
    int n, i;
    while(scanf("%d", &n) && n){
        int v[n+n], head = n, discard[n-1], index = 0;
        for(i = 0; i < n; i++) v[i] = i+1;
        i = 0;
        while(head <= n+n && n > 1){
            v[head] = v[i+1];
            discard[index] = v[i];
            index++;
            i+=2;
            head++;
        }
        printf("Discarded cards:");
        if(n > 1) printf(" %d", discard[0]);
        for(i = 1; i < n-1; i++) printf(", %d", discard[i]);
        printf("\n");
        printf("Remaining card: %d\n", v[n+n-2]);
    }
    return 0;
}
