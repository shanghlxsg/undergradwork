
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <stack>
#include <deque>
#include <iterator>
//#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.get();
	while (N--)
	{
		list<char> l;
		list<char>::iterator it = l.begin();
		string s;
		char c;
		getline(cin, s);
		for (char& c : s) {
			if (c == '<') {
				if (it == l.begin()) {
				}
				else {
					it = l.erase(--it);
				}
			}
			else if (c == ']') {
				it = (l.end())--;
			}
			else if (c == '[') {
				it = l.begin();
			}
			else {
				l.insert(it, c);
			}
		}
		for (char& a : l) {
			cout << a;
		}
		cout << endl;
	}
	return 0;
}

//int main() {
//	int TC; cin >> TC;
//	while (TC--) {
//		deque<char> d;
//		deque<char>::iterator itr = d.begin();
//		char c;
//		while (cin.get(c)) {
//			if (c == '[') {
//				itr = d.begin();
//			}
//			else if (c == ']') {
//				itr = d.end();
//			}
//			else if (c == '<') {
//				if (!d.empty()) {
//					d.erase(itr);
//				}
//			}
//			else {
//				d.emplace(itr, c);
//				itr++;
//			}
//		}
//		for (auto iter = d.begin();iter < d.end();iter++) {
//			cout << *iter;
//		}
//	}
//}

//int main() {
//	int TC; cin >> TC; cin.get(); //absorb newline
//	while (TC--) {
//		vector<char> s1; char c;
//		vector<char>::iterator itr = s1.begin(); //move using iterators
//		while (1) {
//			cin.get(c);
//			if (c == '[') { //move to first element
//				itr = s1.begin();
//			}
//			else if (c == ']') { // move to last element
//				itr = s1.end();
//			}
//			else if (c == '<') {
//				if (s1.size() >= 1) {
//					itr--;
//					s1.erase(itr); //erase current position
//				}
//			}
//			else if (c == '\n') { //cout at newline char
//				break;
//			}
//			else {	//add to string
//				s1.emplace(itr, c);
//				itr++; //next position
//			}
//			for (auto& x : s1) cout << x << s1.size() << endl; //checking
//		}
//		for (auto& x : s1) cout << x << endl;
//	}
//	return 0;
//}

//int main() {
//	string s1 ("abcdef");
//	string::iterator itr;
//	itr = s1.begin(); s1.insert(itr, '1');
//	itr = s1.end() - 1; s1.insert(itr, '2');
//	itr = s1.end(); s1.erase(itr-1);
//	cout << s1 << endl;
//
//	return 0;
//}

//int main() {
//	int TC; cin >> TC; cin.get(); //absorb newline
//	while (TC--) {
//		string s1;
//		string::iterator itr = s1.begin(); //move using iterators
//		while (1) {
//			char c;
//			cin.get(c);
//			if (c == '[') { //move to first element
//				itr = s1.begin();
//			}
//			else if (c == ']') { // move to last element
//				itr = s1.end();
//			}
//			else if (c == '<') {
//				if (s1.length() > 0) {
//					itr--;
//					s1.erase(itr); //erase current position
//				}
//			}
//			else if (c == '\n') { //cout at newline char
//				cout << s1 << endl;
//				break;
//			}
//			else {	//add to string
//				s1.insert(itr, c);
//				itr++;
//			}
//			cout << s1 << ' ' << s1.size() << endl; //checking
//		}
//
//	}
//	return 0;
//}

//int main() {
//	int input;
//	vector<int> v(4);
//	while (1) {
//		while (cin >> input) {
//			v.push_back(input);
//		}	//initialise array for 4 elements each time
//		if (v[0] == 0 && v[1]==0&&v[2]==0&&v[3]==0) {
//			return 0;
//		}
//		int deg = 720; //first 2 CW turn
//		if (v[0] > v[1]) {
//			deg += 9 * (40 - v[0] + v[1]);
//		}
//		else {
//			deg += 9 * (v[0] + v[1]);
//		}
//		deg += 360; // full CCW turn
//	}
//	return 0;
//}