#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int t, caso = 1;
	cin >> t;
	while(t--){
		int d1, m1, a1, d2, m2, a2, age = 0;
		scanf("%*c");
		scanf("%d/%d/%d", &d1, &m1, &a1); // current
		scanf("%d/%d/%d", &d2, &m2, &a2); // birth
		printf("Case #%d: ", caso++);
		if(a2 < a1){
			if(m2 < m1) age = a1-a2;
			else if(m2 == m1){
				if(d2 <= d1) age = a1-a2;
				else age = a1-a2-1;
			} else age = a1-a2-1;
		} else if(a2 == a1){
			if(m2 == m1){
				if(d2 > d1) age = -1;
			} else if(m2 > m1) age = -1;
		} else age = -1;
		
		if(age == -1) printf("Invalid birth date\n");
		else if(age > 130) printf("Check birth date\n");
		else  printf("%d\n", age);
	}
  return 0;
}
