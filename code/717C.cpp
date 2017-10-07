#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> arr;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	long long ans = 0;
	int ind = arr.size() - 1;
	
	for(int i = 0; i < arr.size(); i++){
		ans += arr[i] * arr[ind--];
		if (ans >= 10007)
			ans = ans % 10007;
	}

	cout << ans << endl;
	return 0;
}