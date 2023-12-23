#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c;
	cout << "Variable a = ";
	cin >> a;
	cout << "Variable b = ";
	cin >> b;
	cout << "Variable c = ";
	cin >> c;

	double root1 = ((-1 * b) - sqrt((b * b) - (4 * a * c))) / (2 * a);
	double root2 = ((-1 * b) + sqrt((b * b) - (4 * a * c))) / (2 * a);
	cout << setprecision(6);
	cout << endl << "root 1 = " << root1 << endl;
	cout << "root 2 = " << root2 << endl;
}