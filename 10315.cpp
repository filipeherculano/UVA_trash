#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;


int main(){
	string c;
	map<string, int> cards;
	cards["2D"] = 0; cards["2H"] = 0; cards["2S"] = 0; cards["2C"] = 0;
	cards["3D"] = 1; cards["3H"] = 1; cards["3S"] = 1; cards["2C"] = 1;
	cards["4D"] = 2; cards["4H"] = 2; cards["4S"] = 2; cards["2C"] = 2;
	cards["5D"] = 3; cards["5H"] = 3; cards["5S"] = 3; cards["2C"] = 3;
	cards["6D"] = 4; cards["6H"] = 4; cards["6S"] = 4; cards["2C"] = 4;
	cards["7D"] = 5; cards["7H"] = 5; cards["7S"] = 5; cards["2C"] = 5;
	cards["8D"] = 6; cards["8H"] = 6; cards["8S"] = 6; cards["2C"] = 6;
	cards["9D"] = 7; cards["9H"] = 7; cards["9S"] = 7; cards["2C"] = 7;
	cards["TD"] = 8; cards["TH"] = 8; cards["TS"] = 8; cards["2C"] = 8;
	cards["JD"] = 9; cards["JH"] = 9; cards["JS"] = 9; cards["2C"] = 9;
	cards["QD"] = 10; cards["QH"] = 10; cards["QS"] = 10; cards["2C"] = 10;
	cards["KD"] = 11; cards["KH"] = 11; cards["KS"] = 11; cards["2C"] = 11;
	cards["AD"] = 12; cards["AH"] = 12; cards["AS"] = 12; cards["2C"] = 12;
	while(cin >> c){
		string black[5], white[5];
		bool ST, FK, FH, F, S, TK, TP, P, HC;
		ST = FK = FH = F = S = TK = TP = P = HC = true;
		black[0] = c;
		for(int i = 1; i < 5; i++)
			cin >> black[i];
		for(int i = 0; i < 5; i++)
			cin >> white[i];
		for(int i = 0; i < 5; i++){
			
		}
		for(int i = 0; i < 5; i++)
	}
	return 0;
}




