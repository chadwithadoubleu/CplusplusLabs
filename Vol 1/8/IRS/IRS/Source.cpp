#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	bool married;
	double income;
	cout << "Maritial status (1 for Married, 0 for Single) --> ";
	cin >> married;
	cout << "Taxable income -->";
	cin >> income;

	double tax = 0;
	if (married)
	{
		if (income <= 41200)
			tax = income * 0.15;
		else if (income <= 99600)
			tax = (income - 41200) * 0.28 + 6180;
		else
			tax = (income - 99600) * 0.31 + 22532;
	}
	else
	{
		if (income <= 24650)
			tax = income * 0.15;
		else if (income <= 59750)
			tax = (income - 24650) * 0.28 + 3697.5;
		else
			tax = (income - 59750) * 0.31 + 13525.5;
	}

	cout << fixed << setprecision(2) << endl;
	cout << setw(20) << "Filing status = ";
	if (married)
		cout << "married";
	else
		cout << "single";
	cout << endl;
	cout << setw(20) << "Taxable income = " << income << endl;
	cout << setw(20) << "Federal tax = " << tax;
	
}