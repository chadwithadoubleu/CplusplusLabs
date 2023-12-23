#include <iostream>

using namespace std;


int mult(int a, int b);
int fib(int index);
int nonRecFib(int index);

int main()
{
	cout << "Recursive Fibonacci:      " << fib(0) << " " << fib(3) << " " << fib(11) << endl;
	cout << "Non-recursive Fibonacci:  " << nonRecFib(1) << " " << nonRecFib(5) << " " << nonRecFib(14) << endl;
	cout << "Recursive multiplication: " << mult(0, 4) << " " << mult(3, 1) << " " << mult(7, 8) << " " << mult(5, 0) << endl;
}

int mult(int a, int b)
{
	if (b == 0 || a == 0)
		return 0;
	else if (b == 1)
		return a;
	else
		return mult(a, b - 1) + a;
}

int fib(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return fib(index - 1) + fib(index - 2);
}

int nonRecFib(int index)
{
	int a = 0;
	int b = 1;
	int total = 0;
	for (int i = 0; i < index; i++)
	{
		total = a + b;
		a = b;
		b = total;
	}
	return a;

}