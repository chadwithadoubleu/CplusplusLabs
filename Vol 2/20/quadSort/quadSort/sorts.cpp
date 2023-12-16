#include <iostream>
#include <iomanip>
#include "dice.h"
#include <vector>

const int SIZE = 500;
long steps;

void fillArray(vector<int> &temp);
void screenOutput(const vector<int>& temp);
void swap(int& a, int& b);
void bubbleSort(vector<int>& list);
void selectionSort(vector<int>& list);
void insertionSort(vector<int>& list);
void mergeSort(vector<int>& list, int first, int last);
void quickSort(vector<int>& list, int first, int last);
void sortMenu(vector<int>& temp);
void merge(vector<int>& list, int first, int mid, int last);

int main()
{
	vector<int> list(SIZE + 1);
	steps = 0;
	sortMenu(list);
	return 0;
}


void fillArray(vector<int>& temp)
/* Asks the user for two inputs:  1)  the number of data to generate, and
	2) the largest possible random integer to create.  Then proceeds to fill
	the array, from 1..number, where number is stored in temp[0]. */
{
	int  size;
	steps = 0;

	cout << "How many numbers to you wish to generate? ";
	cin >> temp[0];
	cout << endl << "Largest integer to generate? ";
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
		if (loop % 12 == 0) cout << endl;
	}

	cout << endl << endl << "steps: " << steps << endl;
	cout << endl;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(vector<int>& list)
{
	cout << endl << "Bubble Sort" << endl << endl;
	
	for (int outer = 1; outer <= list[0] - 1; outer++)
	{
		for (int inner = 1; inner <= list[0] - outer; inner++)
		{
			steps++;
			if (list[inner] > list[inner + 1])
			{
				swap(list[inner], list[inner + 1]);
				steps++;
			}
		}
	}
}

void selectionSort(vector<int>& list)
{
	cout << endl << "Selection Sort" << endl << endl;
	
	int flag;

	for (int outer = 1; outer < list[0]; outer++)
	{
		flag = outer;
		for (int inner = outer + 1; inner <= list[0];
			inner++)
		{
			steps++;
			if (list[inner] < list[flag])
			{
				flag = inner;
			}
		}
		swap(list[outer], list[flag]);
		steps++;
	}

}

void insertionSort(vector<int>& list)
{
	cout << endl << "Insertion Sort" << endl << endl;
	int outer, pos, temp;

	for (outer = 2; outer <= list[0]; outer++)
	{
		pos = outer;
		temp = list[pos];	// move list[pos] out of list
		while ((pos > 1) && (list[pos - 1] > temp))
		{
			steps++;
			list[pos] = list[pos - 1];
			pos--;
		}
		steps++;
		list[pos] = temp;
	}

}

void mergeSort(vector<int>& list, int first, int last)
{
	if (last - first == 0)
	{
		steps++;
		return;
	}
	else if (last - first == 1)
	{
		if (list[first] > list[last])
		{
			steps++;
			swap(list[first], list[last]);
		}
			
	}
	else
	{
		steps++;
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
			steps++;
			merged[mergedIndex] = list[indexB];
			indexB++;
		}
		else
		{
			steps++;
			merged[mergedIndex] = list[indexA];
			indexA++;
		}
		mergedIndex++;
	}
	while (indexA <= mid)
	{
		steps++;
		merged[mergedIndex] = list[indexA];
		mergedIndex++;
		indexA++;
	}
	while (indexB <= last)
	{
		steps++;
		merged[mergedIndex] = list[indexB];
		mergedIndex++;
		indexB++;
	}
	for (int i = first; i <= last; i++)
	{
		steps++;
		list[i] = merged[i];
	}
}

void quickSort(vector<int>& list, int first, int last)
{
	steps++;
	int g = first, h = last;
	int midIndex, dividingValue, temp;

	midIndex = (first + last) / 2;
	dividingValue = list[midIndex];
	do
	{
		while (list[g] < dividingValue) g++;
		while (list[h] > dividingValue) h--;
		if (g <= h)
		{
			steps++;
			swap(list[g], list[h]);
			g++;
			h--;
		}
	} while (g < h);
	if (h > first) quickSort(list, first, h);
	if (g < last) quickSort(list, g, last);
}


void sortMenu(vector<int>& temp)
{
	char choice, print;

	do
	{
		cout << "Sorting algorithm menu" << endl << endl;
		cout << "(1) Bubble sort" << endl;
		cout << "(2) Selection sort" << endl;
		cout << "(3) Insertion sort" << endl;
		cout << "(4) Recursive mergesort" << endl;
		cout << "(5) Quicksort" << endl;
		cout << "(6) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '5')
		{
			fillArray(temp);
			switch (choice)
			{
			case '1': bubbleSort(temp); break;
			case '2': selectionSort(temp); break;
			case '3': insertionSort(temp); break;
			case '4': mergeSort(temp,1,temp[0]); cout << endl << "Merge Sort" << endl << endl; break;
			case '5': quickSort(temp,1,temp[0]); cout << endl << "Quick Sort" << endl << endl; break;
			}
			cout << endl << "Print list to screen (y/n)? ";
			cin >> print;
			cin.get();
			if (print == 'y' || print == 'Y')
				screenOutput(temp);
			cout << endl << "Hit return to continue ";
			cin.get();
		}
	} while (choice != '6');
}
