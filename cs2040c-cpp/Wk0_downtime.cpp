#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, temp, count{ 0 }, highest{ 0 };
	queue<int> req;
	priority_queue<int> high;
	cin >> n >> k; cin.get();
	while (n--) {
		cin >> temp; cin.get();
		if (!req.empty() && temp - req.front() >= 1000) {	//more than 1000ms difference
			req.pop();
			count--;
		}
		req.push(temp);
		count++;
		high.push(count);
	}
	highest = high.top();
	highest = (highest + k - 1) / k;
	cout << highest;
}