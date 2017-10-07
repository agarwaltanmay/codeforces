#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr[n];
	vector<int*> res;
	pair <int, int> lookup[2501];
	int c[n];
	int count = 0;

	for(int	i = 0; i < n; i++)
	{
		cin >> c[i];
	} 

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < c[i]; j++)
		{
			int x;
			cin >> x;
			arr[i].push_back(x);
			lookup[x] = make_pair(i, j);
		}
	}

	int val = 1;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < c[i]; j++)
		{
			pair <int, int> pos = lookup[val];
			if (pos != make_pair(i, j)) {
				int num = arr[i][j];
				swap(arr[pos.first][pos.second], arr[i][j]);
				lookup[num] = pos;
				int* a = new int[4];
				a[0] = i + 1;
				a[1] = j + 1;
				a[2] = pos.first + 1;
				a[3] = pos.second + 1;
				res.push_back(a);
			}
			val++;

		}
	}
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 4; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
 