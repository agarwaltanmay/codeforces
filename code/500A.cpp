#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n, des;
	cin >> n >> des;
	int tun[n - 1] = {0};
	bool visited[n] = {0};
	for(int i = 0; i < n -1; i++)
		cin >> tun[i];
	
	int pos = 1;
	visited[pos - 1] = 1;
	int j = 0; 
	while(pos < des) {
		pos += tun[j];
		visited[pos - 1] = 1;
		j += tun[j];
	}
	
	if(pos == des)
		cout << "YES";
	else
		cout << "NO";
	
	
	return 0;
}