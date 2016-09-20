#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;


int main(){
	bool isFirst = true;
	int n;
	map<int, string> cards;
	cards[1] = "2 of Clubs"; 			cards[14] = "2 of Diamonds"; 			cards[27] = "2 of Hearts"; 			cards[40] = "2 of Spades";
	cards[2] = "3 of Clubs"; 			cards[15] = "3 of Diamonds"; 			cards[28] = "3 of Hearts"; 			cards[41] = "3 of Spades";
	cards[3] = "4 of Clubs"; 			cards[16] = "4 of Diamonds"; 			cards[29] = "4 of Hearts"; 			cards[42] = "4 of Spades";
	cards[4] = "5 of Clubs"; 			cards[17] = "5 of Diamonds"; 			cards[30] = "5 of Hearts"; 			cards[43] = "5 of Spades";
	cards[5] = "6 of Clubs"; 			cards[18] = "6 of Diamonds"; 			cards[31] = "6 of Hearts";			cards[44] = "6 of Spades";
	cards[6] = "7 of Clubs"; 			cards[19] = "7 of Diamonds"; 			cards[32] = "7 of Hearts"; 			cards[45] = "7 of Spades";
	cards[7] = "8 of Clubs"; 			cards[20] = "8 of Diamonds"; 			cards[33] = "8 of Hearts"; 			cards[46] = "8 of Spades";
	cards[8] = "9 of Clubs"; 			cards[21] = "9 of Diamonds"; 			cards[34] = "9 of Hearts"; 			cards[47] = "9 of Spades";
	cards[9] = "10 of Clubs"; 		cards[22] = "10 of Diamonds"; 		cards[35] = "10 of Hearts"; 		cards[48] = "10 of Spades";
	cards[10] = "Jack of Clubs"; 	cards[23] = "Jack of Diamonds"; 	cards[36] = "Jack of Hearts"; 	cards[49] = "Jack of Spades";
	cards[11] = "Queen of Clubs"; cards[24] = "Queen of Diamonds"; 	cards[37] = "Queen of Hearts"; 	cards[50] = "Queen of Spades";
	cards[12] = "King of Clubs"; 	cards[25] = "King of Diamonds"; 	cards[38] = "King of Hearts"; 	cards[51] = "King of Spades";
	cards[13] = "Ace of Clubs"; 	cards[26] = "Ace of Diamonds"; 		cards[39] = "Ace of Hearts"; 		cards[52] = "Ace of Spades";
	cin >> n;	
	while(n--){
		string line;
		if(!isFirst) cout << endl;
		isFirst = false;
		int k;
		vector<int> vi;
		for(int i = 0; i < 52; i++)	vi.push_back(i+1);
		cin >> k;
		int v[k][52];
		for(int i = 0; i < k; i++)
			for(int j = 0; j < 52; j++)
				cin >> v[i][j];
		scanf("%*c");
		while(getline(cin, line) && line.size()){
			int aux = stoi(line);
			vector<int> viaux(52);		
			for(int i = 0; i < 52; i++){
				viaux[i] = vi[v[aux-1][i]-1];
				vi.clear();
			}
			for(int i = 0; i < 52; i++) vi.push_back(viaux[i]);
		}
		for(int i = 0; i < 52; i++) cout << cards[vi[i]] << endl;
	}
	return 0;
}




