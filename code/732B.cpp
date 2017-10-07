#include <bits/stdc++.h>

using namespace std;
int a[505];
int b[505];

int main() {
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int add = 0;
	
	if(n > 1) {
		b[0] = a[0];
		for(int i = 1; i < n; i++) {
			if(a[i] + a[i - 1] < k) {
				add += k - (a[i] + a[i - 1]);
				a[i] = a[i] + k - (a[i] + a[i - 1]);
				b[i] = a[i] + k - (a[i] + a[i - 1]);
			}
			else
				b[i] = a[i];
		}
		cout << add << endl;
		for(int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;

	}
	else {
		cout << "0" << endl << a[0];
	}

	return 0;
}