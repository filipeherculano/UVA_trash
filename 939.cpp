#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

map<string, tuple<string,string,int> > tree;

void solveGene(map<string, tuple<string,string,int> >::iterator it){
	map<string, tuple<string,string,int> >::iterator rit, jit;
	rit = tree.find(get<0>(it->second));
	jit = tree.find(get<1>(it->second));
	if(rit != tree.end() && jit != tree.end()){
		if(get<2>(rit->second) == -100) solveGene(rit);
		if(get<2>(jit->second) == -100) solveGene(jit);
		if(get<2>(rit->second) == -1 || get<2>(jit->second) == -1){
			if(get<2>(rit->second) == 1 || get<2>(jit->second) == 1) get<2>(it->second) = 0;
			else get<2>(it->second) = -1;
		} else {
			if(get<2>(rit->second) == 1 || get<2>(jit->second) == 1) get<2>(it->second) = 1;
			else get<2>(it->second) = 0;
		}
	}
}

int main(){
	int n;
	map<string, tuple<string,string,int> >::iterator it, rit, jit;
	scanf("%d%*c", &n);
	while(n--){
		string w1, w2;
		cin >> w1 >> w2;
		it = tree.find(w1);
		if(w2 == "dominant"){
			if(it == tree.end()) tree.insert(make_pair(w1, make_tuple("oasdiusadafandaidasndaskjfakmsd","oasdiusadafandaidasndaskjfakmsd",1)));
		} else if(w2 == "recessive"){
			if(it == tree.end()) tree.insert(make_pair(w1, make_tuple("oasdiusadafandaidasndaskjfakmsd","oasdiusadafandaidasndaskjfakmsd",0)));
		} else if(w2 == "non-existent"){
			if(it == tree.end()) tree.insert(make_pair(w1, make_tuple("oasdiusadafandaidasndaskjfakmsd","oasdiusadafandaidasndaskjfakmsd",-1)));
		} else{
			rit = tree.find(w2);
			if(rit == tree.end()) tree.insert(make_pair(w2, make_tuple(w1, "oasdiusadafandaidasndaskjfakmsd", -100)));
			else get<1>(rit->second) = w1;
		}
	}
	for(it = tree.begin(); it != tree.end(); it++) if(get<2>(it->second) == -100) solveGene(it);
	for(it = tree.begin(); it != tree.end(); it++){
		cout << it->first << " ";
		if(get<2>(it->second) == 1) cout << "dominant\n";
		else if(get<2>(it->second) == 0) cout << "recessive\n";
		else if(get<2>(it->second) == -1) cout << "non-existent\n";
		else cout << "fuckup\n";
	}
  return 0;
}







