//Shemarov M-34

#pragma once

#include "DoublyLinkedList.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

void menu() {
	int optionNumber = 1337;
	DoublyLinkedList doublyLinkedList;
	while (optionNumber != 0) {
		cout << "Options:" << endl;
		cout << "1 - push to 1st element" << endl;
		cout << "2 - push to last element" << endl;
		cout << "3 - push after position" << endl;
		cout << "4 - random list" << endl;
		cout << "5 - print list" << endl;
		cout << "6 - pop element from position" << endl;
		cout << "7 - sort list" << endl;
		cout << "8 - clear list" << endl;
		cout << "9 - save in file" << endl;
		cout << "10 - load from file" << endl;
		cout << "11 - test 1" << endl;
		cout << "12 - test 2" << endl;
		cout << "13 - test 3" << endl;
		cout << "14 - test 4" << endl;
		cout << "15 - test 5" << endl;
		cout << "16 - test 6" << endl;
		cout << "0 - exit" << endl << endl;
		cin >> optionNumber;
		cout << endl;
		switch (optionNumber) {
		case 0:
			return;
		case 1: {
			int value;
			cout << "Enter value of element:" << endl;
			cin >> value;
			doublyLinkedList.pushToHead(value);
			break;
		}
		case 2: {
			int value;
			cout << "Enter value of element:" << endl;
			cin >> value;
			doublyLinkedList.pushToTail(value);
			break;
		}
		case 3: {
			int value;
			cout << "Enter value of element:" << endl;
			cin >> value;
			int position;
			cout << "Enter position of element:" << endl;
			cin >> position;
			doublyLinkedList.pushAfterElement(value, position);
			break;
		}
		case 4: {
			int numberOfElements;
			srand(time(NULL));
			cout << "Enter number of elements:" << endl;
			cin >> numberOfElements;
			for (int i = 0; i < numberOfElements; i++) {
				int value = rand() % 100;
				doublyLinkedList.pushToTail(value);
			}
			break;
		}
		case 5: {
			if (!doublyLinkedList.isEmpty()) {
				DoublyLinkedList::Iterator iterator;
				iterator = doublyLinkedList.getHead();
				while (iterator){
					cout << doublyLinkedList.getValue(iterator) << endl;
					iterator = doublyLinkedList.getNextElement(iterator);
				}
			}
			else {
				cout << "List is empty" << endl;
			}
			break;
		}
		case 6: {
			if (!doublyLinkedList.isEmpty()) {
				int position;
				cout << "Enter position of element:" << endl;
				cin >> position;
				cout << doublyLinkedList.popFromPosition(position) << endl;
			}
			else {
				cout << "List is empty" << endl;
			}
			break;
		}
		case 7: {
			if (!doublyLinkedList.isEmpty()) {
				doublyLinkedList.sort();
				cout << "List sorted" << endl;
			}
			else {
				cout << "List is empty" << endl;
			}
			break;
		}
		case 8: {
			if (!doublyLinkedList.isEmpty()) {
				doublyLinkedList.clear();
				cout << "Succesfully cleared" << endl;
			}
			else {
				cout << "List is empty" << endl;
			}
			break;
		}
		case 9: {
			DoublyLinkedList::Iterator iterator;
			ofstream out;
			out.open("doubly-linked-list.txt");
			if (out.is_open()) {
				iterator = doublyLinkedList.getHead();
				while (iterator){
					out << iterator->value << endl;
					iterator = iterator->nextElement;
				}
				out.close();
				break;
			}
		}
		case 10: {
			string line;
			ifstream in;
			in.open("doubly-linked-list.txt");
			if (in.is_open()) {
				while (getline(in, line)) {
					doublyLinkedList.pushToTail(stoi(line));
				}
			}
			in.close();
			break;
		}
		case 11: {
			DoublyLinkedList testDoublyLinkedList;
			testDoublyLinkedList.pushToHead(1);
			if (testDoublyLinkedList.getHead() == testDoublyLinkedList.getTail()) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 12: {
			DoublyLinkedList testDoublyLinkedList;
			testDoublyLinkedList.pushToHead(2);
			testDoublyLinkedList.pushToHead(1);
			if (testDoublyLinkedList.getHead()->nextElement == testDoublyLinkedList.getTail()) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 13: {
			DoublyLinkedList testDoublyLinkedList;
			testDoublyLinkedList.pushToHead(1);
			testDoublyLinkedList.clear();
			if (testDoublyLinkedList.isEmpty()) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 14: {
			DoublyLinkedList testDoublyLinkedList;
			int testElement = 1;
			testDoublyLinkedList.pushToHead(testElement + 1);
			testDoublyLinkedList.pushToHead(testElement);
			if (testDoublyLinkedList.popHead() == testElement) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 15: {
			DoublyLinkedList testDoublyLinkedList;
			int testElement = 1;
			testDoublyLinkedList.pushToTail(testElement + 1);
			testDoublyLinkedList.pushToTail(testElement);
			if (testDoublyLinkedList.popTail() == testElement) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 16: {
			DoublyLinkedList testDoublyLinkedList;
			const int numberOfTestElements = 5;
			int expectedDoublyLinkedList[numberOfTestElements];
			for (int i = 0; i < numberOfTestElements; i++) {
				testDoublyLinkedList.pushToTail(i);
				expectedDoublyLinkedList[i] = i;
			}
			DoublyLinkedList::Iterator iterator;
			iterator = testDoublyLinkedList.getHead();
			bool isTestCompleted = false;
			for (int i = 0; i < numberOfTestElements; i++) {
				int testValue = testDoublyLinkedList.getValue(iterator);
				isTestCompleted = (expectedDoublyLinkedList[i] == testValue);
				if (!isTestCompleted) {
					cout << "Test failed!" << endl;
					break;
				}
				iterator = testDoublyLinkedList.getNextElement(iterator);
			}
			if (isTestCompleted) {
				cout << "Test completed!" << endl;
			}
			break;
		}
		default:
			cout << "Error" << endl;
			break;
		}
	}
}