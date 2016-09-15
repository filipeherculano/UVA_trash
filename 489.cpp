#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
	int round;
	while(cin >> round && round != -1){
		scanf("%*c");
		string word, guess;
		int hp = 7;
		int bitmask = 0;
		cin >> word;
		cin >> guess;
		for(int i = 0; i < guess.size() && word.size() && hp; i++){
			size_t pos;
			if(!(bitmask&(1 << (guess[i] - 'a')))){
				pos = word.find(guess[i]);
				if(pos == -1) hp--;
				else {
						while(pos != -1) {
								word.erase(pos, 1);
								pos = word.find(guess[i]);
						}
				}
				bitmask |= 1 << (guess[i] - 'a');
			}
		}
		printf("Round %d\n", round);
		if(!hp) cout << "You lose." << endl;
		else if(!word.size()) cout << "You win." << endl;
		else cout << "You chickened out." << endl;
	}
	return 0;
}
