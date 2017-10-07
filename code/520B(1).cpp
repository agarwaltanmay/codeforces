#include <bits/stdc++.h>

using namespace std;
int minsteps = INT_MAX;


int button(int n, int m) {
	int count = 0;
	int temp = m;
	while(temp > n)
	{
		count++;
		if(temp % 2 == 0)
			temp /= 2;
		else
		{
			// count++;
			temp += 1;
		}
	}
	if(n != temp)
		count += (n - temp);
	
	return count;

}

int main() {
	int n, m;
	cin >> n >> m;

	if(m < n)
	{
		cout << (n - m) << endl;
		return 0;
	}
	
	cout << button(n, m) << endl;
	return 0;
}