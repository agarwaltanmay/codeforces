#include <bits/stdc++.h>

using namespace std;

void type1(char * inp)
{
	char out[20];
	int col = 0;
	int i, j, cind;
	for(i = 0; inp[i] != '\0'; i++)
	{
		if (inp[i] == 'C')
		{
			cind = i;
			break;
		}
	}
	
	for(j = i + 1; inp[j] != '\0'; j++)
	{
		col = (col * 10) + (int)(inp[j] - 48);
	}

	int rem;
	char temp[10];
	int k = 0;
    while (col != 0)
    {
        col -= 1;
        rem = col % 26;
        temp[k++] = rem + 'A';
        col /= 26;
    }

    for (i = k - 1; i >= 0; i--)
    	cout << temp[i];

    for (i = 1; i < cind; i++)
    	cout << inp[i];

    cout << endl;

}

void type2(char * inp)
{
	char out[20];
	out[0] = 'R';
	int i, j, k = 1;
	for (i = 0; inp[i] != '\0'; i++)
	{
		if (inp[i] >= '0' && inp[i] <= '9')
			break;
	}
	
	for (j = i; inp[j] != '\0'; j++)
	{
		out[k++] = inp[j];
	}
	
	out[k] = 'C';

	int col = 0;
	for (i = 0; inp[i] != '\0'; i++)
	{
		if (inp[i] >= 'A' && inp[i] <= 'Z')
		{
			col = col * 26 + (int)(inp[i] - 64);
		}
	}
	for (i = 0; i <= k; i++)
		cout << out[i];
	cout << col << endl;

}


int main ()
{
	int T;
	cin >> T;
	while(T--)
	{
		char inp[20];
		cin >> inp;
		bool type = true;
		bool no = false;
		for (int i = 0; i < inp[i] != '\0' ; ++i)
		{
			if (no == false && inp[i] >= '0' && inp[i] <= '9')
			{
				no = true;
				continue;
			}
			if(no == true && inp[i] >= 'A' && inp[i] <= 'Z')
			{
				type = false;
				continue;
			}
		}

		if(!type)
			type1(inp);
		else
			type2(inp);

	}
	
	return 0;
}