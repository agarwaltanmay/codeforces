#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int speed[n] = {0};
	int ram[n] = {0};
	int hdd[n] = {0};
	int cost[n] = {0};
	for(int i = 0; i < n; i++)
		cin >> speed[i] >> ram[i] >> hdd[i] >> cost[i];

	int ind[n];
	int k = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j)
				continue;
			if((speed[i] < speed[j] && ram[i] < ram[j] && hdd[i] < hdd[j])) {
				ind[k++] = i;
				break;
			}
		}
	}

	int mini;
	int mincost = 1001;
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == ind[j]) {
			j++;
			continue;
		}
		if(mincost > cost[i])
		{
			mincost = cost[i];
			mini = i;
		}
	}
	cout << mini + 1 << endl;

	return 0;

}