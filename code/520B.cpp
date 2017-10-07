#include <bits/stdc++.h>

using namespace std;
int minsteps = INT_MAX;
int visited[20001] = {0};

int button(int n, int m) {
	visited[n] = 1;
	queue<int> q;
	q.push(n);
	int steps = 0;
	
	while(!q.empty()) {
		int no = q.front();
		q.pop();
		// cout << no << ' ';
		if (no == m)
		{	
			// cout << visited[no] - 1;
			return visited[no] - 1;
		}
		if(visited[no * 2] == 0 && no <= m) {
			visited[no * 2] = visited[no] + 1;
			q.push(no * 2);
		}

		if(visited[no - 1] == 0 && no > 1) {
			visited[no - 1] = visited[no] + 1;
			q.push(no - 1);
		}

		// steps += 1;
		// cout << "steps = " << steps << endl;

	}

}

int main() {
	int n, m;
	cin >> n >> m;

	if(m < n)
	{
		cout << (n - m) << endl;
		return 0;
	}
	
	cout << button(n, m) << endl;
	return 0;
}