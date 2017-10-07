#include <iostream>

using namespace std;

int main() {
	int n, s, t;
	cin >> n >> s >> t;
	
	int arr[n + 1];
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	int count = 0;
	bool res = true;
	bool visited[n + 1] = {false};
	for(int i = s; i != t; i = arr[i])
	{
		count++;
		if (!visited[i])
			visited[i] = true;
		else
		{
			cout << "-1" << endl;
			res = false;
			break;
		}
	}
	
	if (res)
		cout << count << endl;
	
	return 0;
}