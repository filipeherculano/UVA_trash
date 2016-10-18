#include <bits/stdc++.h>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;

using namespace std;
// 0, 2, 5, 6, 1, 8
bool compare(tuple<int, int, int, int, int, int, int, int, string> a, tuple<int, int, int, int, int, int, int, int, string> b){
	if(get<0>(a) > get<0>(b)) return true;
	else if(get<0>(a) < get<0>(b)) return false;
	else {
		if(get<2>(a) > get<2>(b)) return true;
		else if(get<2>(a) < get<2>(b)) return false;
		else{
			if(get<5>(a) > get<5>(b)) return true;
			else if(get<5>(a) < get<5>(b)) return false;
			else{
				if(get<6>(a) > get<6>(b)) return true;
				else if(get<6>(a) < get<6>(b)) return false;
				else{
					if(get<1>(a) > get<1>(b)) return false;
					else if(get<1>(a) < get<1>(b)) return true;
					else {
						string tempA, tempB;
						REP(i, get<8>(a).size()){
							if(get<8>(a)[i] >= 'A' && get<8>(a)[i] <= 'Z') tempA.pb(get<8>(a)[i] + 32);
							else tempA.pb(get<8>(a)[i]);
						}
						REP(i, get<8>(b).size()){
							if(get<8>(b)[i] >= 'A' && get<8>(b)[i] <= 'Z') tempB.pb(get<8>(b)[i] + 32);
							else tempB.pb(get<8>(b)[i]);
						}
						return lexicographical_compare(all(tempA), all(tempB));
					}
				}
			}
		}
	}
}

int main(){
	bool isFirst = true;
	int n;
	scanf("%d%*c", &n);
	while(n--){
		string tour, aux;
		int t, g, rank = 1;
		getline(cin, tour);
		scanf("%d%*c", &t);
		vector< tuple<int, int, int, int, int, int, int, int, string> > tup;
		REP(i, t) {
			getline(cin, aux);
			tup.pb(make_tuple(0,0,0,0,0,0,0,0,aux)); // points, games, wins, ties, losses, goal diff, goal scored, goals against, name
		}
		scanf("%d%*c", &g);
		REP(i, g){
			int ga, gb, indexA, indexB;
			string temp, teamA, teamB;
			stringstream ss;
			getline(cin, aux);
			REP(j, aux.size()){
				if(aux[j] == '#' || aux[j] == '@') temp.pb(' ');
				else if(aux[j] == ' ') temp.pb('_');
				else temp.pb(aux[j]);
			}
			ss << temp;
			ss >> teamA >> ga >> gb >> teamB;
			REP(j, teamA.size()) if(teamA[j] == '_') teamA[j] = ' ';
			REP(j, teamB.size()) if(teamB[j] == '_') teamB[j] = ' ';
			REP(j, t){
				if(get<8>(tup[j]) == teamA) indexA = j;
				if(get<8>(tup[j]) == teamB) indexB = j;
			}
			if(ga < gb){
				get<1>(tup[indexA])++; get<4>(tup[indexA])++; get<5>(tup[indexA]) += ga-gb; get<6>(tup[indexA]) += ga; get<7>(tup[indexA]) += gb; 
				get<0>(tup[indexB]) += 3; get<1>(tup[indexB])++; get<2>(tup[indexB])++; get<5>(tup[indexB]) += gb-ga; get<6>(tup[indexB]) += gb; get<7>(tup[indexB]) += ga; 
			} else if(ga > gb){
				get<1>(tup[indexB])++; get<4>(tup[indexB])++; get<5>(tup[indexB]) += gb-ga; get<6>(tup[indexB]) += gb; get<7>(tup[indexB]) += ga; 
				get<0>(tup[indexA]) += 3; get<1>(tup[indexA])++; get<2>(tup[indexA])++; get<5>(tup[indexA]) += ga-gb; get<6>(tup[indexA]) += ga; get<7>(tup[indexA]) += gb; 
			} else {
				get<0>(tup[indexA])++; get<1>(tup[indexA])++; get<3>(tup[indexA])++; 
				get<5>(tup[indexA]) += ga-gb; get<6>(tup[indexA]) += ga; get<7>(tup[indexA]) += gb; 
				get<0>(tup[indexB])++; get<1>(tup[indexB])++; get<3>(tup[indexB])++; 
				get<5>(tup[indexB]) += gb-ga; get<6>(tup[indexB]) += gb; get<7>(tup[indexB]) += ga; 
			}
		}
		sort(all(tup), compare);
		if(!isFirst) cout << endl;
		isFirst = false;
		cout << tour << endl;
		REP(i, tup.size()){
			printf("%d) ", rank++);
			cout << get<8>(tup[i]);
			printf(" %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", get<0>(tup[i]), get<1>(tup[i]), get<2>(tup[i]), get<3>(tup[i]), get<4>(tup[i]), get<5>(tup[i]), get<6>(tup[i]), get<7>(tup[i]));
		}
	}
  return 0;
}

















