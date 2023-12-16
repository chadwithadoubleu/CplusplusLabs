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
	int length = 0;
};

void insertOutOfOrder(listType&, int, int);
void printList(listType);
void readData(listType&);
void mergeSort(listType&);
void merge(listType&, listType&);
void swap(nodePtr&, nodePtr&);
void reverseList(listType&);

int main()
{
	listType list;
	list.first = list.last = NULL;
	readData(list);

	cout << "Out of Order:" << endl;
	printList(list);

	mergeSort(list);
	cout << endl << "Sorted:" << endl;
	printList(list);

	reverseList(list);
	cout << endl << "Reversed:" << endl;
	printList(list);

	return 0;
}

void mergeSort(listType& L)
{
	if (L.length == 1)
		return;
	else if (L.length == 2)
	{
		if (L.first->id > L.last->id)
			swap(L.first, L.last);
	}
	else
	{
		int mid = L.length / 2;

		nodePtr fMid = L.first;

		for (int i = 0; i < mid-1; i++)
		{
			fMid = fMid->next;
		}
		
		listType fList;
		fList.length = L.length / 2;
		fList.first = L.first;
		fList.last = fMid;
		
		listType lList;
		lList.length = (L.length + 1) / 2;
		lList.last = L.last;
		lList.first = fMid->next;

		mergeSort(fList);
		mergeSort(lList);
		merge(fList, lList);
	}
}

void swap(nodePtr& a, nodePtr& b)
{
	listNode temp = *a;
	a->id = b->id;
	a->inv = b->inv;

	b->id = temp.id;
	b->inv = temp.inv;
}

void merge(listType& listA, listType& listB)
{
	nodePtr indexMerged = new listNode(0, 0, NULL);

	listType merged;
	merged.first = indexMerged;

	nodePtr indexA = listA.first;
	nodePtr indexB = listB.first;
	nodePtr indexAStop = indexB;
	nodePtr indexBStop = indexB;

	for (int i = 0; i < listB.length; i++)
	{
		if (indexBStop != NULL)
			indexBStop = indexBStop->next;
	}

	while (indexA != indexAStop && indexB != indexBStop)
	{
		if (indexA->id < indexB->id)
		{
			indexMerged->next = new listNode(indexA->id,indexA->inv,NULL);
			indexMerged = indexMerged->next;

			indexA = indexA->next;
		}
		else
		{
			indexMerged->next = new listNode(indexB->id, indexB->inv, NULL);
			indexMerged = indexMerged->next;

			indexB = indexB->next;
		}
	}
	while (indexA != indexAStop)
	{
		indexMerged->next = new listNode(indexA->id, indexA->inv, NULL);
		indexMerged = indexMerged->next;

		indexA = indexA->next;
	}
	while (indexB != indexBStop)
	{
		indexMerged->next = new listNode(indexB->id, indexB->inv, NULL);
		indexMerged = indexMerged->next;

		indexB = indexB->next;
	}

	merged.first = merged.first->next;
	
	nodePtr swapList = listA.first;
	nodePtr swapMerged = merged.first;

	while (swapMerged != NULL)
	{
		swap(swapMerged, swapList);
		swapMerged = swapMerged->next;
		swapList = swapList->next;
	}
}

void insertOutOfOrder(listType& L, int id, int inv)
{
	L.length++;
	if (NULL == L.first)
		L.first = L.last = new listNode(id, inv, L.first);
	else
	{
		L.last->next = new listNode(id, inv, NULL);
		L.last = L.last->next;
	}
}

void reverseList(listType& L)
{
	nodePtr temp = L.first;
	while (temp->next != NULL)
	{
		nodePtr nextNode = temp->next;
		temp->next = nextNode->next;
		nextNode->next = L.first;
		L.first = nextNode;
	}
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
		insertOutOfOrder(temp, id, inv);
	}
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