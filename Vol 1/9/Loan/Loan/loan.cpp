#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double low, high, p, n;

	cout << "Amount of the loan (principal) -->  ";
	cin >> p;
	cout << "The length of the loan in years --> ";
	cin >> n;
	cout << "Low interest rate in % --> ";
	cin >> low;
	cout << "High interest rate in % -->";
	cin >> high;

	cout << fixed;

	int payments = n * 12;


	cout << endl << left << setw(12) << "% interest" << "Monthly Payment" << endl;
	for (double i = low; i <= high; i += 0.25)
	{
		cout << left << setprecision(2) << setw(5) << i << "%";
		
		double k = i / 100 / 12;
		double c = pow(1 + k, n);
		cout << right << setw(10) << (p * (k / 12.0) * c) / (c - 1) << endl;
	}
}