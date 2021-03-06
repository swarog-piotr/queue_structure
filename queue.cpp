#include "queue.h"


Queue::Queue(int size) : queue_size(size)
{
	frontNode = rearNode = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (!isEmpty()) {
		temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
	}
}

void Queue::deleteQueue()
{
	//todo
}

bool Queue::isEmpty() const
{
	return items;
}

bool Queue::isFull() const
{
	return queue_size == items;
}

int Queue::size() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	if (isFull()) return false;

	Node* temp = new Node;
	temp->item = item;
	temp->next= nullptr;
	
	items++;

	if (frontNode == nullptr) 
		frontNode = temp; //if que is empty, new item on the front
	else 
		rearNode->next = temp; //else new item n

	rearNode = temp;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (isEmpty()) return false;

	item = frontNode->item;
	items--;

	Node* temp = frontNode;
	frontNode = frontNode->next;
	delete temp;

	if (isEmpty())
		rearNode == nullptr;

	return true;
}
