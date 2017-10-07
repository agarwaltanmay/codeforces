#include <bits/stdc++.h>

using namespace std;



int diff(int a, int b) {
	if(a <= b)
		return (b - a);
	else
		return (12 - a + b);
}


int main() {
	// C, C#, D, D#, E, F, F#, G, G#, A, B, H
	char inp[3];
	int c[3];
	for(int i = 0; i < 3; i++)
	{
		cin >> inp;
		if(inp[1] == '#') {
			if(inp[0] == 'C')
				c[i] = 2;
			else if(inp[0] == 'D')
				c[i] = 4;
			else if(inp[0] == 'F')
				c[i] = 7;
			else if(inp[0] == 'G')
				c[i] = 9;
		}
		else {
			if(inp[0] == 'C')
				c[i] = 1;
			else if(inp[0] == 'D')
				c[i] = 3;
			else if(inp[0] == 'E')
				c[i] = 5;
			else if(inp[0] == 'F')
				c[i] = 6;
			else if(inp[0] == 'G')
				c[i] = 8;
			else if(inp[0] == 'A')
				c[i] = 10;
			else if(inp[0] == 'B')
				c[i] = 11;
			else if(inp[0] == 'H')
				c[i] = 12;
		}	
	}
	// 0 1 2
	// 1 0 2
	// 0 2 1
	// 1 2 0
	// 2 0 1
	// 2 1 0
	if((diff(c[0], c[1]) == 4 && diff(c[1], c[2]) == 3) || (diff(c[1], c[0]) == 4 && diff(c[0], c[2]) == 3) || (diff(c[0], c[2]) == 4 && diff(c[2], c[1]) == 3) || (diff(c[1], c[2]) == 4 && diff(c[2], c[0]) == 3) || (diff(c[2], c[0]) == 4 && diff(c[0], c[1]) == 3) || (diff(c[2], c[1]) == 4 && diff(c[1], c[0]) == 3))
		cout << "major" << endl;
	else if((diff(c[0], c[1]) == 3 && diff(c[1], c[2]) == 4) || (diff(c[1], c[0]) == 3 && diff(c[0], c[2]) == 4) || (diff(c[0], c[2]) == 3 && diff(c[2], c[1]) == 4) || (diff(c[1], c[2]) == 3 && diff(c[2], c[0]) == 4) || (diff(c[2], c[0]) == 3 && diff(c[0], c[1]) == 4) || (diff(c[2], c[1]) == 3 && diff(c[1], c[0]) == 4))
		cout << "minor" << endl;
	else
		cout << "strange";

	return 0;
}