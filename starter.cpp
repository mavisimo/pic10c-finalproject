/*
Nonogram game project
Random block generator - given the length of the row (say 15 for a 15x15 grid game),
randomly generate how many in that length should be filled and which should be
blank. The list of numbers should sum up to the length.
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

vector<int> random_block(int n)
{
	vector<int> blocks;
	while (n>0) 
	{
		int x = 1 + (rand() % n);
		if (x <= n) { blocks.push_back(x); n -= x; }
	}
	return blocks;
}


/*vector<bool> fill_generator(int n)
{
    bool start_fill = true;
	int x = rand() % 2;
	if (x == 1) start_fill = false;
	vector<bool> fills(n, start_fill);
	for (int i=1; i<n; i+=2) { fills[i] = !start_fill; }
	return fills;
}*/

vector<vector<int> > create_solution(int n)
{
	vector<vector<int> > nonogram(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        vector<int> row = random_block(n);
        int h = 0;
        bool fill = true; if ((rand() % 2) == 1) fill = false;
        for (int j = 0; j < row.size(); j++)
        {
            while (row[j] > 0) { if (fill) nonogram[i][h] = 1; row[j] -= 1; h++; }
            fill = !fill;
        }
    }
    return nonogram;
}


int main()
{
	srand(time(0));
	int length = 0;

	cout << "Input row length: ";
	cin >> length;
    
    vector<vector<int> > nonogram = create_solution(length);
    cout << "Generated nonogram solution: " << endl;
    for (int i = 0; i < nonogram.size(); i++)
    {
        for (int j = 0; j < nonogram.size(); j++) 
        	cout << " " << nonogram[i][j] << " ";
        cout << endl;
    }
/*
	vector<int> blocks = random_block(length);
	static int size = blocks.size();
	vector<bool> fills = fill_generator(size);
	cout << endl << "Random block sequence is: ";
	for (int i=0; i<size; i++) { cout << blocks[i] << " "; }
	cout << endl << "Corresponding fills are: ";
	for (int i=0; i<size; i++)
	{
		if (fills[i]) cout << "Filled ";
		else cout << "Blanks ";
	}
*/
	return 0;
}

