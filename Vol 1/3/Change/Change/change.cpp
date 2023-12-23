#include <iostream>

using namespace std;

int main()
{
	double price, paid;
	cout << "Price of purchase --> ";
	cin >> price;
	cout << "Amount paid --> ";
	cin >> paid;

	if (price > paid)
	{
		cout << endl << "Unable to purchase with amount paid." << endl;
		return;
	}
	double temp = paid - price;
	temp = temp - int(temp) + 0.000001;
	temp *= 100;
	int cents = temp;
	cout << endl << "Amount of coins needed:" << endl;
	cout << cents << "cents = " << endl << endl;
	cout << cents / 25 << " quarters" << endl;
	cents %= 25;
	cout << cents / 10 << " dimes" << endl;
	cents %= 10;
	cout << cents / 5 << " nickels" << endl;
	cents %= 5;
	cout << cents << " pennies" << endl;
}