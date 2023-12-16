#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct word
{
	int number = 0;
	string term = "";
};

void loadFile(vector<word>& list);
void quickSort(vector<word>& list, int first, int last);
void printResults(const vector<word>& list);
int bsearch(const vector<word>& list, string termToSearch, int first, int last);
void quickSortWord(vector<word>& list, int first, int last);
void resize(string& temp);

int wordCount;

int main()
{
	wordCount = 0;
	vector<word> words;
	
	loadFile(words);
	quickSort(words,0,words.size()-1);
	printResults(words);
}

void resize(string& temp)
{
	int index = 0;
	int length = temp.length();

	while (index < length)
	{
		char letter = temp[index];
		if (letter >= 'A' && letter <= 'Z')
			temp[index] += 32;
		else if ((letter >= 'a' && letter <= 'z') || letter == '\'')
			index++;
		else
		{
			temp.erase(index, 1);
			length--;
		}
	}
}

void loadFile(vector<word>& list)
{
	ifstream infile;
	infile.open("Dream.txt", ios::in);
	
	string temp;
	while (infile >> temp)
	{
		resize(temp);
		wordCount++;
		int listIndex = bsearch(list, temp,0,list.size()-1);


		if (listIndex == -1)
		{
			word newWord = {1,temp};
			list.push_back(newWord);
			quickSortWord(list, 0, list.size() - 1);
		}
		else
			list[listIndex].number++;
	}
}

int bsearch(const vector<word>& list, string termToSearch, int first, int last)
{
	//	recursive version, searches range from first to last of the array
	if (last == -1)
		return -1;
	int mid = (first + last) / 2;
	string foundId = list[mid].term;

	if (foundId == termToSearch)
		return mid;
	if (first == last)
		return -1;
	if (foundId.compare(termToSearch) < 0)
		return bsearch(list, termToSearch, mid + 1, last);
	else
		return bsearch(list, termToSearch, first, mid);
}

void quickSortWord(vector<word>& list, int first, int last)
{
	int g = first, h = last;
	int midIndex;
	string dividingValue;

	midIndex = (first + last) / 2;
	dividingValue = list[midIndex].term;
	do
	{
		while (list[g].term.compare(dividingValue) < 0) g++;
		while (list[h].term.compare(dividingValue) > 0) h--;
		if (g <= h)
		{
			swap(list[g], list[h]);
			g++;
			h--;
		}
	} while (h > g);
	if (h > first) quickSortWord(list, first, h);
	if (g < last) quickSortWord(list, g, last);
}

void quickSort(vector<word>& list, int first, int last)
{
	int g = first, h = last;
	int midIndex;
	int dividingValue;

	midIndex = (first + last) / 2;
	dividingValue = list[midIndex].number;
	do
	{
		while (list[g].number > dividingValue) g++;
		while (list[h].number < dividingValue) h--;
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

void printResults(const vector<word>& list)
{
	cout << "Number of words used = " << (list.size()-1) << endl;
	cout << "Total # of words = " << (wordCount-1) << endl;
	cout << endl;
	cout << setiosflags(ios::right);
	cout << setw(6) << "Index" << setw(8) << "Times" << setw(14) << "Word" << endl;

	for (int i = 1; i <= 30 && i <= list.size(); i++)
	{
		word temp = list[i - 1];
		cout << setw(6) << i << setw(8) << temp.number << setw(14) << temp.term << endl;
	}
}