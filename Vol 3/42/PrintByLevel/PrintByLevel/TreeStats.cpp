#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

const string SOURCE = "fileB.txt";

struct treeNode
{
	char letter;
	treeNode* left, * right;

	treeNode(char, treeNode*, treeNode*);
};

treeNode::treeNode(char tempLetter, treeNode* tempLeft, treeNode* tempRight)
	: letter(tempLetter), left(tempLeft), right(tempRight)
{
	// all values initialized using initializer list
}

typedef treeNode* treePtr;

void insert(treePtr& L, char letter);
void preOrder(treePtr);
void inOrder(treePtr);
void postOrder(treePtr);
int countNodes(treePtr);
int countLeaves(treePtr);
int height(treePtr);
int width(treePtr);
int max(int, int);
void readData(treePtr&);
void clearTree(treePtr&);
void printByLevel(treePtr);
void mainMenu(treePtr&);

int main()
{
	treePtr root = NULL;
	mainMenu(root);
	return 0;
}

void insert(treePtr& root, char letter)
{
	treePtr temp = root;
	if (root == NULL)
	{
		root = new treeNode(letter, NULL, NULL);
		return;
	}
	while (temp != NULL)
	{
		if (letter < temp->letter)
		{
			if (temp->left == NULL)
			{
				temp->left = new treeNode(letter, NULL, NULL);
				return;
			}
			else
				temp = temp->left;
		}
		if (letter >= temp->letter)
		{
			if (temp->right == NULL)
			{
				temp->right = new treeNode(letter, NULL, NULL);
				return;
			}
			else
				temp = temp->right;
		}
	}
}

void preOrder(treePtr root)
{
	if (root == NULL)
		return;

	cout << root->letter;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(treePtr root)
{
	if (root == NULL)
		return;

	inOrder(root->left);
	cout << root->letter;
	inOrder(root->right);
}

void postOrder(treePtr root)
{
	if (root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->letter;
}

int countNodes(treePtr root)
{
	if (root == NULL)
		return 0;
	else
		return countNodes(root->left) + 1 + countNodes(root->right);
}

int countLeaves(treePtr root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return countLeaves(root->left) + countLeaves(root->right);
}

int height(treePtr root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + max(height(root->left), height(root->right));
}

int width(treePtr root)
{
	if (root == NULL)
		return 0;
	int possibleWidth = max(width(root->left), width(root->right));
	return max(height(root->left) + 1 + height(root->right), //Includes node
		max(width(root->left), width(root->right)));         //Excludes node
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void readData(treePtr& temp)
{
	ifstream inFile;
	inFile.open(SOURCE);
	if (inFile.fail())
	{
		cerr << "Could not open " << SOURCE << endl;
		abort();
	}
	char letter;
	while (inFile >> letter)
	{
		insert(temp, letter);
	}
}

void clearTree(treePtr& temp)
{
	temp = NULL;
}

void printByLevel(treePtr root)
{
	if (root == NULL)
		return;
	queue<treePtr> list;
	list.emplace(root);
	treePtr temp = root;

	do
	{
		temp = list.front();
		list.pop();
		cout << temp->letter;
		if (temp->left != NULL)
			list.emplace(temp->left);
		if (temp->right != NULL)
			list.emplace(temp->right);
	} while (temp != NULL && (!list.empty()));
	if (temp != NULL)
		cout << temp->letter;
}

void mainMenu(treePtr& temp)
{
	char choice;

	do
	{
		cout << "Linked List algorithm menu" << endl << endl;
		cout << "(1) Fill the tree from a file" << endl;
		cout << "(2) Preorder output" << endl;
		cout << "(3) Inorder output" << endl;
		cout << "(4) Postorder output" << endl;
		cout << "(5) Count the nodes in the tree" << endl;
		cout << "(6) Count the leaves in the tree" << endl;
		cout << "(7) Find the height of the tree" << endl;
		cout << "(8) Find the width of the tree" << endl;
		cout << "(9) Clear the tree" << endl;
		cout << "(0) Print the tree by Level" << endl;
		cout << "(q) Count the nodes in the tree" << endl;
		cout << "Choice ---> ";
		cin >> choice;
		cin.get();	// to dump return key
		cout << endl;
		if ('0' <= choice && choice <= '9')
		{
			switch (choice)
			{
			case '1': readData(temp); break;
			case '2':
				cout << "The tree printed preorder:" << endl << endl;
				preOrder(temp);
				cout << endl << endl;
				break;
			case '3':
				cout << "The tree printed in order:" << endl << endl;
				inOrder(temp);
				cout << endl << endl;
				break;
			case '4':
				cout << "The tree printed postorder:" << endl << endl;
				postOrder(temp);
				cout << endl << endl;
				break;
			case '5':
				cout << "Number of nodes in the tree = " << countNodes(temp) << endl << endl;
				break;
			case '6':
				cout << "Number of leaves in the tree = " << countLeaves(temp) << endl << endl;
				break;
			case '7':
				cout << "Tree height = " << height(temp) << endl << endl;
				break;
			case '8':
				cout << "Tree width = " << width(temp) << endl << endl;
				break;
			case '9':
				clearTree(temp);
				cout << "The tree has been cleared." << endl << endl;
				break;
			case '0':
				printByLevel(temp);
				break;
			}
		}
		cout << endl;
	} while (choice != 'q' && choice != 'Q');
}
