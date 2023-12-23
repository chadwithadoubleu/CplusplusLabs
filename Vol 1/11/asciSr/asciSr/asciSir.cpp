#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int player = 1;
	bool player1 = true;
	int p1Pos = 0;
	int p2Pos = 0;
	int p3Pos = 0;
	bool p1Stop = false;
	bool p2Stop = false;
	bool p3Stop = false;
	int roll;
	bool won = false;
	do
	{
		if (player == 1)
		{
			if (p1Stop)
				p1Stop = false;
			else
			{
				cout << "Player A roll (0 to quit) --> ";
				cin >> roll;
				
				if (roll == 6)
					p1Stop = true;
				else if (roll != 0)
				{
					if (roll == 4)
					{
						p1Pos -= roll;
						if (p1Pos < 0)
							p1Pos = 0;
					}
					else
						p1Pos += roll;

					if (p1Pos == p2Pos)
						p2Pos = 0;
					if (p1Pos == p3Pos)
						p3Pos = 0;

					if (p1Pos >= 30)
						won = true;
				}
			}
			player++;
		}
		else if (player == 2)
		{
			if (p2Stop)
				p2Stop = false;
			else
			{
				cout << "Player B roll (0 to quit) --> ";
				cin >> roll;

				if (roll == 6)
					p2Stop = true;
				else if (roll != 0)
				{
					if (roll == 4)
					{
						p2Pos -= roll;
						if (p2Pos < 0)
							p2Pos = 0;
					}
					else
						p2Pos += roll;

					if (p2Pos == p1Pos)
						p1Pos = 0;
					if (p2Pos == p3Pos)
						p3Pos = 0;

					if (p2Pos >= 30)
						won = true;
				}
			}
			player++;
		}
		else
		{
			if (p3Stop)
				p3Stop = false;
			else
			{
				cout << "Player C roll (0 to quit) --> ";
				cin >> roll;

				if (roll == 6)
					p3Stop = true;
				else if (roll != 0)
				{
					if (roll == 4)
					{
						p3Pos -= roll;
						if (p3Pos < 0)
							p3Pos = 0;
					}
					else
						p3Pos += roll;

					if (p3Pos == p1Pos)
						p1Pos = 0;
					if (p3Pos == p2Pos)
						p2Pos = 0;

					if (p3Pos >= 30)
						won = true;
				}
			}
			player = 1;
		}
	} while (roll != 0 && !won);

	cout << "A-";
	if (p1Pos >= 30)
		cout << "END";
	else if (p1Pos <= 0)
		cout << "START";
	else
		cout << p1Pos;

	cout << ", B-";
	if (p2Pos >= 30)
		cout << "END";
	else if (p2Pos <= 0)
		cout << "START";
	else
		cout << p2Pos;

	cout << ", C-";
	if (p3Pos >= 30)
		cout << "END";
	else if (p3Pos <= 0)
		cout << "START";
	else
		cout << p3Pos;
}