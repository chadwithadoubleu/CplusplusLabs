// ages.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// global definitions

struct item
{
	int id;
	int inv;
};

struct storeType
{
	vector<item> list;
	int number;
};


// function prototypes

void loadFile(const string&, storeType&);
void printList(const storeType&);
void swap(item&, item&);
void quickSort(vector<item>&, int, int);
ostream& operator<< (ostream& out, const item&);

int main()
{
	storeType data;

	loadFile("file50.txt", data);
	cout << "Unsorted data: " << endl << endl;
	printList(data);
	cout << endl;
	quickSort(data.list, 0, data.number - 1);
	cout << "Sorted data: " << endl << endl;
	printList(data);
	
	return 0;
}


void loadFile(const string& fileName, storeType& temp)
// precondition:  temp.list has a size of 0, will need to be resized
{
	ifstream  infile;		// open inFile, link to external file

	infile.open("file50.txt", ios::in);
	
	if (!infile.is_open())
	{
		cout << "Something";
	}
	infile >> temp.number;
	temp.number = 50;
	temp.list.resize(temp.number);
	for (int k = 0; k < temp.number; k++)
	{
		infile >> temp.list[k].id;
		infile >> temp.list[k].inv;
	}
}

void printList(const storeType& temp)
{
	cout << setw(12) << "Id" << setw(5) << " " << "Inv" << endl << endl;

	for (int k = 1; k < temp.number+1; k++)
	{
		cout << setw(2) << k << " " << temp.list[k-1] << endl;
		if (k % 10 == 0)
		{
			cout << endl;
		}
	}
		
	cout << endl;
}

void  swap(item& a, item& b)
{
	item temp = a;
	a = b;
	b = temp;
}

void quickSort(vector<item>& list, int first, int last)
{
	int g = first, h = last;
	int midIndex;
	int dividingValue;

	midIndex = (first + last) / 2;
	dividingValue = list[midIndex].id;
	do
	{
		while (list[g].id < dividingValue) g++;
		while (list[h].id > dividingValue) h--;
		if (g <= h)
		{
			swap(list[g], list[h]);
			g++;
			h--;
		}
	} while (h > g);
	if (h > first) quickSort(list, first, h);
	if (g < last) quickSort(list, g, last);
}

ostream& operator<< (ostream& out, const item& temp)
{
	cout << setiosflags(ios::right);
	out << setw(10) << temp.id << "    " << temp.inv << " ";
	return out;
}


