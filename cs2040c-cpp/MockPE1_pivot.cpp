//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int pivot = 0;
	int n; cin >> n;
	vector<int> v1 (n);
	for (auto& x : v1) cin >> x;
	vector<int>::iterator itr = v1.begin();
	v1.emplace(itr, 0); n++;
	vector<int>::iterator last = v1.end() - 1;
	int Big = v1[1];

	for (int i = 1;i < n;i++) { //start from v1[1]
		if (v1[i] >= Big) {	//pivot >= current biggest int
			Big = v1[i];
			if (i == n - 1) {
				pivot++;
			}
			else {
				for (int j = i + 1;j < n;j++) {	//check RHS
					if (v1[i] > v1[j]) {
						break;	//stop checking RHS
					}
					else if (j == v1.size() - 1) {
						pivot++;	//v1[i] is smaller than all of RHS
					}
				}
			}
		}	//else v1[i] smaller than LHS, go to next.
	}

	cout << pivot;

	return 0;
}