#include <iostream>
#include <iomanip>

using namespace std;

void printTable(int, int);
void pyramid(int);

int main()
{
	printTable(4, 7);
	pyramid(10);
}

void printTable(int rows, int cols)
{
	cout << setw(5) << "";
	for (int i = 1; i <= cols; i++)
		cout << setw(5) << i;
	cout << endl;
	for (int i = 1; i <= rows; i++)
	{
		cout << setw(5) << i;
		for (int q = 1; q <= cols; q++)
		{
			cout << setw(5) << q*i;
		}
		cout << endl;
	}
}

void pyramid(int lines)
{
	cout << endl;
	for (int i = 1; i <= lines; i++)
	{
		for (int q = 0; q <= lines - 1 - i; q++)
			cout << " ";
		for (int j = 0; j < 1+(2*(i-1)); j++)
			cout << "*";
		cout << endl;
	}
	cout << endl;
}