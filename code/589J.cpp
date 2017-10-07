#include <bits/stdc++.h>

using namespace std;
char grid[10][10];
bool visited[10][10][4] = {0};
int w, h;
int ans = 0;
pair<int, int> changepos(pair<int, int> pos, int dir) {
	if(dir == 0)
		return (make_pair(pos.first - 1, pos.second));
	else if(dir == 1)
		return (make_pair(pos.first, pos.second + 1));
	else if(dir == 2)
		return (make_pair(pos.first + 1, pos.second));
	else if(dir == 3)
		return (make_pair(pos.first, pos.second - 1));
}

bool isValid(pair<int, int> pos) {
	if(pos.first < 0 || pos.first >= w || pos.second < 0 || pos.second >= h)
		return 0;

	if(grid[pos.first][pos.second] == '*')
		return 0;
	
	return 1; 
}

void dfs(pair<int, int> start, int dir) {

	if(visited[start.first][start.second][dir] == 1)
		return;

	pair<int, int> next_move;

	bool visit = false;
	for(int i = 0; i < 4; i++)
		visit |= visited[start.first][start.second][i];
	
	visited[start.first][start.second][dir] = true;

	if(!visit)
		ans++;

	next_move = changepos(start, dir);

	if(isValid(next_move)) {
		dfs(next_move, dir);
	}
	else {
		dfs(start, (dir + 1) % 4);
	}
}

int main() {

	cin >> w >> h;
	pair<int, int> start;
	int dir = 0;
	for(int i = 0;i < w; i++) {
		for(int j = 0; j < h; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == 'U') {
				start = make_pair(i, j);
				dir = 0;
			}
			else if(grid[i][j] == 'R') {
				start = make_pair(i, j);
				dir = 1;
			}
			else if(grid[i][j] == 'D') {
				start = make_pair(i, j);
				dir = 2;
			}
			else if(grid[i][j] == 'L') {
				start = make_pair(i , j);
				dir = 3;
			}
		}
	}
	dfs(start, dir);
	cout << ans << endl;

	return 0;
}