#include <iostream>

using namespace std;

double fToC(double);
double cToF(double);
double sphereVol(double);
double hypotenuse(double,double);

int main()
{
	cout << "212 degrees F ---> " << fToC(212) << " degrees C" << endl;
	cout << "-15 degrees C ---> " << cToF(-15) << " degrees F" << endl;
	cout << "A sphere with a radius of 2.25 would have a volume of " << sphereVol(2.25) << endl;
	cout << "The hypotenuse of a triangle with the sides 3.0 and 4.0 would be " << hypotenuse(3.0, 4.0) << endl;
}

double fToC(double f)
{
	return 5.0 / 9 * (f - 32);
}

double cToF(double c)
{
	return (c * 9 / 5) + 32;
}

double sphereVol(double r)
{
	const double pi = 3.141592653;
	return 4.0 / 3 * pi * pow(r, 3);
}

double hypotenuse(double a, double b)
{
	return sqrt((a * a) + (b * b));
}