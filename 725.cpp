#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

bool isOk(int i){
	vector<int> bucket(10, 0);
	string num = to_string(i);
	REP(j, num.size()){
		if(bucket[num[j]-'0']) return false;
		else bucket[num[j]-'0']++;
	}
	return true;
}

bool both(int i, int j){
	vector<int> bucket(10, 0);
	string I = to_string(i), J = to_string(j);
	if(i >= 1234 && i <= 9999) bucket[0]++;
	if(j >= 1234 && j <= 9999) {
		if(bucket[0]) return false;
		else bucket[0]++;
	}
	REP(z, I.size()){
		if(bucket[I[z]-'0']) return false;
		else bucket[I[z]-'0']++;
	}
	REP(z, J.size()){
		if(bucket[J[z]-'0']) return false;
		else bucket[J[z]-'0']++;
	}
	return true;
}

int main(){
	int n;
	bool isfirst = true;
	vector<int> values;
	FOR(i, 1234, 98766){
		bool ok = isOk(i);
		if(ok) values.pb(i);
	}
	while(cin >> n && n){
		if(!isfirst) cout << endl;
		isfirst = false;
		bool has = false;
		for(int i = 0; i < values.size()-1; i++){
			int temp = values[i]*n;
			if(temp > 98765) break;
			if(both(values[i], temp)){
				printf("%05d / %05d = %d\n", temp, values[i], n);
				has = true;
			}
		}
		if(!has) printf("There are no solutions for %d.\n", n);
	}
  return 0;
}
