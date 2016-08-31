#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;
	while(cin >> line){
		vector<int> soundex;
		soundex.push_back(0);
		for(string::iterator it = line.begin(); it != line.end(); it++){
			if(*it == 'B' || *it == 'F' || *it == 'P' || *it == 'V'){
				if(soundex.back() != 1) soundex.push_back(1);
			} else if(*it == 'C' || *it == 'G' || *it == 'J' || *it == 'K'
				|| *it == 'Q' || *it == 'S' || *it == 'X' || *it == 'Z'){
				if(soundex.back() != 2) soundex.push_back(2);
			} else if(*it == 'D' || *it == 'T'){
				if(soundex.back() != 3) soundex.push_back(3);
			} else if(*it == 'L'){
				if(soundex.back() != 4) soundex.push_back(4);
			} else if(*it == 'M' || *it == 'N'){
				if(soundex.back() != 5) soundex.push_back(5);
			} else if(*it == 'R'){
				if(soundex.back() != 6) soundex.push_back(6);
			} else {
				soundex.push_back(0);
			}
		}
		for(int i = 0; i < soundex.size(); i++) if(soundex[i]) printf("%d", soundex[i]);
		cout << endl;
	}
	return 0;
}
