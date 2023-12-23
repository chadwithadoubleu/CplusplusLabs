
#include <stdlib.h>
#include <iostream>
#include "dice.h"

using namespace std;

int main()
{
	dice d1(6);
	dice d2(6);

	int dice;
	int total = 0;
	cout << "Number of Dice Rolled --> ";
	cin >> dice;

	for (int q = 2; q <= 12; q++)
	{
		for (int i = 0; i < dice; i++)
		{
			
			if (d1.roll() + d2.roll() == q)
				total++;
		}
		cout << q << "\t" << total << " / " << dice << "\t\t" << (total * 100.0 / dice) << "%" << endl;
		total = 0;
	}
	cout << endl;
	cout << "Rolls of Dice 1: " << (d1.numRolls()) << endl;
	cout << "Rolls of Dice 2: " << (d2.numRolls()) << endl;
}