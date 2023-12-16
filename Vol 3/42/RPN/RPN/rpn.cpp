#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	queue<char> equation;
	stack<int> calc;

	char input = ' ';
	while (input != 'q' && input != 'Q')
	{
		cout << "Enter the next input or operation (q to quit): ";
		cin >> input;

		if (calc.size() >= 2 && (input == '*' || input == '/' || input == '+' || input == '-'))
		{
			equation.push(input);

			int num1 = calc.top();
			calc.pop();
			int num2 = calc.top();
			calc.pop();

			if (input == '*')
				calc.push(num1 * num2);
			else if (input == '/')
				calc.push(num2 / num1);
			else if (input == '+')
				calc.push(num2 + num1);
			else if (input == '-')
				calc.push(num2 - num1);
		}
		else if (input >= '1' && input <= '9')
		{
			equation.push(input);
			calc.push(input - '0');
		}
		else if (input != 'Q' && input != 'q')
			cout << "Invalid Input" << endl;
	}

	if (!calc.empty())
	{
		while (!equation.empty())
		{
			cout << equation.front() << " ";
			equation.pop();
		}
		cout << "= " << calc.top();
	}
}