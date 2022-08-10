#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int card[13] = { 0 };
	char c;
	int a, b, largest;
	b = 5; largest = 0;
	while (b--) {
		cin.get(c); cin.get(); cin.get();
		switch (c) {
		case 'A': a = 1; break;
		case 'T': a = 10; break;
		case 'J': a = 11; break;
		case 'Q': a = 12; break;
		case 'K': a = 0; break;
		default: a = c - '0'; break;
		}
		//cout << a << '\n';
		card[a]++;
		if (card[a] > largest) largest = card[a];
	}
	cout << largest;
}