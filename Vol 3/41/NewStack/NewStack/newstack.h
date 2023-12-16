#include "usedclasses.h"

using namespace std;

#ifndef NEWSTACK_H
#define NEWSTACK_H

template <class itemType>
class newStack
{
public:
	newStack(); //initializes single private root
	~newStack();
	void push(itemType); //puts an item into the stack in listNode form
	void pop(); //removes the top element, no returning
	int size(); //returns the number of elements
	bool empty(); //true – empty, false - not
	itemType top(); //returns first element without removing it
	list<itemType> myStack; //used to keep track of your stack
private:
};

template <class itemType>
newStack<itemType>::newStack()
{
}



template <class itemType>
newStack<itemType>::~newStack()
{
	listNode<itemType>* temp = myStack.root;
	while (temp != NULL)
	{
		listNode<itemType>* toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
}

template <class itemType>
void newStack<itemType>::push(itemType tempItem)
{
	myStack.root = new listNode<itemType>(tempItem, myStack.root);

}

template <class itemType>
void newStack<itemType>::pop()
{
	if (myStack.root == NULL)
		abort();
	listNode<itemType>* temp =  myStack.root;
	myStack.root = temp->next;
	delete temp;
}

template <class itemType>
int newStack<itemType>::size()
{
	int count = 0;
	listNode<itemType>* temp = myStack.root;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

template <class itemType>
bool newStack<itemType>::empty()
{
	return myStack.root == NULL;
}

template <class itemType>
itemType newStack<itemType>::top()
{
	return myStack.root->it;
}

#endif
