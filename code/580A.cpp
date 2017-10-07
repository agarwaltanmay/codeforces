#include <iostream>

using namespace std;
int arr[100000 + 2];
int dp[100000 + 2];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(arr[i] >= arr[i - 1])
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;
	}
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;

	return 0;
}