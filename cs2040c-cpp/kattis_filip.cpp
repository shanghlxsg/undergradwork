#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	string s1, s2;
	char c;
	while (cin.get(c), isdigit(c)) {
		s1.insert(0, 1, c);
	}
	while (cin.get(c), isdigit(c)) {
		s2.insert(0, 1, c);
	}
	if (s1 > s2) cout << s1 << NL;
	else cout << s2 << NL;
}