#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
	string line;
	map<char, char> mc;
	map<char, char>::iterator it, jit;
	mc['A'] = 'A'; mc['O'] = 'O'; mc['Y'] = 'Y';
	mc['E'] = '3'; mc['S'] = '2'; mc['Z'] = '5';
	mc['H'] = 'H'; mc['T'] = 'T'; mc['1'] = '1';
	mc['I'] = 'I'; mc['U'] = 'U'; mc['2'] = 'S';
	mc['J'] = 'L'; mc['V'] = 'V'; mc['3'] = 'E';
	mc['L'] = 'J'; mc['W'] = 'W'; mc['5'] = 'Z';
	mc['M'] = 'M'; mc['X'] = 'X'; mc['8'] = '8';
	while(getline(cin, line)){
		bool ok = true;
		int i=0, j=line.size()-1;
		cout << line;
		while(i < j){
			if(line[i] != line[j]) ok = false;
			i++;j--;
		}
		if(ok){
			ok = true;
			i=0;j=line.size()-1;
			while(i <= j){
				it = mc.find(line[i]);
				jit = mc.find(line[j]);
				if(it == mc.end() || jit == mc.end()) ok = false;
				if(it->first != jit->second) ok = false;
				i++; j--;
			}
			if(ok) printf(" -- is a mirrored palindrome.\n");
			else printf(" -- is a regular palindrome.\n");
		} else{
			ok = true;
			i=0;j=line.size()-1;
			while(i <= j){
				it = mc.find(line[i]);
				jit = mc.find(line[j]);
				if(it == mc.end() || jit == mc.end()) ok = false;
				if(it->first != jit->second) ok = false;
				i++; j--;
			}
			if(ok) printf(" -- is a mirrored string.\n");
			else printf(" -- is not a palindrome.\n");
		}
		cout << endl;
	}
  return 0;
}




