#include <iostream>

using namespace std;


void get2Values(int& temp1, int& temp2);
void get2Values(double& temp1, double& temp2);
void print2Values(int& temp1, int& temp2);
void print2Values(double& temp1, double& temp2);
void swap(int& temp1, int& temp2);
void swap(double& temp1, double& temp2);

int main()
{
	int num1, num2;
	double d1, d2;

	get2Values(num1, num2);
	get2Values(d1, d2);
	print2Values(num1, num2);
	print2Values(d1, d2);
	swap(num1, num2);
	swap(d1, d2);
	cout << endl << "After Swapping:" << endl;
	print2Values(num1, num2);
	print2Values(d1, d2);


}

void get2Values(int& temp1, int& temp2)
{
	cout << "Value of integer 1 -->";
	cin >> temp1;
	cout << "Value of integer 2 -->";
	cin >> temp2;
}

void get2Values(double& temp1, double &temp2)
{
	cout << "Value of double 1 -->";
	cin >> temp1;
	cout << "Value of double 2 -->";
	cin >> temp2;
}

void print2Values(int& temp1, int& temp2)
{
	cout << "Integer 1 = " << temp1 << endl;
	cout << "Integer 2 = " << temp2 << endl;
}

void print2Values(double& temp1, double& temp2)
{
	cout << "Double 1 = " << temp1 << endl;
	cout << "Double 2 = " << temp2 << endl;
}

void swap(int& temp1, int& temp2)
{
	int val = temp1;
	temp1 = temp2;
	temp2 = val;
}

void swap(double& temp1, double& temp2)
{
	double val = temp1;
	temp1 = temp2;
	temp2 = val;
}