#include <bits/stdc++.h>

using namespace std;

struct node{
	int x;
	int y;
	node(int xx, int yy){
		x = xx;
		y = yy;
	}
};

// inline bool sortx(node& a, node& b)
// {
// 	return (a.x < b.x);
// }

// inline bool sorty(node& a, node& b)
// {
// 	return (a.y < b.y);
// }

// inline bool cmp(node& a, node& b) {
// 	if (a.x < b.x) {
// 		return true;
// 	}
// 	if (a.x > b.x) {
// 		return false;
// 	}
// 	if (a.y <= b.y) {
// 		return true;
// 	}
// 	return false;
// }

vector <node> arr; 

int main()
 {
	int n;
	scanf("%d", &n);
	long long count = 0;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr.push_back(node(x, y));
	}

	map<int, int> dictx;
	map<int, int> :: iterator it;
	for(int i = 0; i < n; i++)
	{
		if(dictx.find(arr[i].x) == dictx.end())
			dictx[arr[i].x] = 1;
		else
			dictx.find(arr[i].x)->second++;
	}

	for(it = dictx.begin(); it != dictx.end(); it++)
	{
		count += (long long)it->second * (it->second - 1) / 2;
	}

	map<int, int> dicty;
	// map<int, int> :: iterator it;
	for(int i = 0; i < n; i++)
	{
		if(dicty.find(arr[i].y) == dicty.end())
			dicty[arr[i].y] = 1;
		else
			dicty.find(arr[i].y)->second++;
	}

	for(it = dicty.begin(); it != dicty.end(); it++)
	{
		count += (long long)it->second * (it->second - 1) / 2;
	}
	

	map<pair<int, int>, int> dict;
	map<pair<int, int>, int> :: iterator itt;
	for(int i = 0; i < n; i++)
	{
		if(dict.find(make_pair(arr[i].x, arr[i].y)) == dict.end())
			dict[make_pair(arr[i].x, arr[i].y)] = 1;
		else
			dict.find(make_pair(arr[i].x, arr[i].y))->second++;
	}

	for(itt = dict.begin(); itt != dict.end(); itt++)
	{
		count -= (long long)itt->second * (itt->second - 1) / 2;
	}
	
	// sort(arr.begin(), arr.end(), sortx);
	
	// for (int i = 0; i < n; i++) {
	// 	long long s = 1;
	// 	while (i + 1 < n && arr[i].x == arr[i + 1].x) {
	// 		s++; i++;
	// 	}
	// 	count += s * (s - 1) / 2;
	// }
	
	// sort(arr.begin(), arr.end(), sorty);

	// for (int i = 0; i < n; i++) {
	// 	long long s = 1;
	// 	while (i + 1 < n && arr[i].y == arr[i + 1].y) {
	// 		s++; i++;
	// 	}
	// 	count += s * (s - 1) / 2;
	// }	

	
	// sort(arr.begin(), arr.end(), cmp);
	
	// for (int i = 0; i < n; i++) {
	// 	long long s = 1;
	// 	while (i + 1 < n && arr[i].y == arr[i + 1].y && arr[i].x == arr[i + 1].x) {
	// 		s++; i++;
	// 	}
	// 	count -= s * (s - 1) / 2;
	// }

	cout << count << endl;
	return 0;
}
