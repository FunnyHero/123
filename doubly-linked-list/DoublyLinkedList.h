//Shemarov M-34

#pragma once

class DoublyLinkedList {
private:
	struct Node {
		int value;
		Node* nextElement;
		Node* previousElement;
		Node() {
			nextElement = nullptr;
			previousElement = nullptr;
		}
	};
	Node* head;
	Node* tail;

public:
	DoublyLinkedList();
	~DoublyLinkedList();
	
	typedef Node* Iterator;
	Iterator getHead();
	Iterator getTail();
	Iterator getNextElement(Iterator iterator);
	Iterator getPreviousElement(Iterator iterator);
	int getValue(Iterator iterator);

	bool isEmpty();
	void pushAfterElement(int value, int position);
	void pushAfterElement(int value, Iterator iterator);
	void pushAfterElementMethod(Iterator iterator, Node* tmpNode);
	void pushToHead(int value);
	void pushToTail(int value);
	int popHead();
	int popTail();
	int popFromPosition(int position);
	int popFromPosition(Iterator iterator);
	int popFromPositionMethod(Iterator iterator);
	void clear();
	void sort();
};
