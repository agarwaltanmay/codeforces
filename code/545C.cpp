#include <iostream>

using namespace std;

// map<int, int> visited;

// int oldmaxtrees(int i, int n) {
// 	if(i >= n)
// 		return 0;

// 	int ans = -1;

// 	bool lcheck = true;
// 	bool rcheck = true;

// 	for(int j = 1; j <= h[i]; j++) {
// 		lcheck &= visited.find(x[i] - j) == visited.end();
// 	}

// 	for(int j = 1; j <= h[i]; j++) {
// 		rcheck &= visited.find(x[i] + j) == visited.end();
// 	}

// 	if(lcheck)
// 	{
// 		for(int j = 1; j <= h[i]; j++) {
// 			visited[x[i] - j] = 1;
// 		}
// 		ans = max(ans, maxtrees(i + 1, n) + 1);
// 		for(int j = 1; j <= h[i]; j++) {
// 			visited.erase(x[i] - j);
// 		}
// 	}

// 	if(rcheck)
// 	{
// 		for(int j = 1; j <= h[i]; j++) {
// 			visited[x[i] + j] = 1;
// 		}
// 		ans = max(ans, maxtrees(i + 1, n) + 1);
// 		for(int j = 1; j <= h[i]; j++) {
// 			visited.erase(x[i] + j);
// 		}
// 	}

// 	ans = max(ans, maxtrees(i + 1, n));
	
// 	return ans;
// }

#define N 100000
int n;
int x[N + 2];
int h[N + 2];

int maxtrees(int i, int pchoice) {
	
	if(i == 0) {
		// cout << "(" << i << ", " << "-1)" << endl;
		return maxtrees(i + 1, -1) + 1;
	}

	if(i == n - 1)
	{
		// cout << "(" << i << ", " << "1)" << endl;
		return 1;	
	}

	if(pchoice == -1 || pchoice == 0) {
		if(x[i] - h[i] > x[i - 1]) {
			// cout << "(" << i << ", " << "-1)" << endl;
			return maxtrees(i + 1, -1) + 1;
		}
		else if(x[i] + h[i] < x[i + 1]) {
			// cout << "(" << i << ", " << "1)" << endl;
			return maxtrees(i + 1, 1) + 1;
		}
		else {
			// cout << "(" << i << ", " << "0)" << endl;
			return maxtrees(i + 1, 0);
		}
	}
	else
	{
		if(x[i] - h[i] > x[i - 1] + h[i - 1]) {
			// cout << "(" << i << ", " << "-1)" << endl;
			return maxtrees(i + 1, -1) + 1;
		}
		else if(x[i] + h[i] < x[i + 1]) {
			// cout << "(" << i << ", " << "1)" << endl;
			return maxtrees(i + 1, 1) + 1;
		}
		else {
			// cout << "(" << i << ", " << "0)" << endl;
			return maxtrees(i + 1, 0);
		}
	}
}
int main() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> x[i] >> h[i];
	}

	if (n <= 2) {
		cout << n;
		return 0;
	}

	int ans = maxtrees(0, -1);

	cout << ans << endl;
	return 0;
}