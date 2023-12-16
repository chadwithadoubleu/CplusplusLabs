#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void printGrid();
void evaluateGrid();
void loadFile();
void printStats();
int countNeighbors(int row, int col);

bool grid[20][20];

int main()
{

	loadFile();
	printGrid();
	for (int i = 0; i < 5; i++)
	{
		evaluateGrid();
		printGrid();
	}
	printStats();
}

void printStats()
{
	int total = 0;
	for (int i = 0; i < size(grid); i++)
	{
		for (int q = 0; q < size(grid[0]); q++)
		{
			if (grid[i][q])
				total++;
		}
	}
	cout << "Total living cells: " << total << endl;
	total = 0;
	for (int i = 0; i < size(grid[0]); i++)
	{
		if (grid[9][i])
			total++;
	}
	cout << "Living cells in row 10: " << total << endl;

	total = 0;
	for (int i = 0; i < size(grid); i++)
	{
		if (grid[i][9])
			total++;
	}
	cout << "Living cells in column 10: " << total << endl;
}

void evaluateGrid()
{
	bool newGen[20][20];

	for (int i = 0; i < size(grid); i++)
	{
		for (int q = 0; q < size(grid[0]); q++)
		{
			int neighbors = countNeighbors(i, q);

			if (neighbors == 3)
				newGen[i][q] = true;
			else if (neighbors == 2 && grid[i][q])
				newGen[i][q] = true;
			else
				newGen[i][q] = false;
		}
	}

	for (int i = 0; i < size(grid); i++)
	{
		for (int q = 0; q < size(grid[0]); q++)
		{
			grid[i][q] = newGen[i][q];
		}
	}
}

void printGrid()
{
	cout << setw(2);
	cout << "  ";
	for (int i = 0; i < size(grid); i++)
	{
		cout << (i+1)%10 << " ";
	}
	cout << endl;
	for (int i = 0; i < size(grid); i++)
	{
		cout << setw(2) << i+1;
		for (int j = 0; j < size(grid[i]); j++)
		{
			if (grid[i][j])
				cout << "*";
			else
				cout << " ";
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void loadFile()
{

	ifstream infile;
	infile.open("life100.txt", ios::in);
	int x;
	int y;
	while (infile >> x)
	{
		infile >> y;
		grid[x-1][y-1] = true;
	}
}

int countNeighbors(int row, int col)
{
	int total = 0;
	for (int j = row - 1; j <= row + 1; j++)
	{

		if (j >= 0 && j < 20)
		{
			for (int k = col - 1; k <= col + 1; k++)
			{
				if (k >= 0 && k < 20)
				{
					if (grid[j][k] && !(row == j && k == col))
					{
						total++;
					}
				}
			}
		}
	}
	//cout << row+1 << ", " << col+1 << ": " << total << endl;
	return total;
}