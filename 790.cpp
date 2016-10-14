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
	Don't fall for the problem description lies!
*/

struct submission{
	int time;
	int tempoABS;
	int tempo;
	char quest;
	char ver;
};

struct teams{
	int time;
	int qnt;
	int pen;
};

bool compareInput(const submission &a, const submission &b){
	if(a.tempoABS < b.tempoABS) return true;
	if(a.tempoABS > b.tempoABS) return false;
	
	return a.ver < b.ver;
}

bool compare(const teams &a, const teams &b){
	if(a.qnt < b.qnt) return false;
	if(a.qnt > b.qnt) return true;
	
	if(a.pen < b.pen) return true;
	if(a.pen > b.pen) return false;
	
	return a.time < b.time;
}

int main(){
	int n;    
	string line;
	cin >> n;
  cin.ignore(100, '\n');
  getline(cin, line);
	while(n--){
		int p[25][26], team, h, m, M = 0;
		char ver, quest;
		vector<teams> vt;
		vector<submission> vinput;
		
		REP(i, 25) REP(j, 26) p[i][j] = 0;
		
		while(getline(cin, line)){
			if(line == "") break;
			submission subs;
			REP(i, line.size()) if(line[i] == ':') line[i] = ' ';
			stringstream ss;
			ss << line;
			ss >> subs.time >> subs.quest >> h >> m >> subs.ver;
			subs.tempoABS = (abs(h)*60)+abs(m);
			subs.tempo = (h*60)+m;
			M = max(M, subs.time);
			vinput.pb(subs);
		}
		sort(all(vinput), compareInput);
		
		int qst[M][26];
		REP(i, M) REP(j, 26) qst[i][j] = 0;
		
		REP(i, vinput.size()){
			if(vinput[i].ver == 'Y'){
				if(qst[vinput[i].time-1][vinput[i].quest-'A'] != 1) {
					p[vinput[i].time-1][vinput[i].quest-'A'] = vinput[i].tempo + abs(p[vinput[i].time-1][vinput[i].quest-'A'])*20;
					qst[vinput[i].time-1][vinput[i].quest-'A'] = 1;
				}
			} else if(vinput[i].ver == 'N'){
				if(qst[vinput[i].time-1][vinput[i].quest-'A'] != 1) {
					p[vinput[i].time-1][vinput[i].quest-'A']--;
				}
			}
		}
		REP(i, M){
			teams timao;
			timao.time = i+1;
			timao.qnt = 0;
			timao.pen = 0;
			REP(j, 26){
				if(qst[i][j] == 1){
					timao.pen += p[i][j];
					timao.qnt++;
				}
			}
			vt.pb(timao);
		}
		sort(all(vt), compare);
		
		printf("RANK TEAM PRO/SOLVED TIME\n");
		int j = 0;
		REP(i, vt.size()){
			if (i == 0 || vt[i].qnt != vt[i-1].qnt || (vt[i].qnt == vt[i-1].qnt && vt[i].pen != vt[i-1].pen)) j = i+1;
			printf("%4d %4d", j, vt[i].time);
			if(vt[i].qnt > 0) printf(" %4d %10d", vt[i].qnt, vt[i].pen);
			printf("\n");
		}
		if(n) cout << endl;
	}
  return 0;
}














