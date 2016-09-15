#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int n, upper = 10, lower = 1;
	while(cin >> n && n){
		scanf("%*c");
		string ans;
		getline(cin, ans);
		//cout << upper << " " << lower << " " << n  << " " << ans<< endl;
		if(!ans.compare("too high")){
			if(upper >= n) upper = n-1;
		} else if(!ans.compare("too low")) {
			if(lower <= n)lower = n+1;
		} else if(!ans.compare("right on")){
			if(upper < lower) cout << "Stan is dishonest\n";
			else if(n >= lower && n <= upper) cout << "Stan may be honest\n";
			else cout << "Stan is dishonest\n";
			upper = 10; lower = 1;
			continue; 
		}
	}
	return 0;
}
