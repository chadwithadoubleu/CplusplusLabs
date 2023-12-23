#include <iostream>

using namespace std;

int main()
{
	int   number = 2;
	long longerNumber = 4;
	unsigned int notSigned = 3;
	char character = '!';
	float f = 6.53;
	double d = 4.643;
	long double aLot = 543.432;
	bool notTrue = false;


	float   answer = 6.25;


	cout << "The value of an integer variable = " << number << endl;
	cout << "     The byte size of the number is " << sizeof(number) << " bytes." << endl;
	cout << "The value of a long integer variable = " << longerNumber << endl;
	cout << "     The byte size of the number is " << sizeof(longerNumber) << " bytes." << endl;
	cout << "The value of an unsigned integer variable = " << notSigned << endl;
	cout << "     The byte size of the number is " << sizeof(notSigned) << " bytes." << endl;
	cout << "The value of a character variable = " << character << endl;
	cout << "     The byte size of the character is " << sizeof(character) << " bytes." << endl;
	cout << "The value of a percision float variable = " << f << endl;
	cout << "     The byte size of the number is " << sizeof(f) << " bytes." << endl;
	cout << "The value of a double float variable = " << d << endl;
	cout << "     The byte size of the number is " << sizeof(d) << " bytes." << endl;
	cout << "The value of a long double float variable = " << aLot << endl;
	cout << "     The byte size of the number is " << sizeof(aLot) << " bytes." << endl;
	cout << "The value of a boolean variable = " << notTrue << endl;
	cout << "     The byte size of the number is " << sizeof(notTrue) << " bytes." << endl;
	return 0;
}