#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stack>

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
void inOrder(treePtr);
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

void inOrder(treePtr root)//Non recursive
{
	if (root == NULL)
		return;

	int index = 1;

	stack<treePtr> nodes;
	treePtr temp = root;

	do
	{
		while (temp != NULL)
		{
			nodes.push(temp);
			temp = temp->left;
		}
		temp = nodes.top();
		nodes.pop();
		cout << setw(2) << index << setw(8) << temp->id << setw(10) << temp->inv << endl;
		index++;
		temp = temp->right;

	} while (!nodes.empty() || temp != NULL);
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
		cout << "(2) Print the tree in order non-recursively" << endl;
		cout << "(3) Quit" << endl << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('1' <= choice && choice <= '2')
		{
			switch (choice)
			{
			case '1': readData(temp); break;
			case '2': cout << setiosflags(ios::right);
				cout << setw(10) << "Id" << setw(10) << "Inv" << endl << endl;
				inOrder(temp);
				cout << endl;
				break;
			}
		}
	} while (choice != '3');
}
