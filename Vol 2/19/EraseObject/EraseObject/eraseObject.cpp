#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void loadFile(vector<vector<bool>>& grid);
void erase(vector<vector<bool>>& grid, int row, int col);
void printTable(vector<vector<bool>>& grid);

int main()
{
	vector<vector<bool>> grid(20, vector<bool>(20));
	int xCoord, yCoord;
	
	loadFile(grid);

	do
	{
		printTable(grid);

		cout << "Enter the x-coordinate of the object to delete: ";
		cin >> xCoord;
		cout << "Enter the y-coordinate of the object to delete: ";
		cin >> yCoord;

		erase(grid,xCoord,yCoord);
	} while (xCoord != -1 && yCoord != -1);
	
}

void loadFile(vector<vector<bool>> &grid)
{
	ifstream infile;
	infile.open("digital.txt", ios::in);
	int x;
	int y;

	while (infile >> x)
	{
		infile >> y;
		grid[x-1][y-1] = true;
	}
}

void erase(vector<vector<bool>> &grid, int row, int col)
{
	grid[row - 1][col - 1] = false;
}

void printTable(vector<vector<bool>> &grid)
{
	cout << "  ";
	for (int i = 0; i < grid.size(); i++)
	{
		cout << setw(2) << (i+1)%10;
	}
	cout << endl;

	for (int i = 0; i < grid.size(); i++)
	{
		cout << setw(2) << i + 1;
		for (int q = 0; q < grid[i].size(); q++)
		{
			cout << setw(2);
			if (grid[q][i])
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}