#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <deque>
#include <queue>
#include <iterator>
#include <map>
#include <unordered_map>
#include <sstream>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, votes, winner, highest, total, cand, same;
	cin >> T; cin.get();
	while (T--) {
		cin >> n; cin.get();
		highest = 0; total = 0; cand = 1;
		while (n--) {
			cin >> votes; cin.get();
			if (votes > highest) {	//update with new candidate data
				winner = cand;
				highest = votes;
				same = 0;
			}
			else if (votes == highest) {
				same++;
			}
			total += votes;		//total votes
			cand++;				//candidate count
		}
		cand--;
		if (highest * cand == total || same > 0) cout << "no winner" << '\n';
		else if (highest * 2 > total) cout << "majority winner " << winner << '\n';
		else if (highest * 2 <= total) cout << "minority winner " << winner << '\n';
		else cout << "ERROR" << '\n';
	}
}