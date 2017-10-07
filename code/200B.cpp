#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	double ans, sum;
	sum = 0.0;
	for(int i = 0 ; i < n; i++)
		sum += arr[i];
	ans = sum / n;
	printf("%.3f", ans);
	// printf("%.4f", ans);
	// printf("%.6f", ans);
	// printf("%.8f", ans);

	return 0;

	
}