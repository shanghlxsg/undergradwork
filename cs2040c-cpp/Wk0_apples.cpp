#include <bits/stdc++.h>
#define NL '\n'
using namespace std;

//use string each row is faster.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row, col;
    char c;
    array<vector<char>, 10> atree;
    array<int, 10>  obstacle = { 0,0,0,0,0,0,0,0,0,0 }; //where to insert space instead.
    cin >> row >> col; cin.get();
    for (int i = 0; i < row;i++) {  //row
        vector<char> hold;
        for (int j = 0; j < col; j++) { //col
            cin.get(c);
            if (c == 'a') {
                atree[j].emplace_back(c);
            }
            else if (c == '#') {
                obstacle[j] = i + 1;
                atree[j].emplace_back(c);
            }
            else {  //empty space
                auto it = atree[j].begin() + obstacle[j];
                atree[j].emplace(it, c);
            }
        }   //next row.
        cin.get();
    }
    cout << NL;
    for (int i = 0; i < row;i++) {
        for (int j = 0; j < col; j++) {
            cout << atree[j][i];
        }
        cout << NL;
    }
}