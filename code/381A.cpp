#include <iostream>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int scoreA = 0;
	int scoreB = 0;
	int scores[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> scores[i];
	}
	int j = n-1;
	int i = 0;
	bool A = true;
	while (i <= j)
	{
		if (scores[i] > scores[j])
		{
			if (A)
				scoreA += scores[i];
			else
				scoreB += scores[i];
			i++;
		}
		else
		{
			if (A)
				scoreA += scores[j];
			else
				scoreB += scores[j];
			j--;
		}

		if (A)
			A = false;
		else
			A = true;
	}
	cout << scoreA << " " << scoreB << endl;
	return 0;
}