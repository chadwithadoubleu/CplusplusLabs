#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile;

	infile.open("Numbers.txt", ios::in);

	long total = 0;
	int index = 0;
	string temp;

	while (infile >> temp)
	{
		total += stoi(temp);
		index++;
	}
	cout << "Total:        " << total << endl;
	cout << "Number count: " << index << endl;
	cout << "Average:      " << fixed << setprecision(2) << total / ((double)index);
}