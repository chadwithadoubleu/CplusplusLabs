#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

bool move();
void printTable();
void initializeMovement();
void lowerProbabilities();
void loadAccessability();

int row;
int col;
int moveNum;

vector<vector<int>> board(8, vector<int>(8, 0));
vector<vector<int>> movement(8, vector<int>(2));
vector<vector<int>> access(8, vector<int>(8,0));

int main()
{
	moveNum = 1;
	row = 0;
	col = 0;

	loadAccessability();
	initializeMovement();

	while (move())
	{
		moveNum++;
	}

	printTable();

	cout << moveNum << " squares were visisted" << endl;
}

bool move()
{
	board[row][col] = moveNum;

	int chosenIndex = -1;
	int bestAccess = 8;

	for (int i = 0; i < size(movement); i++)
	{
		int x = row + movement[i][0];
		int y = col + movement[i][1];

		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (board[x][y] == 0 && access[x][y] > 0)
			{
				if (access[x][y] < bestAccess)
				{
					bestAccess = access[x][y];
					chosenIndex = i;
				}
			}
		}
	}
	if (chosenIndex == -1)
	{
		return false;
	}

	lowerProbabilities();


	row += movement[chosenIndex][0];
	col += movement[chosenIndex][1];

	access[row][col] = 0;
	return true;
}

void lowerProbabilities()
{
	for (int i = 0; i < size(movement); i++)
	{
		int x = row + movement[i][0];
		int y = col + movement[i][1];
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			access[x][y]--;
		}
	}
}

void printTable()
{
	cout << "    ";
	for (int i = 0; i < size(board); i++)
	{
		cout.width(4);
		cout << i + 1;
	}
	cout << endl;

	for (int i = 0; i < size(board[0]); i++)
	{
		cout.width(4);
		cout << i + 1;
		for (int q = 0; q < size(board); q++)
		{
			cout.width(4);
			cout << board[q][i];
		}
		cout << endl;
	}
	cout << endl;
}

void initializeMovement()
{
	movement[0] = { 1,-2 };
	movement[1] = { 2,-1 };
	movement[2] = { 2,1 };
	movement[3] = { 1,2 };
	movement[4] = { -1,2 };
	movement[5] = { -2,1 };
	movement[6] = { -2,-1 };
	movement[7] = { -1,-2 };
}

void loadAccessability()
{
	ifstream infile;
	infile.open("access.txt", ios::in);

	for (int i = 0; i < 8; i++)
	{
		for (int q = 0; q < 8; q++)
		{
			infile >> access[i][q];
		}
	}

}