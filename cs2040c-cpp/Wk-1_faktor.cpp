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
	int articles, factor, citation, div, mod;
	cin >> articles >> factor; cin.get();
	citation = articles * (factor - 1) + 1;
	cout << citation;
}