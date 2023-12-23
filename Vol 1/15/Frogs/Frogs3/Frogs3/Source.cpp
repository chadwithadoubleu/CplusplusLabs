#include <iostream>
#include "frog.h"

using namespace std;

int main()
{
	frog frog1;
	frog frog2;

	int stepCount;
	int samePos = 0;

	cout << "Enter the amount of steps ---> ";
	cin >> stepCount;
	for (int i = 0; i < stepCount; i++)
	{
		frog1.move();
		frog2.move();

		int pos1 = frog1.getPos();
		int pos2 = frog2.getPos();

		int lower;
		int higher;
		if (pos1 < pos2)
		{
			higher = pos2;
			lower = pos1;
		}
		else
		{
			higher = pos1;
			lower = pos2;
		}

		for (int j = 0; j < 40 + lower; j++)
			cout << " ";
		cout << "*";
		
		for (int j = 0; j < higher - lower; j++)
			cout << " ";

		if (higher != lower)
			cout << "*";
		else
			samePos++;

		cout << endl;
	}

	cout << "frog 1 final position =      " << frog1.getPos() << endl;
	cout << "frog 2 final position =      " << frog2.getPos() << endl << endl;
	cout << "frogs in the same position = " << samePos;

	return 0;
}
