#include <iostream>

using namespace std;

#ifndef _date_h
#define _date_h

class date {
public:
	date();	// default constructor, date is set to valid values of your choice
	date(int month, int day, int year);	// constructor with initial values of month, day, and year
	date(const date& temp);	// copy constructor, self is constructed as a copy of temp
	void setDate(int month, int day, int year);  // set values for date
	void getDate();  // get date from keyboard
	void print() const;   // public print function
	date& operator++ ();
	date operator++ (int);
	date& operator--();
	date operator--(int);
	bool operator==(const date temp);
	bool operator!=(const date temp);
	bool operator>(const date temp);
	bool operator>=(const date temp);
	bool operator<(const date temp);
	bool operator<=(const date temp);
private:
	int myMonth, myDay, myYear;
	int daysInMonth(int month, int year);	// suggested private member function
};

istream& operator>> (istream& infile, date& temp);
ostream& operator<< (ostream& outfile, date& temp);

date::date()
{
	myMonth = 0;
	myDay = 0;
	myYear = 0;
}

date::date(int month, int day, int year)
{
	myMonth = month;
	myDay = day;
	myYear = year;
}

date::date(const date& temp)
	:myMonth(temp.myMonth), myDay(temp.myDay), myYear(temp.myYear)
{

}

int date::daysInMonth(int month, int year)
{
	if (month == 2 && year % 4 == 0)
		return 29;

	int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return daysPerMonth[month - 1];
}

void date::getDate()
{
	int month;
	cout << "Month: ";
	cin >> month;
	int day;
	cout << "Day:";
	cin >> day;
	int year;
	cout << "Year:";
	cin >> year;
	setDate(month, day, year);
}

void date::print() const
{
	cout << myMonth << "/" << myDay << "/" << myYear;
}

void date::setDate(int month, int day, int year)
{
	myDay = day;
	myMonth = month;
	myYear = year;
}


ostream& operator<< (ostream& outfile, date& temp)
{
	temp.print();
	return outfile;
}
istream& operator>> (istream& infile, date& temp)  // overloaded >> operator
{
	temp.getDate();
	return infile;
}

date& date::operator++()
{
	myDay++;
	if (myDay > daysInMonth(myMonth, myYear))
	{
		myDay = 1;
		myMonth++;
		if (myMonth > 12)
		{
			myYear++;
			myMonth = 1;
		}
	}

	return *this;
}

date date::operator++(int)
{
	date temp = *this;
	++* this;
	return temp;
}

date& date::operator--()
{
	myDay--;
	if (myDay < 1)
	{
		myMonth--;
		if (myMonth < 1)
		{
			myYear--;
			myMonth = 12;
		}
		myDay = daysInMonth(myMonth, myYear);
	}
	return *this;
}

date date::operator--(int)
{
	date temp = *this;
	--(*this);
	return temp;
}

bool date::operator==(const date temp)
{
	return myMonth == temp.myMonth && myDay == temp.myDay && myYear == temp.myYear;
}

bool date::operator!=(const date temp)
{
	return myMonth != temp.myMonth || myDay != temp.myDay || myYear != temp.myYear;
}

bool date::operator>(const date temp)
{
	if (myYear > temp.myYear)
		return true;
	else if (myYear == temp.myYear)
	{
		if (myMonth > temp.myMonth)
			return true;
		else if (myMonth == temp.myMonth)
		{
			if (myDay > temp.myDay)
				return true;
		}
	}
	return false;
}

bool date::operator<(const date temp)
{
	if (temp.myYear > myYear)
		return true;
	else if (temp.myYear == myYear)
	{
		if (temp.myMonth > myMonth)
			return true;
		else if (temp.myMonth == myMonth)
		{
			if (temp.myDay > myDay)
				return true;
		}
	}
	return false;
}

bool date::operator>=(const date temp)
{
	if (myMonth == temp.myMonth && myDay == temp.myDay && myYear == temp.myYear)
		return true;

	if (myYear > temp.myYear)
		return true;
	else if (myYear == temp.myYear)
	{
		if (myMonth > temp.myMonth)
			return true;
		else if (myMonth == temp.myMonth)
		{
			if (myDay > temp.myDay)
				return true;
		}
	}
	return false;
}

bool date::operator<=(const date temp)
{
	if (myMonth == temp.myMonth && myDay == temp.myDay && myYear == temp.myYear)
		return true;

	if (temp.myYear > myYear)
		return true;
	else if (temp.myYear == myYear)
	{
		if (temp.myMonth > myMonth)
			return true;
		else if (temp.myMonth == myMonth)
		{
			if (temp.myDay > myDay)
				return true;
		}
	}
	return false;
}


#endif
