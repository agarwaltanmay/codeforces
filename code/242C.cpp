#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<int, int> > validPoints;

int bfs(pair<int, int> start, pair<int, int> end, map<pair<int, int>, int> visited) {
	queue<pair<int, int> > q;
	q.push(start);
	// visited[start] = 1;
	
	while(!q.empty()) {
		pair<int, int> cur, newcur;
		cur = q.front();
		q.pop();
		for(int i = 0 ; i < 8; i++)
		{
			newcur = make_pair(cur.first + dx[i], cur.second + dy[i]);
			
			if(binary_search(validPoints.begin(), validPoints.end(), newcur) && visited[newcur] == 0)
			{
				// cout << newcur.first << "  " << newcur.second;
				q.push(newcur);
				visited[newcur] = visited[cur] + 1;
			}
			if(newcur == end)
				return visited[newcur];
		}
	}
	return -1;
}

int main() {
	// your code goes here
	pair<int, int> start;
	pair<int, int> end;
	map<pair<int, int>, int> visited;
	int n;
	cin >> start.first >> start.second >> end.first >> end.second;
	cin >> n;
	for(int i = 0 ; i < n; i++) {
		int r, a, b;
		cin >> r >> a >> b;
		for(int j = a; j <= b; j++) {
			validPoints.push_back(make_pair(r, j));
		}
	}
	
	sort(validPoints.begin(), validPoints.end());
	
	visited[start] = 0;
	visited[end] = 0;
	
	for(int i = 0 ; i < n; i++) {
		if(visited.find(validPoints[i]) == visited.end()) {
			visited[validPoints[i]] = 0;
		}
	}
	
	// for(int i = 0 ; i < validPoints.size(); i++) {
	// 	cout << "(" << validPoints[i].first << ", " << validPoints[i].second << ")" << endl;	
	// }
	
	cout << bfs(start, end, visited) << endl;
	return 0;
}