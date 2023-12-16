#include <iostream>
#include <vector>
#include "dice.h"
#include <iomanip>

using namespace std;

bool move();
void printTable();
void initializeMovement();

int row;
int col;
int moveNum;

vector<vector<int>> board(8, vector<int>(8,0));
vector<vector<int>> movement(8, vector<int>(2));

int main()
{
	moveNum = 1;
	row = 0;
	col = 0;

	
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

	vector<int> posMoves(0);

	//cout << "1";
	for (int i = 0; i < size(movement); i++)
	{
		//cout << "l" << i;
		int x = row + movement[i][0];
		int y = col + movement[i][1];
		
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			//cout << "C";
			if (board[x][y] == 0)
			{
				//cout << "D";
				posMoves.push_back(i);
			}
		}
	}
	//cout << posMoves.size();
	if (posMoves.size() == 0)
	{
		return false;
	}
	int chosenMove = posMoves[dice(posMoves.size()).roll()-1];

	row += movement[chosenMove][0];
	col += movement[chosenMove][1];
	return true;
}

void printTable()
{
	cout << "    ";
	for (int i = 0; i < size(board); i++)
	{
		cout.width(4);
		cout << i+1;
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