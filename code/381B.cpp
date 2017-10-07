#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	int counter[5001] = {0};
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i]; 
		counter[arr[i]]++;
	}
	
	int res[10001] = {0};
	int k = 0;
	for(int i = 1; i <= max; i++)
	{
		if(counter[i] !=0)
		{
			res[k++] = i;
			counter[i]--;
		}	
	}	

	for(int i = max - 1; i >= 1; i--)
	{
		if (counter[i] != 0)
			res[k++] = i;
	}
	cout << k << endl;
	for (int i = 0; i < k; ++i)
	{
		cout << res[i] << " ";
	}
	
	cout << endl;
	

	return 0;
}