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
	int n, g, prev, curr, next, pos;
	cin >> n; cin.get();
	while (n--) {
		cin >> g >> prev >> curr;
		g -= 2; pos = 2;
		while (g--) {
			cin >> next;
			if (curr > next&& prev < next) {   //king bigger
				cout << pos << '\n';
			}
			else if (prev > curr&& prev < next) {  //king smaller
				cout << pos << '\n';
			}
			prev = curr; curr = next; pos++;
		}
		cin.get();
	}
}