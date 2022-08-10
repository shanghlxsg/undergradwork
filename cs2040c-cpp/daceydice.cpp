#include <bits/stdc++.h>
using namespace std;
enum {TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK};

// Input is the *current* position of the '5' 
// Returns the *future* position of the '5' after you more right
int move_right(int pos) {
	switch(pos) {
		case TOP: return RIGHT;
		case RIGHT: return BOTTOM;
		case BOTTOM: return LEFT;
		case LEFT: return TOP;
		case FRONT: return FRONT;
		case BACK: return BACK;
	}
}

int move_left(int pos) {
	switch(pos) {
		// Fill in this bit yourself
		// It is the reverse of move_right
	}
}

int move_up(int pos) {
	switch(pos) {
		case TOP: return BACK;
		case RIGHT: return RIGHT;
		case BOTTOM: return FRONT;
		case LEFT: return LEFT;
		case FRONT: return TOP;
		case BACK: return BOTTOM;
	}
}

int move_down(int pos) {
	switch(pos) {
		// Reverse of move up       
	}
}

char grid[25][25];
bool flag = false;
int n;
set<tuple<int,int,int>> visited;

// A helper function to check whether that square is valid to visit
// (within bounds, not blocked, not visited before)
bool is_valid(int r, int c, int o) {
	return (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] != '*'
	&& visited.count({r,c,o}) == 0);
}

void dfs(int r, int c, int o) {
	// if you visit the goal state, set flag = true
	if (grid[r][c] == 'H' && o == BOTTOM) {
		flag = true; return;
	}
	// Mark that state as "visited"
	visited.insert({r,c,o});
	
	int r2,c2,o2;	

	// move right
	r2 = r; c2 = c + 1, o2 = move_right(o);
	if (is_valid(r2,c2,o2)) 
		dfs(r2,c2,o2);
	
	// Do similar for the other directions
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n; 
		int r,c;
		// reset variables
		visited.clear(); 
		flag = false;
		// Read in the grid
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				cin>>grid[i][j];
				if (grid[i][j] == 'S') {
					r = i; c = j; // Note down initial position
				}
			} 
		}
		// Explore all possible "states" from the initial state,
		dfs(r,c,LEFT);
		// check if flag == true, print output accordingly
	}
}