#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin >> n;
	string s1, s2, order;

	while (n--) {
		cin >> s2;
		if (!s1.empty() && s2 > s1) {
			if (order == "DECREASING") {
				cout << "NEITHER" << NL;
				return 0;
			}
			else order = "INCREASING";
		}
		else if (!s1.empty() && s2 < s1) {
			if (order == "INCREASING") {
				cout << "NEITHER" << NL;
				return 0;
			}
			else order = "DECREASING";
		}
		s1 = s2;
	}
	cout << order << NL;
}