#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	vector<char> grades;
	char grade;
	do
	{
		cout << "Next Class (Q to stop) --> ";
		cin >> grade;
		if (grade != 'Q' && grade != 'q')
		{
			grades.push_back(grade);
		}
	} while (grade != 'Q' && grade != 'q');
	
	
	bool hasF = false;
	double gpa = 0;
	for (int i = 0; i < grades.size(); i++)
	{
		char temp = grades[i];
		if (temp == 'F')
			hasF = true;
		if (temp == 'A')
			gpa += 4;
		if (temp == 'B')
			gpa += 3;
		if (temp == 'C')
			gpa += 2;
	}
	gpa /= grades.size();
	cout << fixed << setprecision(2) << "GPA = " << gpa << "    ";
	if (grades.size() < 4)
		cout << "Ineligable, taking less than 4 classes" << endl;
	else if (gpa >= 2 && hasF)
		cout << "Ineligable, gpa above 2.0 but has F grade" << endl;
	else if (gpa <= 2 && hasF)
		cout << "Ineligable, gpa below 2.0 and has F grade" << endl;
	else if (gpa <= 2)
		cout << "Ineligable, gpa below 2.0" << endl;
	else
		cout << "Eligable" << endl;
}