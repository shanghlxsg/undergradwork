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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N; cin.get();
	deque<int> d1, d2, d3;
	//deque<int>::iterator itr = d.begin();
	string s; int n;

	string back("push_back");
	string front("push_front");
	string middle("push_middle");
	string g("get");

	while (N--) {
		getline(cin, s, ' '); cin >> n; cin.get();
		if (s == back) {
			d2.emplace_back(n); //right 
			if (d2.size() > d1.size()+1) { //RHS>LHS shift 1 element LHS
				d1.emplace_back(d2.front());
				d2.pop_front();
			}
		}
		else if (s == front) {
			d1.emplace_front(n); //left array
			if (d2.size() < d1.size()) {
				d2.emplace_front(d1.back());
				d1.pop_back();
			}
		}
		else if (s == middle) {
			if (d1.size() == d2.size()) d2.emplace_front(n); //right array
			else {
				d1.emplace_back(d2.front());
				d2.pop_front();
				d2.emplace_front(n);
			}
			//d.emplace((d.begin()+(d.size()+1)/2), n);
		}
		else if (s == g) {
			if (n < d1.size()) { //left array
				cout << d1[n] << endl;
			}
			else { //right array
				cout << d2[n - d1.size()] << endl;
			}
			//cout << d[n] << endl;
		}
	}
	return 0;
}


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