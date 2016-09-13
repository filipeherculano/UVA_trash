#include <bits/stdc++.h>

using namespace std;

int main(){
	bool isFirst = true;
	int n, p, rfp = 1;
	while(cin >> n >> p && (n || p)){
		if(!isFirst) cout << endl;
		isFirst = false;
		double d, max = 0.0;
		int r, index;
		scanf("%*c");
		string prop[p], aux;
		vector< pair<double, double> > v;
		for(int i = 0; i < n; i++)
			getline(cin, aux);

		for(int i = 0; i < p; i++){
			getline(cin, prop[i]);
			scanf("%lf %d%*c", &d, &r);
			v.push_back(std::pair<double, double>(d, (double)r/(double)n));
			if(max < v[i].second) {
				max = v[i].second;
				index = i;
			}
			for(int j = 0; j < r; j++)
				getline(cin, aux);
		}
		for(int i = 0; i < p; i++)
			if(v[i].second == max && index != i && v[i].first < v[index].first)
				index = i;
		printf("RFP #%d\n", rfp++);
		cout << prop[index] << endl;
	}			
	return 0;
}
