#include <bits/stdc++.h>

using namespace std;
vector<int> b;
vector<int> g;
bool bdone[100] = {0};
bool gdone[100] = {0};
int no;

int main(){
	int n, m;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		b.push_back(a);
	}
	
	cin >> m;
	
	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		g.push_back(a);
	}

	sort(b.begin(), b.end());
	sort(g.begin(), g.end());

	no = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) {
			if(!gdone[j]) {
				if (abs(b[i] - g[j]) <= 1) {
					// cout << b[i] << " " << g[j] << endl;
					bdone[i] = 1;
					gdone[j] = 1;
					no++;
					break;
				}
			}
		}
	}

	cout << no << endl;

}