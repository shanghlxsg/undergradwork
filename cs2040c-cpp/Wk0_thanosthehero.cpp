#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N; cin.get();
	stack<long long> worlds;
	long long temp, kills{ 0 }, max;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp < i && i != 0) {	//maximum requirement
			cout << '1';
			return 0;
		}	//else
		worlds.emplace(temp);
	}	//all worlds pass max req.
	while(worlds.size()>1){
		max = worlds.top() - 1;	//maximum population the previous world can have.
		worlds.pop();
		if (worlds.top() > max) {	//only kill if > max.
			kills += worlds.top() - max;
			worlds.top() = max;
		}
	}
	cout << kills;
}