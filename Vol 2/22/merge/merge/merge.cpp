#include <iostream>
#include <iomanip>
#include "dice.h"
#include <vector>

const int SIZE = 200;

void fillArray(vector<int>& temp);
void screenOutput(const vector<int>& temp);
void swap(int& a, int& b);
void selectionSort(vector<int>& list);
vector<int> merge(vector<int>& listA, vector<int>& listB);

int main()
{
	vector<int> listA(SIZE + 1);
	vector<int> listB(SIZE + 1);
	
	cout << "For the first list:  " << endl;
	fillArray(listA);
	cout << endl << "For the second list: " << endl;
	fillArray(listB);
	cout << endl;

	selectionSort(listA);
	selectionSort(listB);
	vector<int> listC = merge(listA, listB);

	cout << "List A: " << endl;
	screenOutput(listA);
	cout << "List B: " << endl;
	screenOutput(listB);
	cout << "List C: " << endl;
	screenOutput(listC);

	return 0;
}


void fillArray(vector<int>& temp)
/* Asks the user for two inputs:  1)  the number of data to generate, and
	2) the largest possible random integer to create.  Then proceeds to fill
	the array, from 1..number, where number is stored in temp[0]. */
{
	int  size;

	cout << "How many numbers to you wish to generate? ";
	cin >> temp[0];
	cout << "Largest integer to generate? ";
	cin >> size;
	dice die(size);	// allocate dice object
	for (int loop = 1; loop <= temp[0]; loop++)
		temp[loop] = die.roll();
}

void screenOutput(const vector<int>& temp)
// prints out the contents of the array in tabular form, 12 columns
{
	cout << setiosflags(ios::right) << endl;
	for (int loop = 1; loop <= temp[0]; loop++)
	{
		cout << setw(6) << temp[loop];
		if (loop % 20 == 0) cout << endl;
	}

	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

vector<int> merge(vector<int>& listA, vector<int>& listB)
{
	vector<int> merged(listA.size() + listB.size() -1);
	merged[0] = listA[0] + listB[0];
	int indexA = 1;
	int indexB = 1;
	int mergedIndex = 1;
	while (indexA <= listA[0] && indexB <= listB[0])
	{
		if (listA[indexA] > listB[indexB])
		{
			merged[mergedIndex] = listB[indexB];
			indexB++;
		}
		else
		{
			merged[mergedIndex] = listA[indexA];
			indexA++;
		}
		mergedIndex++;
	}
	while (indexA <= listA[0])
	{
		merged[mergedIndex] = listA[indexA];
		mergedIndex++;
		indexA++;
	}
	while (indexB <= listB[0])
	{
		merged[mergedIndex] = listB[indexB];
		mergedIndex++;
		indexB++;
	}
	return merged;
}

void selectionSort(vector<int>& list)
{
	int flag;

	for (int outer = 1; outer < list[0]; outer++)
	{
		flag = outer;
		for (int inner = outer + 1; inner <= list[0]; inner++)
		{
			if (list[inner] < list[flag])
			{
				flag = inner;
			}
		}
		swap(list[outer], list[flag]);
	}

}