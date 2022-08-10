#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, temp;
	vector<int> tea, topp;	//pricing
	cin >> n; cin.get();
	for (int i = 0; i < n;i++) {
		cin >> temp;
		tea.emplace_back(temp);
	}
	cin.get();
	cin >> m; cin.get();
	for (int i = 0; i < m;i++) {
		cin >> temp;
		topp.emplace_back(temp);
	}
	cin.get();
	int cheapest=2001;	//most expensive combination =1000+1000
	for(int i=0;i<n;i++) {
		int k; cin >> k;
		while (k--) {
			cin >> temp;
			if (temp < topp.size()) {	//prevent out of range
				int price = tea[i] + topp[temp - 1];	//price of current combination
				if (price < cheapest) cheapest = price;	//update with cheapest combination
			}
		}
		cin.get();
	}
	int wallet; cin >> wallet;
	int count = wallet / cheapest;
	if (count > 0) count--;
	cout << count;
}