#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;
map<string, int> cards;

int HC(string hand[]){
	int v[14] = {0}, res = 0, offset = 10000;
	for(int i = 0; i < 5; i++)
		v[cards[hand[i]]]++;
	for(int i = 13; i >= 0; i--){
		if(v[i]) {
			res += v[i]*i*offset;
			offset /= 10;
		}
	}
	return res;
}

int SF(string hand[]){
	int res = -1;
	if(hand[0][1] == hand[1][1] && 
			hand[1][1] == hand[2][1] && 
			hand[2][1] == hand[3][1] && 
			hand[3][1] == hand[4][1]){
		vector<int> v;
		for(int i = 0; i < 5; i++)
			v.push_back(cards[hand[i]]);
		sort(v.begin(), v.end());
		bool ok = true;
		for(int i = 0; i < 4; i++)
			if((v[i]+1) != v[i+1]) ok = false;
		if(ok) res = v[4];
	}
	return res;
}
int FK(string hand[]){
	int res = -1, v[14] = {0};
	for(int i = 0; i < 5; i++)
		v[cards[hand[i]]]++;
	for(int i = 0; i < 14; i++)
		if(v[i] == 4) res = i;
	return res;
}

int FH(string hand[]){
	bool valid = false;
	int res = -1, v[14] = {0}, index;
	for(int i = 0; i < 5; i++)
		v[cards[hand[i]]]++;
	for(int i = 0; i < 14; i++){
		if(v[i] == 3) {
			valid = true;
			index = i;
		}
	}	
	if(valid)
		for(int i = 0; i < 14; i++)	
			if(v[i] == 2) res = index;
	return res;
}

int F(string hand[]){
	int res = -1;
	if(hand[0][1] == hand[1][1] &&
			hand[1][1] == hand[2][1] &&
			hand[2][1] == hand[3][1] &&
			hand[3][1] == hand[4][1]){
		res = HC(hand);
	}
	return res;
}

int S(string hand[]){
	int res = -1;
	vector<int> v;
	bool ok = true;
	for(int i = 0; i < 5; i++)
		v.push_back(cards[hand[i]]);
	sort(v.begin(), v.end());
	for(int i = 0; i < 4; i++)
		if((v[i]+1) != v[i+1]) ok = false;
	if(ok) res = HC(hand);
	return res;
}

int TK(string hand[]){
	int res = -1, v[14] = {0};
	for(int i = 0; i < 5; i++)
		v[cards[hand[i]]]++;
	for(int i = 0; i < 14; i++)
		if(v[i] == 3) res = i;
	return res;
}

int TP(string hand[]){
	int res = -1, v[14] = {0}, two = 0;
	for(int i = 0; i < 5; i++)
		v[cards[hand[i]]]++;
	for(int i = 0; i < 14; i++)
		if(v[i] == 2) two++;
	if(two == 2){
		res = 0;
		int offset = 100;
		for(int i = 13; i >= 0; i--){
			if(v[i] == 2){
				res += 2*i*offset;
				offset /= 10;
			}
		}
		for(int i = 13; i >= 0; i--)
			if(v[i] == 1)
				res += i*offset;
	}
	return res;
}

int P(string hand[]){
	int res = -1, v[14] = {0}, offset = 1000;
	bool ok = false;
	for(int i = 0; i < 5; i++)
		v[cards[hand[i]]]++;
	for(int i = 13; i >= 0; i--){
		if(v[i] == 2){
			res = 2*i*offset;
			ok = true;
			offset /= 10;
		}
	}
	if(ok){
		for(int i = 13; i >= 0; i--){
			if(v[i] == 1){
				res += i*offset;
				offset /= 10;
			}
		}
	}
	return res;
}

void winner(int t, int b, int w){
	if(b > w) printf("Black wins.\n");
	else if(b < w) printf("White wins.\n");
	else if(b == w) printf("Tie.\n");
}

int main(){
	string c;
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
	cards["AD"] = 13; cards["AH"] = 13; cards["AS"] = 13; cards["AC"] = 13;
	while(cin >> c){
		string black[5], white[5];
		int bscore, wscore;
		black[0] = c;
		for(int i = 1; i < 5; i++) cin >> black[i];
		for(int i = 0; i < 5; i++) cin >> white[i];
		bscore = SF(black); wscore = SF(white);//straight flush
		if(bscore == -1 && wscore == -1){
			bscore = FK(black); wscore = FK(white);//four of a kind
			if(bscore == -1 && wscore == -1){
				bscore = FH(black); wscore = FH(white);//full house
				if(bscore == -1 && wscore == -1){
					bscore = F(black); wscore = F(white);//flush
					if(bscore == -1 && wscore == -1){
						bscore = S(black); wscore = S(white);//straight
						if(bscore == -1 && wscore == -1){
							bscore = TK(black); wscore = TK(white);//three of a kind
							if(bscore == -1 && wscore == -1){
								bscore = TP(black); wscore = TP(white);//Two pairs
								if(bscore == -1 && wscore == -1){
									bscore = P(black); wscore = P(white);//Pairs
									if(bscore == -1 && wscore == -1){
										bscore = HC(black); wscore = HC(white);
										winner(bscore, wscore);
									} else winner(bscore, wscore);
								} else winner(bscore, wscore);
							} else winner(bscore, wscore);
						} else winner(bscore, wscore);
					} else winner(bscore, wscore);
				} else winner(bscore, wscore);
			} else winner(bscore, wscore);
		} else winner(bscore, wscore);
	}
	return 0;
}




