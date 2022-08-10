#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i = 1;
	string str1, str2;
	char c, d;
	c = cin.peek();
	while (c != EOF) {
		cin >> str1 >> str2; cin.get();
		if (str1.length() == 1) cout << "Case " << i << ": UNIQUE \n";
		else {
			stringstream(str1) >> c >> d;
			if (d == '#') {
				if (c == 'G') c = 'A';	//G becomes A
				else c++;	//next alphabet
				d = 'b';
			}
			else if (d == 'b') {
				if (c == 'A') c = 'G';	//A becomes G
				else c--;	//previous alphabet
				d = '#';
			}
			cout << "Case " << i << ": " << c << d << " " << str2 << '\n';
		}
		i++;
		c = cin.peek();
	}
}