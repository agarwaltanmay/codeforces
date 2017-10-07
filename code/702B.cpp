#include <bits/stdc++.h>

using namespace std;
int n;
int arr[100000 + 2];
map<int, int> intexist;
map<int, int>::iterator it;

int main() {
	// your code goes here
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		intexist[arr[i]]++;
	}
	long long res = 0;
	
	for(int i = 1; i <= n; i++) {
		for(long long k = 2; k < (1LL << 32); k <<= 1) {
			if(arr[i] < k) {
				it = intexist.find(k - arr[i]); 
				if(it != intexist.end()) {
					res += it->second;
					if(k - arr[i] == arr[i])
						res--;
				}
			}
		}
	}
	cout << (res >> 1) << endl;	
	return 0;
}