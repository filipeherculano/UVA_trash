#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	int n, m = 1;
	string line;
	bool isFirst = true;
	map<string, char> msc;
	msc[".-"] 	= 'A'; msc[".---"] 	= 'J'; msc["..."] 	= 'S'; msc[".----"] = '1'; msc[".-.-.-"] 	= '.'; msc["---..."] = ':'; 
	msc["-..."] = 'B'; msc["-.-"] 	= 'K'; msc["-"] 		= 'T'; msc["..---"] = '2'; msc["--..--"] 	= ','; msc["-.-.-."] = ';'; 
	msc["-.-."] = 'C'; msc[".-.."] 	= 'L'; msc["..-"] 	= 'U'; msc["...--"] = '3'; msc["..--.."] 	= '?'; msc["-...-"]  = '='; 
	msc["-.."] 	= 'D'; msc["--"] 		= 'M'; msc["...-"] 	= 'V'; msc["....-"] = '4'; msc[".----."] 	= '\''; msc[".-.-."]  = '+'; 
	msc["."] 		= 'E'; msc["-."] 		= 'N'; msc[".--"] 	= 'W'; msc["....."] = '5'; msc["-.-.--"] 	= '!'; msc["-....-"] = '-'; 
	msc["..-."] = 'F'; msc["---"] 	= 'O'; msc["-..-"] 	= 'X'; msc["-...."] = '6'; msc["-..-."] 	= '/'; msc["..--.-"] = '_'; 
	msc["--."] 	= 'G'; msc[".--."] 	= 'P'; msc["-.--"] 	= 'Y'; msc["--..."] = '7'; msc["-.--."] 		= '('; msc[".-..-."] = '"'; 
	msc["...."] = 'H'; msc["--.-"] 	= 'Q'; msc["--.."] 	= 'Z'; msc["---.."] = '8'; msc["-.--.-"] 	= ')'; msc[".--.-."] = '@'; 
	msc[".."] 	= 'I'; msc[".-."] 	= 'R'; msc["-----"] = '0'; msc["----."] = '9'; msc[".-..."] 	= '&'; msc["*"] = ' '; 
	scanf("%d%*c", &n);
	while(n--){
		if(!isFirst) cout << endl;
		isFirst = false;
		stringstream ss;
		getline(cin, line);
		FOR(i, line.size()-1) if(line[i] == line[i+1] && line[i] == ' ') line[i] = '*';
		ss << line;
		printf("Message #%d\n", m++);
		while(ss >> line) {
			string temp = line;
			if(line[line.size()-1] == '*') temp.pop_back();
			cout << msc[temp];
			if(line[line.size()-1] == '*') cout << " ";
		}
		cout << endl;
	}
  return 0;
}


