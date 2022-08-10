#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string n, m;
	cin >> n >> m;
	while (m.back() == '0' && n.back() == '0') {
		n.pop_back();
		m.pop_back();
	}
	int a = n.size() - m.size() + 1;	//number of digits before decimal.
	if (m.size()==1) {	//no remainder.
		cout << n;
	}
	else if (n.size() < m.size()) {	//all digits after decimal.
		cout << "0.";
		for (int i = 0; i < m.size() - n.size() - 1; i++) {
			cout << "0";
		}
		cout << n;
	}
	else {	//decimal in the middle of n.
		auto it = n.begin() + a;
		n.insert(it, '.');
		cout << n;
	}
}