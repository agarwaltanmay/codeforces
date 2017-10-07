#include <iostream>
using namespace std;

int oarr[8][8];
int arr[8][8];
long long mindiff = 100000000;

void swaap(int *swap, int a, int b)
{
	int temp = swap[a];
	swap[a] = swap[b];
	swap[b] = temp;
}
 
long long changeArray(int *swap, int n, int k)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
			arr[i][j] = oarr[i][j];
	
	for(int i = 0; i < n; i++)
	{
		int no[k];
		for(int j = 0; j < k; j++)
			no[j] = arr[i][j];
		for(int j = 0; j < k; j++)
		{
			arr[i][j] = no[swap[j] - 1];
		}
	}
	long max = -1;
	long long min = 100000000;
	for(int i = 0; i < n; i++)
	{
		long long no = 0;
		for(int j = 0; j < k; j++)
		{
			no = no *10 + arr[i][j];
		}
		if(no >  max)
			max = no;
		if(no < min)
			min = no;
			
	}
	return (max - min);
	
}
 
long long permute(int *swap, int l, int r, int n, int size)
{
	
	if (l == r)
	{
		long long diff;
		diff = changeArray(swap, n, size);
		if(diff < mindiff)
			mindiff = diff;
	}
	else
	{
		for(int i = r; i >= l; i--)
		{
			swaap(swap, i, r);
			permute(swap, l, r - 1, n, size);
			swaap(swap, i, r);
		}
	}
	
	return mindiff;
}

int main() {
	// your code goes here
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++)
	{
		long long no;
		cin >> no;
		for(int j = k - 1; j >= 0; j--)
		{
			if(no != 0)
			{
				int rem = no % 10;
				oarr[i][j] = arr[i][j] = rem;
				no /= 10;	
			}
			else
				oarr[i][j] = arr[i][j] = 0;
		}
	}
	
	int swap[k];
	for(int i = 0; i < k; i++)
		swap[i] = i + 1;
	
	mindiff = permute(swap, 0, k - 1, n, k);
	cout << mindiff <<  endl;
	return 0;
}