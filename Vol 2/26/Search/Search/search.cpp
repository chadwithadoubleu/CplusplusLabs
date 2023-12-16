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
void testSearch(const storeType& store);
int bsearch(const storeType& store, int idToSearch);
int bsearch(const storeType& store, int idToSearch, int first, int last);

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

	testSearch(data);
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

	for (int k = 1; k < temp.number + 1; k++)
	{
		cout << setw(2) << k << " " << temp.list[k - 1] << endl;
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


void testSearch(const storeType& store)
{
	int idToFind, invReturn, index;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> idToFind;
	while (idToFind >= 0)
	{
		index = bsearch(store, idToFind);
		//	index = bsearch (store, idToFind, 0, store.number-1);    recursive version call
		cout << "Id # " << idToFind;
		if (-1 == index)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << store.list[index].inv << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> idToFind;
	}
}

int bsearch(const storeType& store, int idToSearch)
{
	/*	precondition:  store.list is sorted by the id field.  store.number stores how many items are in the array.
	data is stored in the array list from positions 0..store.number-1.

	postcondition:  if idToSearch exists in the array, the function returns the index position of the item, otherwise it returns -1.  */

	int low = 0;
	int high = store.number - 1;
	int mid = (low + high) / 2;
	int foundId = store.list[mid].id;

	while (low != high && foundId != idToSearch)
	{
		if (foundId > idToSearch)
			high = mid;
		if (foundId < idToSearch)
			low = mid + 1;

		mid = (low + high) / 2;
		foundId = store.list[mid].id;
	}

	if (foundId != idToSearch)
		return -1;
	return mid;
}

int bsearch(const storeType& store, int idToSearch, int first, int last)
{
	//	recursive version, searches range from first to last of the array

	int mid = (first + last) / 2;
	int foundId = store.list[mid].id;
	
	if (foundId == idToSearch)
		return mid;
	if (first == last)
		return -1;
	if (foundId < idToSearch)
		return bsearch(store, idToSearch, mid + 1, last);
	else
		return bsearch(store, idToSearch, first, mid);
}