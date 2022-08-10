#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T; cin.get();
	while (T--) {
		int n, m; cin >> n >> m;cin.get();
		vector<vector<int>> prizes;	//at most 30 prizes, each prize containing list of stickertypes.
#define PB prizes.back()
#define PBB prizes.back().back()
		vector<int> stickers; stickers.push_back(0);
		int pcount = 0;	//start from first prize.
		while (n--) {
			prizes.emplace_back(vector<int>());
			int k; cin >> k; k++;	//last element for each vector is the prize value.
			while (k--) {
				int temp; cin >> temp;
				PB.emplace_back(temp);
				//cout << PBB << NL;
			}
		}
		while (m--) {
			int temp; cin >> temp;
			stickers.push_back(temp);
		}
		int a{ 1 }, totalval{ 0 }, mincount{ 0 };
		while (!prizes.empty()) {
			int pval = PBB;	//value for prize.
			PB.pop_back();	//remaining PB vector elements are all sticker types
			mincount = stickers[PBB];	//any potential non-zero value
			while (!PB.empty()) {
				int abc = stickers[PBB];	//stickercount for stickertype
				if (abc < mincount) mincount = abc;	//lowest sticker count (can be zero).
				PB.pop_back();
			}
			totalval += (pval * mincount);
			prizes.pop_back();//next prize
		}
		cout << totalval << '\n';
	}
}