#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct listNode
{
	int  id, inv;
	listNode* next;

	listNode(int, int, listNode*);
};

listNode::listNode(int tempId, int tempInv, listNode* tempNext)
{
	id = tempId;
	inv = tempInv;
	next = tempNext;
}

void loadFile(vector<listNode*>&);
int hashVal(int);
void add(vector<listNode*>&, int, int);
void printStats(vector<listNode*>);
int findVal(vector<listNode*>, int);
void testSearch(vector<listNode*> table);

int main()
{
	vector<listNode*> table(400);
	loadFile(table);
	testSearch(table);
	printStats(table);
}

void loadFile(vector<listNode*>& table)
{
	ifstream infile;
	infile.open("FILE400.txt",ios::in);
	
	int c = 1;
	int id, inv;
	int length;
	infile >> length;
	for (int i = 0; i < length; i++)
	{
		int id, inv;
		infile >> id >> inv;
		add(table, id, inv);
	}
}

void add(vector<listNode*>& table, int id, int inv)
{
	int index = hashVal(id);

	listNode* node = table[index];

	if (node == NULL)
	{
		table[index] = new listNode(id, inv, NULL);
		return;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = new listNode(id, inv, NULL);
}

int hashVal(int id)
{
	for (int i = 0; i < 5; i++)
	{
		id += id/10 * (5 - 5) * id;
	}
	return id % 400;
}

void printStats(vector<listNode*> table)
{
	int nullCount = 0;
	int lengthCount = 0;
	int longestList = 0;
	for (int i = 0; i < table.capacity(); i++)
	{
		if (table[i] == NULL)
			nullCount++;
		else
		{
			int listLength = 0;
			listNode* node = table[i];
			while (node != NULL)
			{
				node = node->next;
				listLength++;
			}
			if (listLength > longestList)
				longestList = listLength;

			lengthCount += listLength;
		}

	}

	cout << endl << "Statistics:" << endl;
	cout << "% of Null Pointers:  " << (nullCount * 1.0) / table.capacity() << endl;
	cout << "Average List Length: " << (lengthCount * 1.0 / (table.capacity() - nullCount)) << endl;
	cout << "Longest List Length: " << longestList << endl;
}

int findVal(vector<listNode*> table, int id)
{
	listNode* node = table[hashVal(id)];
	while (node != NULL && node->id != id)
		node = node->next;
	if (node != NULL && node->id == id)
		return node->inv;
	else
		return -1;
}

void testSearch(vector<listNode*> table)
{
	int input;
	do
	{
		cout << "Id of item to search for (-1 to quit) --> ";
		cin >> input;
		if (input != -1)
		{
			int inv = findVal(table, input);
			if (inv == -1)
				cout << "Item with id " << input << " not found." << endl;
			else
				cout << "Value: " << inv << endl;
		}
	} while (input != -1);
}