using namespace std;

#ifndef USEDCLASSES_H
#define USEDCLASSES_H

using namespace std;

struct item
{
	int id;
	int inv;
};
 
template <class itemType>
struct listNode
{
	itemType it;
	listNode* next;

	listNode(itemType, listNode*);
};

template <class itemType>
listNode<itemType>::listNode(itemType ite, listNode<itemType>* nxt)
{
	it = ite;
	next = nxt;
}

template <class itemType>
class list
{
public:
	list();
	list(listNode<itemType>);
	listNode<itemType>* root;
private:
};

template <class itemType>
list<itemType>::list()
{
	root = NULL;
}

template <class itemType>
list<itemType>::list(listNode<itemType> node)
{
	root = &node;
}

#endif
