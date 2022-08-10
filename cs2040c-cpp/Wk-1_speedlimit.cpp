
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <stack>
//#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, spd, tnow, tprev, distance;
	while (true) {
		distance = 0; tprev = 0;
		cin >> n; cin.get();
		if (n == -1) break;
		while (n--) {
			cin >> spd >> tnow; cin.get();
			distance += spd * (tnow - tprev);
			tprev = tnow;
		}
		cout << distance << " miles" << '\n';
	}
}