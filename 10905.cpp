#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;

/*
	Concatene as strings usando '+' e verifique se a possibilidade
	de trocar é boa ou não com o '>'
	
	Se retornar false, ele dá swap.
	se retornar true, ele mantém a ordem.
	
	909 é menor lexograficamente que 990, porém nós usamos o inverso e
	queremos decrescer lexograficamente
*/

bool compare(string a, string b){
	return (a+b > b+a);
}

int main(){
	int n;
	while(scanf("%d%*c", &n) && n){
		string aux;
		vector<string> vs;
		REP(i, n) {
			cin >> aux;
			vs.pb(aux);
		}
		sort(all(vs), compare);
		REP(i, vs.size()) cout << vs[i];
		cout << endl;
	}
  return 0;
}
