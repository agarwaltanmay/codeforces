#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> dict;
	map<string, int>::iterator it;
	for(int i = 0; i < n; i++)
	{
		string inp;
		cin >> inp;
		if(dict.find(inp) != dict.end()) {
			dict.find(inp)->second += 1;
			cout << inp << dict.find(inp)->second;
			
		}
		else {
			
			dict.insert(pair<string, int>(inp, 0));
			cout << "OK";
		}
		cout << endl;
	
	}
	
	return 0;
	
}