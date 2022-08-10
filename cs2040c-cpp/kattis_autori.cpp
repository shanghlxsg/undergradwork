#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	string s;
	char c;
	while (cin.peek()!=EOF) {
		cin.get(c);
		if (isupper(c)) {
			s.push_back(c);
		}
	} cout << s << NL;
}