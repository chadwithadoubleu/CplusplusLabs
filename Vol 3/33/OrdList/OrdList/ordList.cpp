//  ordShell.cpp
//  A program shell for the ordered linked list lab, Lesson 33

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const string SOURCE = "file20.txt";

struct listNode
{
	int  id, inv;
	listNode* next;

	listNode(int tempId, int tempInv, listNode* nxt);
};

listNode::listNode(int tempId, int tempInv, listNode* nxt)
	: id(tempId), inv(tempInv), next(nxt)
{
	// all values initialized using initializer list
}

typedef listNode* nodePtr;

struct listType
{
	nodePtr first;
	nodePtr last;
};

void insertOutOfOrder(listType&, int, int);
void insertInOrder(listType& L, int id, int inv);
nodePtr search(listType, int);
bool removeNode(listType&, int);
void testSearch(listType);
void testDelete(listType&);
void clearList(listType&);
void printList(listType);
int countNodes(listType);
void readData(listType&);
void printBackward(nodePtr temp);
void mainMenu(listType&);


int main()
{
	listType list;

	list.first = list.last = NULL;
	mainMenu(list);
	return 0;
}


void insertOutOfOrder(listType& L, int id, int inv)
{
	if (NULL == L.first)
		L.first = L.last = new listNode(id, inv, L.first);
	else
	{
		L.last->next = new listNode(id, inv, NULL);
		L.last = L.last->next;
	}
}

void insertInOrder(listType& L, int id, int inv)
{

	if (L.first == NULL)
	{
		L.first = L.last = new listNode(id, inv, L.first);
	}
	else if (id < L.first->id)
		L.first = new listNode(id, inv, L.first);
	else
	{
		nodePtr temp = L.first;

		while (L.last != temp && temp->next->id < id)
			temp = temp->next;

		temp->next = new listNode(id, inv, temp->next);
		
		if (L.last == temp)
			L.last = temp->next;
	}
}


nodePtr search(listType temp, int idToFind)
{
	nodePtr tempNode = temp.first;
	while (tempNode != NULL && tempNode->id != idToFind)
		tempNode = tempNode->next;

	return tempNode;
}


void testSearch(listType temp)
{
	int idToFind;
	nodePtr location;

	cout << "Testing search algorithm" << endl << endl;
	cout << "Enter Id value to search for (-1 to quit) ---> ";
	cin >> idToFind;
	while (idToFind >= 0)
	{
		location = search(temp, idToFind);
		cout << "Id # " << idToFind;
		if (NULL == location)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Inventory = " << location->inv << endl;
		cout << endl << "Enter Id value to search for (-1 to quit) ---> ";
		cin >> idToFind;
	}
}

bool removeNode(listType& temp, int idToDelete)
{
	nodePtr tempNode = temp.first;
	
	if (temp.first == NULL)
		return false;
	if (tempNode->id == idToDelete)
	{
		if (temp.last == tempNode)
		{
			delete tempNode;
			temp.first = NULL;
			temp.last = NULL;
			return true;
		}
		else
		{
			temp.first = tempNode->next;
			delete tempNode;
			return true;
		}
	}

	while (tempNode->next != NULL && tempNode->next->id != idToDelete)
	{
		tempNode = tempNode->next;
	}

	if (tempNode->next == NULL)
		return false;

	if (idToDelete == tempNode->next->id)
	{
		nodePtr nodeToDelete = tempNode->next;
		tempNode->next = nodeToDelete->next;
		delete nodeToDelete;
		return true;
	}
	if (temp.last == tempNode->next && tempNode->next->id == idToDelete)
	{
		temp.last = tempNode;
		tempNode->next = NULL;
		delete tempNode;
		return true;
	}
}

void testDelete(listType& temp)
{
	int idToDelete;
	bool success;

	cout << "Testing delete algorithm" << endl << endl;
	cout << "Enter Id value to delete (-1 to quit) ---> ";
	cin >> idToDelete;
	while (idToDelete >= 0)
	{
		success = removeNode(temp, idToDelete);
		cout << "Id # " << idToDelete;
		if (!success)
			cout << "     No such part in stock" << endl;
		else
			cout << "     Id #" << idToDelete << " was deleted" << endl;
		cout << endl << "Enter Id value to delete (-1 to quit) ---> ";
		cin >> idToDelete;
	}
}

void clearList(listType& local)
{
	cout << "Clear list" << endl;
	cin.get();

	nodePtr temp = local.first;
	nodePtr next;
	while (temp != NULL)
	{
		next = temp->next;
		delete temp;
		temp = next;
	}
	local.first = NULL;
	local.last = NULL;
}


void printList(listType local)
{
	nodePtr temp = local.first;
	int line = 1;

	cout << setiosflags(ios::right);
	cout << setw(15) << "Id" << setw(10) << "Inv" << endl << endl;
	while (temp != NULL)
	{
		cout << setw(5) << line << setw(10) << temp->id << setw(10) << temp->inv << endl;
		if (line % 10 == 0) cout << endl;
		temp = temp->next;
		line++;
	}
}


int countNodes(listType local)
{
	nodePtr temp = local.first;
	int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void readData(listType& temp)
{
	ifstream inFile;
	int howMany, k, id, inv;
	inFile.open(SOURCE);
	if (inFile.fail())
	{
		cerr << "Could not open " << SOURCE << endl;
		abort();
	}
	inFile >> howMany;
	for (k = 1; k <= howMany; k++)
	{
		inFile >> id >> inv;
		insertInOrder(temp, id, inv);
	}
}
void printBackward(nodePtr temp)
{
	
	if (temp != NULL)
	{
		printBackward(temp->next);
		cout << setw(10) << temp->id << setw(10) << temp->inv << endl;
	}
}

void mainMenu(listType& temp)
{
	char choice, print;

	do
	{
		cout << "Linked List algorithm menu" << endl << endl;
		cout << "(1) Read file10.txt from disk" << endl;
		cout << "(2) Print ordered list" << endl;
		cout << "(3) Search list" << endl;
		cout << "(4) Delete from list" << endl;
		cout << "(5) Clear entire list" << endl;
		cout << "(6) Count nodes in list" << endl;
		cout << "(7) Print list backwards" << endl;
		cout << "(8) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '7')
		{
			switch (choice)
			{
			case '1': readData(temp); break;
			case '2': printList(temp); break;
			case '3': testSearch(temp); break;
			case '4': testDelete(temp); break;
			case '5': clearList(temp); break;
			case '6':
				cout << "Number of nodes = " << countNodes(temp) << endl << endl;
				break;
			case '7':
				cout << setw(10) << "Id" << setw(10) << "Inv" << endl << endl;
				printBackward(temp.first); cout << endl; break;
			}
		}
	} while (choice != '8');
}
