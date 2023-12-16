#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));

	int roll1, roll2, roll3;
	int rolls = 0;

	do
	{
		rolls++;

		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;
		roll3 = rand() % 6 + 1;

		cout << roll1 << " " << roll2 << " " << roll3 << endl;
	} while (roll1 == roll2 || roll1 == roll3 || roll2 == roll3);
	cout << "count = " << rolls;

}