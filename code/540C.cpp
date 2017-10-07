#include <bits/stdc++.h>

using namespace std;
int n, m;
char grid[505][505];
pair<int, int> startpoint;
pair<int, int> endpoint;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(pair<int, int> pos) {
	if(pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m)
		return 0;

	return 1; 
}

bool dfs(pair<int, int> pos) {
	if(pos == endpoint && grid[pos.first][pos.second] == 'X')
		return true;

	if(grid[pos.first][pos.second] == 'X')
		return false;

	pair<int, int> new_pos;
	grid[pos.first][pos.second] = 'X';
	for(int i = 0; i < 4; i++)
	{
		new_pos = make_pair(pos.first + dx[i], pos.second + dy[i]);
		if(isValid(new_pos)) {
			bool res;
			res = dfs(new_pos);
			if(res)
				return res;
		}
	}
	grid[pos.first][pos.second] = '.';

	return false;
}

int main() {
	pair<int, int> startpoint;
	pair<int, int> endpoint;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		cin >> grid[i];

	cin >> startpoint.first >> startpoint.second;
	cin >> endpoint.first >> endpoint.second;

	startpoint.first--;
	startpoint.second--;
	endpoint.first--;
	endpoint.second--;

	grid[startpoint.first][startpoint.second] = '.';

	if(dfs(startpoint))
		cout << "YES" << endl;
	else
		cout << "NO";
	return 0;
}