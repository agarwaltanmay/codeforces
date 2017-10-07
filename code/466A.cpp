#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

int main() {	
	cin >> n >> m >> a >> b;
	int ans = INT_MAX;	
	for(int i = 0; i <= n; i++) {
		ans = min(i * b + (n >= i * m ? n - i * m : 0) * a, ans);
	}
	cout << ans;
	return 0;
}
