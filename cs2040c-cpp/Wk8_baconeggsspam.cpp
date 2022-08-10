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
//#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		int n; cin >> n; cin.get();
		if (n < 1 || n >20) break;
		map<string, vector<string>> ordermap;
		while (n--) {	//for each day
			string Name; cin >> Name;
			string order;
			while (cin.peek() != '\n') {	//for each line of order
				cin >> order;
				ordermap[order].push_back(Name);
			}
			cin.get();	//absorb newline
		}	//after input of each day
		for (auto it1 = ordermap.begin();it1 != ordermap.end();it1++) {
			cout << it1->first;
			sort(it1->second.begin(), it1->second.end());
			for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
				cout << " " << *it2;
			}
			cout << endl;
		}	//before start of next day
		cout << endl;
	}
}

//int main() {
//	int N; cin >> N; cin.get();	//cin.get() to absorb \n before you waste another 4hrs
//	unordered_map<string, pair<int,int>> mymap;
//	priority_queue<pair<pair<int,int>, string>> mypq;
//	int i = 0;
//	while (N--){
//		int k,n; string s;	//k is case, n is infection level
//		cin >> k;
//		if (k == 0) {	//new
//			cin >> s >> n;
//			mymap[s] = make_pair(n, i);
//			mypq.push(make_pair(make_pair(n,i), s));
//			i--;
//			//cout << "ZERO: name= " << s << ", level= " << mymap[s] << endl;
//			//for (auto& x : mymap) cout << "ZERO name=" << x.first << ", level=" << x.second << endl;
//		}
//		else if (k == 1) {	//update
//			cin >> s >> n;
//			//mymap[s].first += n;
//			auto it1=mymap.find(s);
//			it1->second.first += n;
//			mypq.push(make_pair(make_pair(mymap[s].first,mymap[s].second), s));
//			//cout << "ONE: new level: " << mymap[s] << endl;
//		}
//		else if (k == 2) {	//delete
//			cin >> s;
//			//cout << "TWO: sizebef: " << mymap.size();
//			mymap.erase(s);
//			//cout << "sizeaft: " << mymap.size() <<endl;
//		}
//		else if (k == 3) {
//			if (mymap.empty()) {
//				cout << "The clinic is empty" << endl;
//			}
//			else {
//				while (!mypq.empty()) {
//					auto it2 = mypq.top().second;
//					if (mymap.find(it2) != mymap.end()) {
//						cout << it2 << endl;
//						break;
//					}
//					else mypq.pop();
//				}
//			}
//		}
//		else cout << "ERROR" << endl;
//	}
//	return 0;
//}