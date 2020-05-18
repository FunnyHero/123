//Shemarov M-34

#pragma once

class Queue
{
private:
	struct Node {
		int value;
		Node* next;
		Node() {
			next = nullptr;
		}
	};
	Node* frontElement;
	Node* backElement;

public:
	Queue();
	~Queue();

	typedef Node* iterater;
	iterater getFrontElement();
	iterater getBackElement();
	iterater getNext(iterater iterator);
	int getValue(iterater iterator);
	void push(int);
	int pop();
	bool is_empty();
	void clear();
	int peekFrontElement();
	int peekBackElement();
};