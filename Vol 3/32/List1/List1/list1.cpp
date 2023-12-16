#include <iostream>

using namespace std;

struct listNode
{
	int data;
	listNode* next;

	listNode(int, listNode*);
};

listNode::listNode(int tempData, listNode* tempNext)
	:data(tempData), next(tempNext)
{

}

typedef listNode* nodePtr;

int countNodes(nodePtr tempNode);
void printList(nodePtr tempNode);
void createList(nodePtr& tempNode);


int main()
{
	nodePtr first;
	createList(first);
	printList(first);
	cout << "Nodes in List: " << countNodes(first) << endl;
}

int countNodes(nodePtr tempNode)
{
	int count = 0;
	while (tempNode != NULL)
	{
		count++;
		tempNode = tempNode->next;
	}
	return count;
}

void printList(nodePtr tempNode)
{
	while (tempNode != NULL)
	{
		cout << tempNode->data << endl;
		tempNode = tempNode->next;
	}
	cout << endl;
}

void createList(nodePtr& tempNode)
{
	tempNode = new listNode(0,NULL);
	nodePtr first = tempNode;
	for (int i = 1; i <= 20; i++)
	{
		tempNode->next = new listNode(i,NULL);
		tempNode = tempNode->next;
	}
	tempNode = first->next;
}