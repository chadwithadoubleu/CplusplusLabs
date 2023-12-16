#include <iostream>
#include <iomanip>
#include "dice.h"
#include <vector>

const int SIZE = 200;

void fillArray(vector<int>& temp);
void screenOutput(const vector<int>& temp);
void swap(int& a, int& b);
void selectionSort(vector<int>& list); 
void merge(vector<int>& listA, int first, int mid, int last);
void mergeSort(vector<int>& listA, int first, int last);

int main()
{
	vector<int> list(SIZE + 1);

	fillArray(list);
	cout << endl;

	cout << "Unsorted: " << endl;
	screenOutput(list);

	mergeSort(list,1,list[0]);
	
	cout << "Sorted: " << endl;
	screenOutput(list);

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

void mergeSort(vector<int>& list, int first, int last)
{
	if (last - first == 0)
		return;
	else if (last - first == 1)
	{
		if (list[first] > list[last])
			swap(list[first], list[last]);
	}
	else
	{
		int mid = (first + last) / 2;
		mergeSort(list, first, mid);
		mergeSort(list, mid + 1, last);
		merge(list, first, mid, last);
	}

}

void merge(vector<int>& list, int first, int mid, int last)
{
	int indexA = first;
	int indexB = mid + 1;
	int mergedIndex = first;
	vector<int> merged(list.size());
	merged[0] = last - first + 1;

	while (indexA <= mid && indexB <= last)
	{
		if (list[indexA] > list[indexB])
		{
			merged[mergedIndex] = list[indexB];
			indexB++;
		}
		else
		{
			merged[mergedIndex] = list[indexA];
			indexA++;
		}
		mergedIndex++;
	}
	while (indexA <= mid)
	{
		merged[mergedIndex] = list[indexA];
		mergedIndex++;
		indexA++;
	}
	while (indexB <= last)
	{
		merged[mergedIndex] = list[indexB];
		mergedIndex++;
		indexB++;
	}
	for (int i = first; i <= last; i++)
	{
		list[i] = merged[i];
	}
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