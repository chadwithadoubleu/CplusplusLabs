#include <iostream>
#include "date.h"

using namespace std;

int  daysApart(date day1, date day2);
//  if day1 = day2, then the function returns 0, otherwise the function returns the number of
//  days which separates the two dates.  For example:
//	6/27/96  and  6/28/96 are 1 day apart
//	11/2/60  and  10/27/60 are 6 days apart
//	2/27/96  and  3/10/96 are 12 days apart (leap year issue)



int main()
{
	date day1, day2;
	
	while (true)
	{
		cout << "For day1:" << endl;
		cin >> day1;
		cout << endl;
		cout << "For day2:" << endl;
		cin >> day2;
		cout << endl;

		cout << day1 << " and " << day2 << " are " << daysApart(day1, day2) << " days apart." << endl << endl;
	}
}

int daysApart(date day1, date day2)
{
	int daysApart = 0;
	while (day1 > day2)
	{
		day1--;
		daysApart++;
	}
	while (day2 > day1)
	{
		day2--;
		daysApart++;
	}
	return daysApart;
}