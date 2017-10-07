#include <iostream>

using namespace std;

int main(){
	int n, s;
	cin >> n >> s;
	int d[n];
	int c[n];
	for(int i = 0; i < n; i++)
		cin >> d[i] >> c[i];

	int maxC = -1;
	for(int i = 0; i < n; i++){
		if(s > d[i] || (s == d[i] && c[i] == 0)){
			if (maxC < (100-c[i]) % 100)
				maxC = (100-c[i]) % 100;
		}
	}
	cout << maxC << endl;
 	return 0;
}