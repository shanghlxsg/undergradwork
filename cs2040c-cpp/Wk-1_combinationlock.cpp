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
	int a1, a2, a3, a4, sum, deg;
	while (true) {
		cin >> a1 >> a2 >> a3 >> a4; cin.get();
		if ((a1 + a2 + a3 + a4) == 0) break;
		deg = 720;	//2 full CW 
		//CW goes backwards in counting, CCW goes forward, each digit is 360/40=9 degrees
		//stop at first number + 1 CCW 
		deg += ((a1 - a2 + 40) % 40) * 9 + 360;
		//CCW stop at second number 
		deg += ((a3 - a2 + 40) % 40) * 9;
		//CW stop at third number
		deg += ((a3 - a4 + 40) % 40) * 9;
		cout << deg << '\n';
	}
}