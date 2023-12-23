#include <iostream>
#include "frog.h"

using namespace std;

int main()
{
	frog frog1;

	int distance;

	cout << "Enter the distance from the orgin ---> ";
	cin >> distance;
	while (frog1.getPos() != distance && frog1.getPos() * -1 != distance)
	{
		frog1.move();

		int blanks = 40 + frog1.getPos();
		for (int j = 0; j < blanks; j++)
			cout << " ";
		cout << "*" << endl;
	}
	cout << "number of steps = " << frog1.stepCount() << endl;
	return 0;
}
