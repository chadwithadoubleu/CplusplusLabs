#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/*
void loadFile(vector<string>& list);
void printList(vector<string>& list);
void printAscending(vector<string>& list);
void printAscendingWithoutSort(vector<string>& list);
*/
void testConstructors();
void testAssignment();
void testAccessors();
void testIndexing();
void testModifiers();
void testgetline();
void testComparisons();
void testConcat();
void testSort();
void selectionSort(vector<string>& list);
void printList(vector<string>& list);
void testExtract();
string extractFirstWord(const string& s);

int main()
{
	testConstructors();
	testAssignment();
	testAccessors();
	testIndexing();
	testModifiers();
	testgetline();
	testComparisons();
	testConcat();
	testSort();
	testExtract();
	return 0;
}


void testConstructors()
{
	string word1;
	string word2("Hello world\0");
	string word3("Hello world\n");

	cout << "Testing constructors" << endl << endl;
	cout << word1;
	cout << word2;
	cout << word3;
	cout << endl;
}

void testAssignment()
{
	string word1 = "First";
	string word2 = "Second";
	string word3 = "Third";

	word2 = word1;
	word1 = word3;

	cout << "Testing assignment" << endl << endl;
	cout << word1;
	cout << word2;
	cout << word3;
	cout << endl;
}

void testAccessors()
{
	string word = "A lot of words";

	cout << "Testing accessors" << endl << endl;
	cout << word.at(0);
	cout << word.at(7);
	cout << word.front();
	cout << word.back();
	cout << endl;
}

void testIndexing()
{
	string word = "Another bunch of words";

	cout << "Testing indexing" << endl << endl;
	cout << word[0];
	cout << word[5];
	cout << word[12];
	cout << word[word.size() - 1];
	cout << endl;
}

void testModifiers()
{
	string word1 = "Something";
	string word2 = "Something";
	string word3 = "Something";
	string word4 = "Something";
	string word5 = "Something";

	word1.append(" some more words");
	word2.push_back('0');
	word3.assign(5, 'x');
	word4.insert(6, "MIDDLE");
	word5.erase(0, 4);

	cout << "Testing modifiers" << endl << endl;
	cout << word1 << endl;
	cout << word2 << endl;
	cout << word3 << endl;
	cout << word4 << endl;
	cout << word5 << endl;
	cout << endl;

}

void testgetline()
{
	ifstream infile;
	infile.open("words.txt", ios::in);

	cout << "Testing getline" << endl << endl;
	while (!infile.fail())
	{
		string word;
		getline(infile, word);
		cout << word << endl;
	}
	cout << endl;
}

void testComparisons()
{
	string word1 = "Something";
	string word2 = "Another thing";
	string word3 = "something";
	string word4 = "Something";

	cout << "Testing Comparisons" << endl << endl;
	if (word1 == word2)
	{
		cout << "Something = Another thing" << endl;
	}
	if (word1 == word3)
	{
		cout << "Something = something" << endl;
	}
	if (word1 == word4)
	{
		cout << "Something = Something" << endl;
	}
	if (word1.compare(word4) == 0)
	{
		cout << "Something.compare(Something) = 0" << endl;
	}
	cout << endl;
}

void testConcat()
{
	string word1 = "Something";
	string word2 = "Something";
	string word3 = "Something";
	string word4 = "Something\0";

	word1 += 4;
	word2 += " Other Words";
	word3 += 'h';
	word4 += 'f';

	cout << "Testing Concatination" << endl << endl;
	cout << word1 << endl;
	cout << word2 << endl;
	cout << word3 << endl;
	cout << word4 << endl;
	cout << endl;
}

void testSort()
{
	ifstream infile;
	infile.open("names.txt", ios::in);

	vector<string> names(5);
	int index = 0;

	while (infile.good())
	{
		getline(infile, names[index]);
		index++;
	}

	cout << "Testing Sorting" << endl << endl;
	cout << "File order: " << endl;
	printList(names);
	cout << "Ascending order:" << endl;
	selectionSort(names);
	printList(names);
	cout << endl;
}

void printList(vector<string>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}

void selectionSort(vector<string>& list)
{
	int flag;

	for (int outer = 0; outer < list.size(); outer++)
	{
		flag = outer;
		for (int inner = outer + 1; inner < list.size(); inner++)
		{
			if (list[inner].compare(list[flag]) < 0)
				flag = inner;
		}
		swap(list[outer], list[flag]);
	}
}

void testExtract()
{
	cout << "Testing Extraction " << endl << endl;
	string temp;

	do
	{
		cout << "Words to extract from (Q to quit): ";
		getline(cin, temp);
		string word = extractFirstWord(temp);
		if (temp != "Q" && temp != "q")
			cout << "First word: " << word << endl << endl;
	} while (temp != "Q" && temp != "q");
	cout << endl;

}

string extractFirstWord(const string& s)
{
	int index = 0;
	while (index < s.size() && s.at(index) != ' ')
		index++;
	return s.substr(0, index);
}