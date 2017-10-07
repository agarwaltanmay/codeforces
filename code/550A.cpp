#include <bits/stdc++.h>

using namespace std;

int main() {
	string inp;
	cin >> inp;

	size_t ind1 = inp.find("AB");
	size_t ind2 = inp.find("BA");

	// bool ab, ba;
	// int abi, bai;
	// abi = bai = -1;
	// ab = ba = false;

	// for(int i = 1; inp[i] != '\0'; i++){
	// 	if(inp[i] == 'B' && inp[i- 1] == 'A') {
	// 		ab = true;
	// 		abi = i;
	// 		i++;
	// 	}
	// 	else if(inp[i] == 'A' && inp[i - 1] == 'B'){
	// 		ba = true;
	// 		bai = i;
	// 		i++;
	// 	}
	// }

	// if(ab && ba && abs(abi - bai) >= 2)
	// 	cout << "YES";
	// else
	// 	cout << "NO";
		
	return 0;
}