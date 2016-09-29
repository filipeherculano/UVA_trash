#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
	string line;
	map<string, int> cards;
	cards["2D"] = 1; cards["2H"] = 1; cards["2S"] = 1; cards["2C"] = 1;
	cards["3D"] = 2; cards["3H"] = 2; cards["3S"] = 2; cards["3C"] = 2;
	cards["4D"] = 3; cards["4H"] = 3; cards["4S"] = 3; cards["4C"] = 3;
	cards["5D"] = 4; cards["5H"] = 4; cards["5S"] = 4; cards["5C"] = 4;
	cards["6D"] = 5; cards["6H"] = 5; cards["6S"] = 5; cards["6C"] = 5;
	cards["7D"] = 6; cards["7H"] = 6; cards["7S"] = 6; cards["7C"] = 6;
	cards["8D"] = 7; cards["8H"] = 7; cards["8S"] = 7; cards["8C"] = 7;
	cards["9D"] = 8; cards["9H"] = 8; cards["9S"] = 8; cards["9C"] = 8;
	cards["TD"] = 9; cards["TH"] = 9; cards["TS"] = 9; cards["TC"] = 9;
	cards["JD"] = 10; cards["JH"] = 10; cards["JS"] = 10; cards["JC"] = 10;
	cards["QD"] = 11; cards["QH"] = 11; cards["QS"] = 11; cards["QC"] = 11;
	cards["KD"] = 12; cards["KH"] = 12; cards["KS"] = 12; cards["KC"] = 12;
	cards["AD"] = 0; cards["AH"] = 0; cards["AS"] = 0; cards["AC"] = 0;
	while(cin >> line && line[0] != '#'){
		string curr;
		queue<string> qs[13];
		int i = 11, count = 0;
		qs[12].push(line);
		FOR(j, 51){
			cin >> line;
			qs[i].push(line);
			i--;
			if(i < 0) i = 12;
		}
		i = 12;
		while(!qs[i].empty()){
			curr = qs[i].front();
			qs[i].pop();
			i = cards[curr];
			count++;
		}
		if(count < 10) printf("0");
		printf("%d,", count);
		cout << curr << endl;
	}
  return 0;
}
