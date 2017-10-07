#include <bits/stdc++.h>

using namespace std;
int arr[100][100] = {0};

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	
	int rem;
	bool check = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(i == 0 && j == 0)
				rem = arr[i][j] % d;
			else 
				check &= (arr[i][j] % d) == rem;
		}
	}
	vector<int> sarr;
	int steps = -1;
	if(check)
	{
		steps = 0;
		for(int i = 0 ; i < n; i++) {
			for(int j = 0; j < m; j++) {
				sarr.push_back(arr[i][j]);
			}
		}
		sort(sarr.begin(), sarr.end());
		int size = sarr.size();
		int median = 0;
		if(size % 2 == 0)
			median = sarr[(size / 2) - 1];
		else
			median = sarr[(size - 1) / 2];

		for(int i = 0; i < sarr.size(); i++) {
			steps += abs(sarr[i] - median) / d;
		}
	}

	cout << steps << endl;
	return 0;
}