#include <iostream>

using namespace std;

void magicSquare(int);
long reversedInt(long);
int LCM(int, int);

int main()
{
	cout << "4 Magic Squares:" << endl; magicSquare(4);
	cout << endl << "Reversed integer" << endl;
	cout << 123 << "-->" << reversedInt(123) << endl;
	cout << "LCM:" << endl;
	cout << "12,15 LCM = " << LCM(12, 15);
}

void magicSquare(int nums)
{
	int index = 0;
	int num = 0;
	while (index < nums)
	{
		long total = pow(num, 2);

		long temp = 0;
		for (int i = 0; i < total; i++)
		{
			temp += i;
			if (total == temp)
			{
				cout << total << " ";
				i = total;
				index++;
			}
			else if (temp > total)
				i = total;
		}
		num++;
	}
}

long reversedInt(long temp)
{
	long val = 0;

	while (temp > 0)
	{
		val *= 10;
		val += temp % 10;
		temp /= 10;
	}
	return val;
}

int LCM(int a, int b)
{
	int aTotal = a;
	int bTotal = b;
	while (aTotal != bTotal)
	{
		if (aTotal > bTotal)
			bTotal += b;
		else
			aTotal += a;
	}
	return aTotal;
}