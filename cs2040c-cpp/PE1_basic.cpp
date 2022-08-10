//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

int main() {
	int N, t; cin >> N >> t;
	vector<int> v1(N);
	for (auto& x : v1) cin >> x;
	vector<int>::iterator it1, it2;
	it1 = v1.begin(); it2 = v1.end();

	if (t == 1) {
		cout << "7" << endl;
	}
	else if (t == 2) {
		if (it1 > it1 + 1) {
			cout << "Bigger" << endl;
		}
		else if (it1 == it2) {
			cout << " Equal" << endl;
		}
		else {
			cout << "Smaller" << endl;
		}
	}
	else if (t == 3) {
		priority_queue<int> pq1;
		for (int i = 0;i < 3;i++) {
			pq1.push(v1[i]);
		}
			pq1.pop();
			cout << pq1.top() << endl;
	}
	else if (t == 4) {
		cout << accumulate(it1, it2, 0) << endl;
	}
	else if (t == 5) { //try using element access [ ] instead of iterator
		int sum = 0;
		for (it1;it1 < it2;it1++) {
			if (*it1 % 2 == 0) {
				sum += *it1;
			}
		}
		cout << sum << endl;
	}
	else if (t == 6) {
		for (it1;it1 < it2;it1++) {
			*it1 %= 26;
		}
		string s1("abcdefghijklmnopqrstuvwxyz");
		string s2;
		//no need string, integer addition to char c 'a' gives respective alphabets
		vector<int>::iterator it1, it2;
		it1 = v1.begin(); it2 = v1.end();
		for (it1;it1 < it2;it1++) {
			s2.push_back(s1.at(*it1));
		}
		cout << s2 << endl;
	}
	else if (t == 7) {
		vector<int>::iterator itr = find(it1, it2, 0);
		if (itr == it2) {
			cout << "Out" << endl;
		}
		else if (*itr == 0) {
			cout << "Cyclic" << endl;
		}
		else {
			cout << "Done" << endl;
		}
	}
	return 0;
}