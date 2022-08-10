#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stack>
#include <deque>
#include <queue>
#include <iterator>
#include <map>
#include <unordered_map>
#include <sstream>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	float n, m, s, N, M, S, avg;
	cin >> N; cin.get();
	n = N; m = 0; s = 0;
	while (n--) {
		cin >> M >> S; cin.get();
		m += M; s += S;
	}
	avg = s / (m * 60);
	cout.precision(8);
	if (avg <= 1) cout << "measurement error" << '\n';
	else cout << avg << '\n';
}