#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double principal,rate,pay;
	cout << "Principal (amount borrowed) --> ";
	cin >> principal;
	cout << "Annual interest rate --> ";
	cin >> rate;
	cout << "Monthly payment --> ";
	cin >> pay;


	double total = principal;
	double interest;

	cout << fixed << setprecision(2);
	cout << endl << setw(15) << "Month" << setw(15) << "Principal" << setw(15) << "Interest" << setw(15) << "Payment" << setw(15) << "New Balance" << endl << endl;
	
	int month = 1;
	double totalInterest = 0;
	do
	{
		interest = total * (rate / 100 /12);
		totalInterest += interest;
		cout << setw(15) << month << setw(15) << total << setw(15) << interest << setw(15) << pay;
		total += interest - pay;
		cout << setw(15) << total << endl;
		month++;
	} while (total > pay);

	cout << endl << setw(30) << "Principal = " << principal << endl;
	cout << setw(30) << "Annual interest rate = " << rate << "%" << endl;
	cout << setw(30) << "Monthly payment = " << pay << endl;
	cout << endl << setw(30) << "" << totalInterest << " total interest" << endl;

}
