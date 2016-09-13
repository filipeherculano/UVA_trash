#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

int main(){
  bool isFirst = true;
  int n;
  while(cin >> n){
    if(!isFirst) cout << endl;
    scanf("%*c");
    string name;
    int give, friends;
    vector< pair<string, int> > ppl;
    vector< pair<string, int> >::iterator it;
    for(int i = 0; i < n; i++){
      cin >> name;
      ppl.push_back(std::pair<string, int>(name, 0));
    }

    for(int i = 0; i < n; i++){
      cin >> name >> give >> friends;
      if(give && friends){
        for(int j = 0; j < n; j++){
          if(!name.compare(ppl[j].first)) {
            ppl[j].second -= give;
            ppl[j].second += give % friends;
          }
        }
      }
      
      for(int j = 0; j < friends; j++){
        cin >> name;
        if(give)
          for(int j = 0; j < n; j++)
            if(!name.compare(ppl[j].first)) ppl[j].second += give/friends;
      }
    }
    for(int i = 0; i < n; i++){
      cout << ppl[i].first;
      printf(" %d\n", ppl[i].second);
    }
    isFirst = false;
  }
  return 0;
}
