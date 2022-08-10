//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <stack>

using namespace std;

int main() {
	//cout << sizeof(int) << " " << sizeof(long long) << endl;

	int TC; cin >> TC;
	while (TC--) {
		int N;
		long long a1, b1, c1, x1, y1;
		cin >> N >> a1 >> b1 >> c1 >> x1 >> y1;

		priority_queue<long long> pq1; pq1.push(a1);	//S[0]
		long long prevEle = a1;	//S[i-1]=A
		for (int i = 1;i < N;i++) {
			long long currEle = (prevEle * b1 + a1) % c1;	//S[i]
			pq1.push(currEle);	//push S[i] into pq
			prevEle = currEle;	//S[i] is now S[i-1]
		} //pq is sorted
		stack<long long> mystack;
		for (int i = 0;i < N;i++) {	//shift pq to stack to start from smallest
			mystack.push(pq1.top());
			pq1.pop();
		}
		long long V = 0;
		for (int j = 0;j < N;j++) {
			V = (V * x1 + mystack.top()) % y1;
			mystack.pop();
		}
		cout << "ans: " << V <<endl;
	}
	return 0;
}

/*
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
	else if (t == 5) {
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
*/