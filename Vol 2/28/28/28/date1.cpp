#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	date  day1(6, 27, 96), day2;

	day2 = day1++;

	date day3;

	cout << "For day3: " << endl;
	cin >> day3;

	cout << "day1 = " << day1 << endl << "day2 = " << day2 << endl << "day3 = " << day3 << endl;

	if (day1 > day2)
	{
		cout << "day1 > day2" << endl;
	}
	if (day2 < day1)
	{
		cout << "day2 < day1" << endl;
	}
	if (day2 > day3)
	{
		cout << "day2 > day3" << endl;
	}
	if (day1 > day3)
	{
		cout << "day1 > day3" << endl;
	}
	


}