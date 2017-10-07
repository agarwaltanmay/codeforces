#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b, aa, bb;
	cin >> a >> b;
	long long i, j, dx, dy;
	i = j = 0;
	
	char s[101];
	cin >> s;
	if(i == a && j == b)
	{
		cout << "Yes" << endl;
		return 0;
	}

	int size = 0;
	for(int i = 0; s[i] != '\0'; i++)
		size++;

	for(int k = 0; k < size; k++) {
		if(s[k] == 'U')
			j++;
		else if(s[k] == 'D')
			j--;
		else if(s[k] == 'R')
			i++;
		else if(s[k] == 'L')
			i--; 
		
		if(i == a && j == b) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	dx = i;
	dy = j;
	// cout << dx << " " << dy << endl;
	if(dx == 0 && dy == 0) {
		cout << "No" << endl;
		return 0;
	}


	if(dx != 0) {
		if(dy != 0) {
			//if((double)b == (double)(dy / dx) *  a && a * dx >= 0 && b * dy >= 0)
			if(a * dx >= 0 && b * dy >= 0 && a / dx >= 1 && a % dx == 0 && b / dy >= 1 && b % dy == 0 && a / dx == b / dy)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
		else
		{
			if(a * dx >= 0 && a / dx >= 1 && a % dx == 0 && b == 0)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	else
	{
		if(b * dy >= 0 && b / dy >= 1 && b % dy == 0 && a == 0)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}

	for(int i = size - 2; i >= 0; i--) {
		aa = a;
		bb = b;
		for(int j = i; j >= 0; j--) {
			if(s[j] == 'U')
				bb--;
			else if(s[j] == 'D')
				bb++;
			else if(s[j] == 'R')
				aa--;
			else if(s[j] == 'L')
				aa++;

		}
		
		// cout << aa << " " << bb << endl;
		
		if(dx != 0) {
			if (dy != 0) {
				// if((double)bb == (double)(dy / dx) *  aa && aa * dx >= 0 && bb * dy >= 0)
				if(aa * dx >= 0 && bb * dy >= 0 && aa / dx >= 1 && aa % dx == 0 && bb / dy >= 1 && bb % dy == 0 && aa / dx == bb / dy)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
			else
			{
				if(aa * dx >= 0 && aa / dx >= 1 && aa % dx == 0 && bb == 0)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
		else
		{
			if(bb * dy >= 0 && bb / dy >= 1 && bb % dy == 0 && aa == 0)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}

	}
	cout << "No" << endl;
	return 0;
}