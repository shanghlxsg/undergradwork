//#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int N; cin >> N; cin.get();
	while (N--) {
		string s1("abcdefghijklmnopqrstuvwxyz");
		string input;
		getline(cin, input);
		for (int i = 0;i < input.size();i++) {
			if (isalpha(input[i])) {
				for (string::iterator itr = s1.begin();itr < s1.end();) {
					if (tolower(input[i]) == *itr) {
						s1.erase(itr);
					}
					else {
						itr++;
					}
				}
			}
		}
		if (s1.empty()) {
			cout << "pangram" << endl;
		}
		else {
			//for (auto& v : s1) cout << s1;
			//cout << endl;
			cout << "missing " << s1 << endl;
		}
	}
	return 0;
}