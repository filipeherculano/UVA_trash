#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define Lf long double

using namespace std;

/*
	This question need some clarifications:
		-> When one of the sides of the chessboard is equal to one,
		   then the maximum number of knights is equal to the other
		   side. Since knights can't move in straight lines.
		-> When one of the sides of the chessboard is equal to two,
		   we will calculate differently. I noticed that for a che-
		   ssboard with one of the sides equal to 2, the rule below
		   doesn't apply. The rule now is: "Every 4 slots in one row
		   we'll have 2 knights". This means that a side that has
		   mod != 1 we should just add three(adding ceil) and divide 
		   by 4. If it is equal to 1, then subtract by one.
		-> The trivial answer is just counting the number of slots
		   in the same color, since knights can only move to other
		   color slots. For example: in a 5x5 chessboard, there is
		   exactly 25 slots, 12 black and 13 white (or the other
		   way around). Which means the maximum number of knights
		   in this trivial test case is 13.

	To really understand this question, you should draw alot! Good luck!
*/

int main(){
	int m, n;
	while(cin >> m >> n && (m || n)){
		int ans;
		if(min(n,m) == 1) ans = max(n,m);
		else if(min(n,m) == 2) ans = min(n,m)*((2*((max(n,m)+3)/4)) - (max(n,m) % 4 == 1 ? 1 : 0));
		else ans = ((n*m)+1)/2; 
		printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
  	}
	return 0;
}
