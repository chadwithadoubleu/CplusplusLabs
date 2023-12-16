#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const string SOURCE = "file20.txt";

struct treeNode
{
	int  id, inv;
	treeNode* left, * right;

	treeNode(int, int, treeNode*, treeNode*);
};

treeNode::treeNode(int tempId, int tempInv, treeNode* tempLeft, treeNode* tempRight)
	: id(tempId), inv(tempInv), left(tempLeft), right(tempRight)
{
	// all values initialized using initializer list
}

typedef treeNode* treePtr;

void insert(treePtr& L, int id, int inv);
void testSearch(treePtr);
treePtr search(treePtr, int);
void testDelete(treePtr&);
bool removeNode(treePtr&, int);
treePtr deleteTargetNode(treePtr&);
void printList(treePtr);
int countNodes(treePtr);
void readData(treePtr&);
void mainMenu(treePtr&);

int main()
{
	treePtr root = NULL;
	mainMenu(root);
	return 0;
}

void insert(treePtr& root, int id, int inv)
{
	treePtr temp = root;
	if (root == NULL)
	{
		root = new treeNode(id, inv, NULL, NULL);
		return;
	}
	while (temp != NULL)
	{
		if (id < temp->id)
		{
			if (temp->left == NULL)
			{
				temp->left = new treeNode(id, inv, NULL, NULL);
				return;
			}
			else
				temp = temp->left;
		}
		if (id >= temp->id)
		{
			if (temp->right == NULL)
			{
				temp->right = new treeNode(id, inv, NULL, NULL);
				return;
			}
			else
				temp = temp->right;
		}
	}
}

treePtr search(treePtr root, int idToFind)
{
	while (root != NULL && root->id != idToFind)
	{
		if (idToFind < root->id)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}

void testSearch(treePtr temp)
{
	int idToFind;
	treePtr location;

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

bool removeNode(treePtr& root, int idToDelete)
{
	treePtr temp = root;

	if (root == NULL)
		return false;
	if (root->id == idToDelete)
	{
		root = deleteTargetNode(root);
		return true;
	}

	while (temp != NULL)
	{
		if (idToDelete < temp->id)
		{
			if (temp->left != NULL && idToDelete == temp->left->id)
			{
				temp->left = deleteTargetNode(temp->left);
				return true;
			}
			else
				temp = temp->left;

		}
		else
		{
			if (temp->right != NULL && idToDelete == temp->right->id)
			{
				temp->right = deleteTargetNode(temp->right);
				return true;
			}
			else
				temp = temp->right;
		}
	}
	return false;
}

treePtr deleteTargetNode(treePtr& target)
{
	if (target->right == NULL)
	{
		treePtr replaceNode = target->left;
		delete target;
		return replaceNode;
	}
	else if (target->left == NULL)
	{
		treePtr replaceNode = target->right;
		delete target;
		return replaceNode;
	}
	else if (target->right->left == NULL)
	{
		target->id = target->right->id;
		target->inv = target->right->inv;
		treePtr targetToDelete = target->right;
		target->right = targetToDelete->right;
		delete targetToDelete;
		return target;
	}
	else
	{
		treePtr marker = target->right;
		while (marker->left->left != NULL)
		{
			marker = marker->left;
		}
		target->id = marker->left->id;
		target->inv = marker->left->inv;
		treePtr targetToDelete = marker->left;
		marker->left = marker->left->right;
		delete targetToDelete;
		return target;
	}
}

void testDelete(treePtr& temp)
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

void inOrder(treePtr root)
{
	if (root == NULL)
		return;

	inOrder(root->left);
	cout << setw(10) << root->id << setw(10) << root->inv << endl;
	inOrder(root->right);
}

int countNodes(treePtr root)
{
	if (root == NULL)
		return 0;
	else
		return countNodes(root->left) + 1 + countNodes(root->right);
}

void readData(treePtr& temp)
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
		insert(temp, id, inv);
	}
}

void mainMenu(treePtr& temp)
{
	char choice;

	do
	{
		cout << "Linked List algorithm menu" << endl << endl;
		cout << "(1) Read file20.txt from disk" << endl;
		cout << "(2) Print the tree in order" << endl;
		cout << "(3) Search the tree" << endl;
		cout << "(4) Delete from the tree" << endl;
		cout << "(5) Count the nodes in the tree" << endl;
		cout << "(6) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '7')
		{
			switch (choice)
			{
			case '1': readData(temp); break;
			case '2': cout << setiosflags(ios::right);
					  cout << setw(10) << "Id" << setw(10) << "Inv" << endl << endl; 
					  inOrder(temp); 
					  cout << endl; 
					  break;
			case '3': testSearch(temp); break;
			case '4': testDelete(temp); break;
			case '5':
				cout << "Number of tree nodes = " << countNodes(temp) << endl << endl;
				break;
			}
		}
	} while (choice != '6');
}
