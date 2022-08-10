#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

string T9(char& c) {
	string i;
	switch (c) {
	case 'a': i = "2"; break;
	case 'b': i = "22"; break;
	case 'c': i = "222"; break;
	case 'd': i = "3"; break;
	case 'e': i = "33"; break;
	case 'f': i = "333"; break;
	case 'g': i = "4";break;
	case 'h': i = "44"; break;
	case 'i': i = "444"; break;
	case 'j': i = "5";break;
	case 'k': i = "55"; break;
	case 'l': i = "555"; break;
	case 'm': i = "6"; break;
	case 'n': i = "66"; break;
	case 'o': i = "666"; break;
	case 'p': i = "7"; break;
	case 'q': i = "77"; break;
	case 'r': i = "777"; break;
	case 's': i = "7777"; break;
	case 't': i = "8"; break;
	case 'u': i = "88"; break;
	case 'v': i = "888"; break;
	case 'w': i = "9"; break;
	case 'x': i = "99"; break;
	case 'y': i = "999"; break;
	case 'z': i = "9999"; break;
	case ' ': i = "0"; break;
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k; cin.get();
	char c;
	string s, temp;
	for (int i = 1; i <= k; i++){
		while (cin.peek() != NL) {
			cin.get(c);
			temp = T9(c);
			if (s.back() == temp.front()) s.push_back(' ');
			s.append(temp);
		}
		cin.get();
		cout << "Case #" << i << ": " << s << NL;
		s.clear();
	}
}