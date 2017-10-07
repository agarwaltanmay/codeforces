#include <bits/stdc++.h>

using namespace std;

bool res = true;

int hori = 0;
int vert = 0;

struct seg{
	pair<int, int> s;
	pair<int, int> e;
};

inline bool isHori(seg a)
{
	return (a.s.second == a.e.second);
}

inline bool isvert(seg a)
{
	return (a.s.first == a.e.first);
}


int main()
{
	seg arr[4];
	for(int i = 0; i < 4; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i].s = make_pair(a, b);
		arr[i].e = make_pair(c, d);
	}

	for(int i = 0; i < 4; i++)
	{
		 if((arr[i].s.first != arr[i].e.first) == (arr[i].s.second != arr[i].e.second))
		 {
		 	cout << "NO";
		 	return 0;
		 }
	}

	for(int i = 0; i < 4; i++)
	{
		if(isHori(arr[i]))
			hori++;
		else if(isvert(arr[i]))
			vert++;
	}

	if(hori != 2 || vert != 2)
	{
		cout << "NO";
		return 0;
	}

	vector<int> y;
	vector<int> x;
	for(int i = 0; i < 4; i++)
	{
		if(isHori(arr[i]))
			y.push_back(arr[i].s.second);
		else if(isvert(arr[i]))
			x.push_back(arr[i].s.first);
	}

	if(abs(y[0] - y[1]) < 1 || abs(x[0] - x[1]) < 1){
		cout << "NO";
		return 0;
	}

	

	bool check[4][2] = {0};
	for(int i = 0; i < 4; i++)
	{
		for(int j = i + 1; j < 4; j++)
		{
			if (arr[i].s == arr[j].s)
			{
				check[i][0] = 1;
				check[j][0] = 1;
			}
			else if (arr[i].s == arr[j].e)
			{
				check[i][0] = 1;
				check[j][1] = 1;
			}
			if (arr[i].e == arr[j].s)
			{
				check[i][1] = 1;
				check[j][0] = 1;
			}
			else if (arr[i].e == arr[j].e)
			{
				check[i][1] = 1;
				check[j][1] = 1;
			}
		}
	}

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if (!check[i][j])
			{
				res = false;
				break;
			}
		}
		if(!res)
			break;
	}

	if (res)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}