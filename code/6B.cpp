#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char desk;
	string s;
	cin >> s;
	desk = s[0];
	string arr[n + 2];
	for(int i = 1; i < n + 1; i++)
	{
		cin >> arr[i];
	}
	arr[0] = "";
	arr[n + 1] = "";
	set<char> res;
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j < m + 1; j++)
		{
			if (arr[i][j] == desk)
			{
				if (arr[i-1][j] >= 'A' && arr[i-1][j] <= 'Z' && arr[i-1][j] != desk)
				{
					res.insert(arr[i-1][j]);
				}
				if (arr[i+1][j] >= 'A' && arr[i+1][j] <= 'Z' && arr[i+1][j] != desk)
				{
					res.insert(arr[i+1][j]);
				}
				if (arr[i][j+1] >= 'A' && arr[i][j+1] <= 'Z' && arr[i][j+1] != desk)
				{
					res.insert(arr[i][j+1]);
				}
				if (arr[i][j-1] >= 'A' && arr[i][j-1] <= 'Z' && arr[i][j-1] != desk)
				{
					res.insert(arr[i][j-1]);
				}
			}
		}
	}

	cout << res.size() << endl;
	return 0;

}