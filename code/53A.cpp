#include <bits/stdc++.h>

using namespace std;

int main()

{
	char preinp[101];
	cin >> preinp;
	int n;
	cin >> n;
	vector <string> permut;
	for(int i = 0; i < n; i++)
	{
		string inp;
		cin >> inp;
		permut.push_back(inp);
	}

	sort(permut.begin(), permut.end());

	bool rest = false;
	int ind = 0;
	for(int k = 0; k < n; k++)
	{
		bool res = true;
		for(int i = 0; preinp[i] != '\0'; i++)
		{
			if(preinp[i] != permut[k][i])
			{
				res = false;
				// ind = k;
				break;
			}	
		}
		rest |= res;
		if(res)
		{
			ind = k;
			break;
		}	
		
	}

	if(rest)
		cout << permut[ind] << endl;
	else
		cout << preinp << endl;


	return 0;
}