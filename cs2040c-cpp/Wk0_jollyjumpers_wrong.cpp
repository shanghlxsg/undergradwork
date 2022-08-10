#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, prev, curr, diff;
	while (cin) {
		cin >> k >> prev; k--;
		n = k;
		while (k--) {
			cin >> curr;
			diff = abs(curr - prev);
			if (diff > n) {
				cin.ignore(3000, NL);
				cout << "Not jolly" << NL;
				break;
			}
			prev = curr;
			if (k == 0) {
				cout << "Jolly" << NL;
			}
		}
	}
}