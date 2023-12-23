#include <iostream>
#include <vector>

using namespace std;

int main()
{
	bool player1 = true;
	int p1Pos = 0;
	int p2Pos = 0;
	int roll;
	bool won = false;
	do
	{
		if (player1)
		{
			cout << "Player A roll (0 to quit) --> ";
			cin >> roll;
			if (roll != 0)
			{
				if (roll == 6 || roll == 4)
				{
					p1Pos -= roll;
					if (p1Pos < 0)
						p1Pos = 0;
				}
				else
					p1Pos += roll;

				if (p1Pos == p2Pos)
					p2Pos = 0;

				if (p1Pos >= 40)
					won = true;
				player1 = false;
			}
		}
		else
		{
			cout << "Player B roll (0 to quit) --> ";
			cin >> roll;
			if (roll != 0)
			{ 
				if (roll == 6 || roll == 4)
				{
					p2Pos -= roll;
					if (p2Pos < 0)
						p2Pos = 0;
				}
				else
					p2Pos += roll;

				if (p2Pos == p1Pos)
					p1Pos = 0;

				if (p2Pos >= 40)
					won = true;
				player1 = true;
			}
		}
	} while (roll != 0 && !won);

	cout << "A-";
	if (p1Pos >= 40)
		cout << "END";
	else if (p1Pos <= 0)
		cout << "START";
	else
		cout << p1Pos;

	cout << ", B-";
	if (p2Pos >= 40)
		cout << "END";
	else if (p2Pos <= 0)
		cout << "START";
	else
		cout << p2Pos;
}