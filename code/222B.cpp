#include <bits/stdc++.h>

using namespace std;
int arr[1001][1001];
int row[1001] = {0};
int col[1001] = {0};
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <=n; i++)
		for(int j = 1; j <=m; j++)
			scanf("%d", &arr[i][j]);

	for(int i = 1; i <=1001; i++)
	{
		row[i] = col[i] = i;
	}

	while(k--)
	{
		char typer[2]; 
		int x, y;
		char type;
		scanf("%s %d %d", typer, &x, &y);
		type = typer[0];

		if (type == 'c')
		{
			int temp = col[x];
			col[x] = col[y];
			col[y] = temp;
		}
		else if (type == 'r')
		{
			int temp = row[x];
			row[x] = row[y];
			row[y] = temp;
		}
		else
		{
			printf("%d\n", arr[row[x]][col[y]]);
		}
	}

	return 0;
}