#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const double FED = 15;
	const double FICA = 8;
	const double STATE = 3.2;
	int hours;
	double rate;
	cout << "Hours worked --> ";
	cin >> hours;
	cout << "Hourly rate -->  ";
	cin >> rate;
	double total = hours * rate;

	cout << left << fixed << setprecision(2);
	double tempFed = total * FED / 100;
	cout << setw(20) << "Federal tax (15%)" << tempFed << endl;
	double tempFica = total * FICA / 100;
	cout << setw(20) << "FICA (8%)" << tempFica << endl;
	double tempState = total * STATE / 100;
	cout << setw(20) << "State tax (3.2%)" << tempState << endl;

	total -= tempFed + tempFica + tempState;

	cout << endl << setw(20) << "Net pay" << total << endl;


}