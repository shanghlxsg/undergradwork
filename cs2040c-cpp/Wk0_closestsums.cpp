#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int binarysearch(vector<int>& v, int& q, int& L, int& R) {	//returns position
	if (q <= v[L]) return L;			//first element.
	else if (q >= v[R]) return R;		//last element.
	else {
		while (R - L > 1) {	//R-L=2 means L or R was MID previously, already checked.
			int mid = (L + R) / 2;
			if (q == v[mid]) return mid;	//middle element.
			else if (q < v[mid]) R = mid;	//go left, update R.
			else if (q > v[mid]) L = mid;	//go right, update L.
		}
		if (R - L == 1) {	//between L and R, return element closest in value.
			if (q - v[L] <= v[R] - q) return L;	//closer to left
			else return R;	//closer to right
		}
		return -1; //not found
	}
}

void print1(int& a, int& b) {
	cout << "Closest sum to " << a << " is " << b << '.' << NL;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i = 1;
	while (cin.peek() != EOF) {
		vector<int> myvec, sum;
		int n, m;
		cin >> n; cin.get();
		int temp; cin >> temp; cin.get();
		myvec.push_back(temp); n--;	//first number.
		while (n--) {
			cin >> temp; cin.get();
			//for (auto it = myvec.begin(); it != myvec.end(); it++) {
			//	sum.push_back(temp + *it);	//sum of temp and all previous numbers.
			//}
			myvec.push_back(temp);	//add temp to vector.
		}
		//if (sum.empty()) sum.push_back(myvec.front());	//if there's only 1 number
		//sort(sum.begin(), sum.end());
		sort(myvec.begin(), myvec.end());
		//queries
		cin >> m; cin.get();
		cout << "Case " << i << ":" << NL; i++;
		while (m--) {
			cin >> temp; cin.get();
			int L = 0;
			int R = sum.size()-1;
			int pos = binarysearch(sum, temp, L, R);
			print1(temp, sum[pos]);
		}
	}
}