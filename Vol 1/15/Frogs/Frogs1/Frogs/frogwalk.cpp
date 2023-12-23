#include <iostream>
#include "frog.h"

using namespace std;

int main()
{

	frog frog1;

	int numSteps;

	cout << "Enter # of steps ---> ";
	cin >> numSteps;
	for (int k = 0; k < numSteps; k++)
	{
		frog1.move();


		int blanks = 40 + frog1.getPos();
		for (int j = 0; j < blanks; j++)
			cout << " ";
		cout << "*" << endl;

	}
	cout << "final position = " << frog1.getPos() << endl;
	return 0;
}
