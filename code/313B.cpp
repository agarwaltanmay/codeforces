#include <iostream>

using namespace std;
char inp[100000 + 2];
int pp[100000 + 2];

int compute(int l, int r) {
	if(l >= r)
		return 0;
	
	int ans;
	ans = pp[r] - pp[l];
	
	return ans;
}

int main() {
	// your code goes here
	
	int m, len = 0;
	cin >> inp;
	for(int i = 0; inp[i] != '\0'; i++)
		len++;
	
	pp[1] = 0;
	for(int i = 2; i <= len; i++) {
		if(inp[i - 2] == inp[i - 1]) {
			pp[i] = pp[i - 1] + 1; 
		}
		else
			pp[i] = pp[i - 1];
	}
	
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		int ans = compute(l, r);
		cout << ans << endl;
	}
	
	return 0;
}