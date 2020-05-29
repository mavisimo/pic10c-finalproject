/*
Nonogram game project
Random block generator - given the length of the row (say 15 for a 15x15 grid game),
randomly generate how many in that length should be filled and which should be
blank. The list of numbers should sum up to the length.
*/

#include <iostream>
#include <iomanip>
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

// randomly generate 0 for filled, 1 for empty space
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

// 2n rows to store columns then rows
vector<vector<int> > create_clues(int n, vector<vector<int> > solution)
{
	vector<vector<int> > clues(2*n);
	for (int i = 0; i < n; i++)
	{
		int count1=0, count2=0, j = 0;
		for (int j = 0; j < n; j++)
		{
			if ((solution[i][j] == 1 && count1 != 0) || (j == n-1)) 
			{
				if (solution[i][j]== 0) count1++;
				if (count1 > 0) clues[i].push_back(count1);
				count1 = 0;
			}
			else if (solution[i][j] == 0) count1++;
			else continue;
			if ((solution[j][i] == 1 && count2 != 0) || (j == n-1)) 
			{
				if (solution[j][i]== 0) count2++;
				if (count2 > 0) clues[n+i].push_back(count2);
				count2 = 0;
			}
			else if (solution[j][i] == 0) count2++;
			else continue;
		}
	}
	return clues;
}


void print_board(int n, vector<vector<int> > coords)
{
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++)
    	{
    		if (coords[i][j] == 0) cout << "  " << "O" << "  ";
    		else if (coords[i][j] == 1) cout << "  " << "X" << "  ";
    		else cout << "  " << "-" << "  ";
    	}
    	cout << endl;
    }
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

    vector<vector<int> > clues = create_clues(length, nonogram);
    cout << "Testing clues output: " << endl;
    for (int i = 0; i < 2*length; i++)
    {
        for (int j = 0; j < clues[i].size(); j++) 
        	cout << " " << clues[i][j] << " ";
        cout << endl;
    }

    // will be comparing coords to solution to update board
    vector<vector<int> > coords(length,vector<int>(length,2));
    cout << "Playing Board: " << endl;
    print_board(length,coords);

    int lives = 3;
    int rowNum, colNum;
    while (lives > 0)
    {
    	while(!(cin >> rowNum >> colNum) || rowNum>=length || rowNum<0 || colNum>=length || colNum<0)
    	{
        	cin.clear();
        	cin.ignore(1000, '\n');
        	cout << "Please Enter a valid coordinate:" << endl;
    	}
    	if (nonogram[rowNum][colNum] != 0) lives--;
    	coords[rowNum][colNum] == nonogram[rowNum][colNum];
    	print_board(length,coords);
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

