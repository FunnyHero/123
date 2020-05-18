//Shemarov M-34

#include "Queue.h"

Queue::Queue() {
	frontElement = nullptr;
	backElement = nullptr;
}

Queue::~Queue() {
	clear();
}

bool Queue::is_empty() {
	return frontElement == nullptr && backElement == nullptr;
}

void Queue::push(int value) {
	Node* tmpNode = new Node();
	tmpNode->value = value;
	if (is_empty()) {
		backElement = frontElement = tmpNode;
	}
	else {
		backElement->next = tmpNode;
		backElement = tmpNode;
	}
}


int Queue::pop() {
	if (!is_empty()) {
		int tmpValue = frontElement->value;
		Node* tmpFrontElement = frontElement;
		if (frontElement->next) {
			frontElement = frontElement->next;
		}
		else {
			backElement = frontElement = nullptr;
		}

		delete tmpFrontElement;
		return tmpValue;
	}
	return -1337;
}

void Queue::clear() {
	while (!is_empty()) {
		pop();
	}
}

int Queue::peekFrontElement() {
	if (!is_empty()) {
		return frontElement->value;
	}
}

int Queue::peekBackElement() {
	if (!is_empty()) {
		return backElement->value;
	}
}

Queue::iterater Queue::getFrontElement() {
	return frontElement;
}

Queue::iterater Queue::getBackElement() {
	return backElement;
}

Queue::iterater Queue::getNext(iterater iterator) {
	if (iterator != nullptr) {
		return iterator->next;
	}
}

int Queue::getValue(iterater iterator) {
	if (iterator == nullptr)
		return -1337;
	else
		return iterator->value;
}