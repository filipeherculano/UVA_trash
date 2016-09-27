#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n;
	vector< pair<string, bool> > vs;
  FOR(i, 24){
  	FOR(j, 60){
  		bool ok = true;
  		string total, aux, pal;
  		if(i < 10) total.push_back('0');
  		aux = to_string(i);
  		total.append(aux);
  		total.push_back(':');
  		if(j < 10) total.push_back('0');
  		aux = to_string(j);
  		total.append(aux);
  		int z = 0, k = total.size()-1;
  		while(z != total.size()-1 && (total[z] == '0' || total[z] == ':'))
  			z++;
  			
  		while(z <= k){
  			if(total[z] == ':') z++;
  			if(z <= k){
  				if(total[z] != total[k]) ok = false;
  			}
  			z++; k--;
  		}
  		vs.push_back(std::pair<string, bool>(total, ok));
  	}
  }
  scanf("%d%*c", &n);
  while(n--){
  	int index = 0;
  	string line;
  	cin >> line;
  	FOR(i, vs.size()){
  		if(!line.compare(vs[i].first)){
  			index = i;
  			break;
  		}
  	}
  	do{
  		index = (index+1) % vs.size();
  	}while(!vs[index].second);
  	cout << vs[index].first << endl;
  }
  return 0;
}







