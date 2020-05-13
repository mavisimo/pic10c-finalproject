/*
Nonogram game project
Random row generator - given the length of the row (say 15 for a 15x15 grid game),
randomly generate how many in that length should be filled and which should be
blank. The list of numbers should sum up to the length.
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

vector<int> random_row(int n)
{
	vector<int> blocks;
	while (n>0) 
	{
		int x = 1 + (rand() % n);
		if (x <= n) { blocks.push_back(x); n -= x; }
	}
	return blocks;
}


int main()
{
	srand(time(0));
	int length = 0;

	cout << "Input row length: ";
	cin >> length;
	vector<int> blocks = random_row(length);
	cout << endl << "Random block sequence is: ";
	for(int i=0; i < blocks.size(); i++) { cout << blocks[i] << " "; }

	return 0;
}

