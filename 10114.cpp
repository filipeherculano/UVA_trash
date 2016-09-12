#include <bits/stdc++.h>

using namespace std;

int main(){
	int mon, dep;
	double loan, down;
	while(cin >> mon >> down >> loan >> dep && mon > 0){
		int index;
		double temp, actualLoan = loan, carValue = loan+down, p, payoff = loan / (double)mon;
		map<int, double> depMon;
		map<int, double>::iterator it;
		for(int i = 0; i < dep; i++){
			cin >> index >> temp;
			depMon.insert(std::pair<int, double>(index, (1.0 - temp)));
		}
		for(index = 0; index <= mon ; index++){
			it = depMon.find(index);
			if(it != depMon.end()) p = it->second;
			if(index) actualLoan -= payoff;
			carValue *= p;
			if(actualLoan < carValue) break;
		}
		printf("%d %s\n", index, index == 1 ? "month" : "months");
	}
	return 0;
}
