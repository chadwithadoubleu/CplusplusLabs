#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile;
	ofstream outfile;

	infile.open("lots of whitespace.txt", ios::in);
	cout << "stuff";
	outfile.open("()lots of whitespace.txt", ios::out);

	char letter = '\n';
	int count = 0;

	do
	{
		if (letter == '\n')
		{
			count = 0;
			bool spaces = true;
			while (spaces)
			{
				infile.get(letter);
				if (letter == ' ')
					count++;
				else if (letter == '\t')
					count += 4;
				else if (letter == '\n')
				{
					outfile << setw(2) << endl << count << "  ";
					count = 0;
				}
				else
					spaces = false;
			}
			outfile << setw(2) << endl << count << "  ";
		}
		outfile << letter;
	} while (infile.get(letter));
}