#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int i{ 1 }, k;
	while (cin>>k, !cin.eof()){
		int high{ 0 }, low{ 0 }, n;
		for (int i = 0; i < k; i++) {
			cin >> n;
			if (i == 0) {
				high = n;
				low = n;
			}
			else if (n > high) high = n;
			else if (n < low) low = n;
		}
		cout << "Case " << i++ << ": " << low << ' ' << high << ' ' << high - low << NL;
	}
}