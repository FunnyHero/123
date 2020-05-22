//Shemarov M-34

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
	clear();
}

bool DoublyLinkedList::isEmpty() {
	return head == nullptr;
}

void DoublyLinkedList::pushToTail(int value) {
	Node* tmpNode = new Node;
	tmpNode->value = value;
	if (!isEmpty()) {
		tail->nextElement = tmpNode;
		tmpNode->previousElement = tail;
		tail = tmpNode;
	}
	else {
		tail = head = tmpNode;
	}
}

void DoublyLinkedList::pushToHead(int value) {
	Node* tmpNode = new Node;
	tmpNode->value = value;
	if (!isEmpty()) {
		head->previousElement = tmpNode;
		tmpNode->nextElement = head;
		head = tmpNode;
	}
	else {
		tail = head = tmpNode;
	}
}

void DoublyLinkedList::pushAfterElementMethod(Iterator iterator, Node* tmpNode) {
	if (!iterator) return;
	else {
		tmpNode->nextElement = iterator->nextElement;
		tmpNode->previousElement = iterator;
		if (iterator != tail) {
			iterator->nextElement->previousElement = tmpNode;
		}
		iterator->nextElement = tmpNode;
	}
}

void DoublyLinkedList::pushAfterElement(int value, int position) {
	Node* tmpNode = new Node;
	tmpNode->value = value;
	if (!isEmpty()) {
		Iterator iterator = getHead();
		for (int i = 0; i < position - 1 && iterator->nextElement; i++){
			iterator = iterator->nextElement;
		}
		pushAfterElementMethod(iterator, tmpNode);
	}
	else {
		head = tail = tmpNode;
	}
}

void DoublyLinkedList::pushAfterElement(int value, Iterator iterator) {
	Node* tmpNode = new Node;
	tmpNode->value = value;
	if (!isEmpty()) {
		pushAfterElementMethod(iterator, tmpNode);
	}
	else {
		head = tail = tmpNode;
	}
}

int DoublyLinkedList::popHead() {
	if (!isEmpty()) {
		Node* tmpHead = new Node;
		tmpHead = getHead();
		int value = tmpHead->value;
		if (head == tail) {
			head = tail = nullptr;
		}
		else {
			head = tmpHead->nextElement;
			head->previousElement = nullptr;
		}
		delete tmpHead;
		return value;
	}
	return -1337;
}

int DoublyLinkedList::popTail() {
	if (!isEmpty()) {
		Node* tmpTail = new Node;
		tmpTail = getTail();
		int value = tmpTail->value;
		if (head == tail) {
			head = tail = nullptr;
		}
		else {
			tail = tmpTail->previousElement;
			tail->nextElement = nullptr;
		}
		delete tmpTail;
		return value;
	}
	return -1337;
}

int DoublyLinkedList::popFromPositionMethod(Iterator iterator) {
	int value = iterator->value;
	if (iterator == head && iterator == tail) {
		head = tail = nullptr;
		delete iterator;
	}
	else if (iterator == head) {
		value = popHead();
	}
	else if (iterator == tail) {
		value = popTail();
	}
	else {
		iterator->previousElement->nextElement = iterator->nextElement;
		iterator->nextElement->previousElement = iterator->previousElement;
		delete iterator;
	}
	return value;
}

int DoublyLinkedList::popFromPosition(int position) {
	if (!isEmpty()) {
		Iterator iterator = getHead();
		for (int i = 0; i < position && iterator; i++){
			iterator = getNextElement(iterator);
		}
		return popFromPositionMethod(iterator);
	}
	return -1337;
}

int DoublyLinkedList::popFromPosition(Iterator iterator) {
	if (!isEmpty()) {
		Iterator tmpIterator(iterator);
		return popFromPositionMethod(tmpIterator);
	}
	return -1337;
}

void DoublyLinkedList::clear() {
	while (!isEmpty()) {
		popHead();
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getHead() {
	if (!isEmpty()) {
		return head;
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getTail() {
	if (!isEmpty()) {
		return tail;
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getNextElement(Iterator iterator) {
	if (!isEmpty()) {
		return iterator->nextElement;
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::getPreviousElement(Iterator iterator) {
	if (!isEmpty()) {
		return iterator->previousElement;
	}
}

int DoublyLinkedList::getValue(Iterator iterator) {
	if (!isEmpty()) {
		return iterator->value;
	}
	return -1337;
}

void DoublyLinkedList::sort() {
	if (!isEmpty() && (head != tail)) {
		Iterator iterator = head;
		while (iterator->nextElement){
			Iterator currentNode = iterator;
			if (currentNode->value > currentNode->nextElement->value){
				int value = popFromPosition(currentNode->nextElement);
				while ((currentNode->value > value) && currentNode->previousElement) {
					currentNode = currentNode->previousElement;
				}
				if (currentNode == head) {
					pushToHead(value);
				}
				else {
					pushAfterElement(value, currentNode);
				}
			}
			else {
				iterator = iterator->nextElement;
			}
		}
	}
}