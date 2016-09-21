#include <bits/stdc++.h>

typedef unsigned long long llu;
typedef long long ll;
typedef long double Lf;

using namespace std;

int main(){
  string line1, line;
  char c;
  map<string, int> cards;
  cards["C2"] = 1; cards["D2"] = 14; cards["S2"] = 27; cards["H2"] = 40;  
  cards["C3"] = 2; cards["D3"] = 15; cards["S3"] = 28; cards["H3"] = 41;  
  cards["C4"] = 3; cards["D4"] = 16; cards["S4"] = 29; cards["H4"] = 42;  
  cards["C5"] = 4; cards["D5"] = 17; cards["S5"] = 30; cards["H5"] = 43;  
  cards["C6"] = 5; cards["D6"] = 18; cards["S6"] = 31; cards["H6"] = 44; 
  cards["C7"] = 6; cards["D7"] = 19; cards["S7"] = 32; cards["H7"] = 45; 
  cards["C8"] = 7; cards["D8"] = 20; cards["S8"] = 33; cards["H8"] = 46;  
  cards["C9"] = 8; cards["D9"] = 21; cards["S9"] = 34; cards["H9"] = 47;  
  cards["CT"] = 9; cards["DT"] = 22; cards["ST"] = 35; cards["HT"] = 48;  
  cards["CJ"] = 10;cards["DJ"] = 23; cards["SJ"] = 36; cards["HJ"] = 49; 
  cards["CQ"] = 11;cards["DQ"] = 24; cards["SQ"] = 37; cards["HQ"] = 50; 
  cards["CK"] = 12;cards["DK"] = 25; cards["SK"] = 38; cards["HK"] = 51; 
  cards["CA"] = 13;cards["DA"] = 26; cards["SA"] = 39; cards["HA"] = 52; 
  while(scanf("%c%*c", &c) && c != '#'){
	getline(cin, line);
	getline(cin, line1);
	line.append(line1);
    int start = (c == 'N' ? 0 : (c == 'E' ? 1 : (c == 'S' ? 2 : 3)));
    vector<string> hands[4]; // NESW
    for(int i = 0; i < line.size()-1; i += 2){
      start = (start+1) % 4;
      char aux[3];
      line.copy(aux, 2, i);
      aux[2] = '\0';
      string saux(aux);
      hands[start].push_back(saux);
    }
    start = 2;
    do{
      printf("%c:", (start == 0 ? 'N' : (start == 1 ? 'E' : (start == 2 ? 'S' : 'W'))));
      for(int i = 0; i < 12; i++)
        for(int j = i+1; j < 13; j++)
          if(cards[hands[start][i]] > cards[hands[start][j]]) swap(hands[start][i], hands[start][j]);

      for(int i = 0; i < 13; i++)
        cout << " " << hands[start][i]; 
      cout << endl;
      start = (start+1) % 4;
    }while(start != 2);
  }
  return 0;
}
