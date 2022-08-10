#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	bool hey = true;
	cin >> x >> y; cin.get();
	if (x == 0) {
		if (y == 0) {
			hey = false;
		}
	}
	while (hey) {
		if (x + y == 13) cout << "Never speak again." << '\n';
		else if (x > y) cout << "To the convention." << '\n';
		else if (x < y) cout << "Left beehind." << '\n';
		else  if (x == y) cout << "Undecided." << '\n';
		cin >> x >> y; cin.get();
		if (x == 0) {
			if (y == 0) {
				hey = false;
			}
		}
	}
}