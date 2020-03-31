#pragma once

typedef long Item;

class Queue
{
private:
	enum {Q_SIZE = 10};
    const int queue_size;
	int items;
	struct Node {
		Item item;
		Node* next;
	};
	Node* frontNode;
	Node* rearNode;

public:
	Queue(int size = Q_SIZE);
	~Queue();
	
	bool enqueue(const Item& item);
	bool dequeue(Item& item);

	void deleteQueue();
	bool isEmpty() const;
	bool isFull() const;
	int size() const;
};

		
//public interface:

/*
- check if empty
- check if full
- check how many items

- create empty queue(with item limit)
- delete queue

- add item (push?) to the end of queue /enqueue
- pull item from the head of queue /dequeue
*/