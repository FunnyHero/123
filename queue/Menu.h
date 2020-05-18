//Shemarov M-34

#pragma once
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void menu() {
	int optionNumber = 1337;
	Queue queue;
	while (optionNumber != 0) {
		cout << "Options:" << endl;
		cout << "1 - push element" << endl;
		cout << "2 - random queue" << endl;
		cout << "3 - print queue" << endl;
		cout << "4 - pop element" << endl;
		cout << "5 - peek front element" << endl;
		cout << "6 - peek back element" << endl;
		cout << "7 - clear the queue" << endl;
		cout << "8 - save in file" << endl;
		cout << "9 - load from file" << endl;
		cout << "10 - test 1" << endl;
		cout << "11 - test 2" << endl;
		cout << "12 - test 3" << endl;
		cout << "13 - test 4" << endl;
		cout << "0 - exit" << endl;
		cin >> optionNumber;
		cout << endl;
		switch (optionNumber) {
		case 0:
			return;
		case 1: {
			int value;
			cout << "Enter value of element:" << endl;
			cin >> value;
			queue.push(value);
			break;
		}
		case 2:
			int numberOfElements;
			srand(time(NULL));
			cout << "Enter number of elements:" << endl;
			cin >> numberOfElements;
			for (int i = 0; i < numberOfElements; i++) {
				int value = rand() % 100;
				queue.push(value);
			}
			break;
		case 3:
			if (!queue.is_empty()) {
				Queue::iterater iterator;
				iterator = queue.getFrontElement();
				while (iterator) {
					cout << queue.getValue(iterator) << endl;
					iterator = queue.getNext(iterator);
				}
			}
			else
				cout << "The queue is empty" << endl;
			break;
		case 4:
			if (!queue.is_empty()) {
				cout << queue.pop() << endl;
			}
			else
				cout << "The queue is empty" << endl;
			break;
		case 5:
			if (!queue.is_empty()) {
				cout << queue.peekFrontElement() << endl;
			}
			else
				cout << "The queue is empty" << endl;
			break;
		case 6:
			if (!queue.is_empty()) {
				cout << queue.peekBackElement() << endl;
			}
			else
				cout << "The queue is empty" << endl;
			break;
		case 7:
			if (!queue.is_empty()) {
				queue.clear();
				cout << "Succesfully cleared" << endl;
			}
			else
				cout << "The queue is empty" << endl;
			break;
		case 8: {
			Queue::iterater iterator;
			ofstream out;
			out.open("queue.txt");
			if (out.is_open()) {
				iterator = queue.getFrontElement();
				while (iterator) {
					out << queue.getValue(iterator) << endl;
					iterator = queue.getNext(iterator);
				}
				out.close();
				break;
			}
		}
		case 9: {
			string line;
			ifstream in;
			in.open("queue.txt");
			if (in.is_open()) {
				while (getline(in, line)) {
					queue.push(stoi(line));
				}
			}
			in.close();
			break;
		}
		case 10: {
			Queue testQueue;
			const int numberOfTestElements = 5;
			int expectedFrontElement = 0;
			int expectedBackElement;
			for (int i = 0; i < numberOfTestElements; i++) {
				testQueue.push(i);
				expectedBackElement = i;
			}
			if (testQueue.peekFrontElement() == expectedFrontElement && testQueue.peekBackElement() == expectedBackElement) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 11: {
			Queue testQueue;
			const int numberOfTestElements = 5;
			int expectedQueue[numberOfTestElements];
			for (int i = 0; i < numberOfTestElements; i++){
				testQueue.push(i);
				expectedQueue[i] = i;
			}
			Queue::iterater iterator;
			iterator = testQueue.getFrontElement();
			bool isTestCompleted = true;
			for (int i = 0; i < numberOfTestElements; i++) {
				int testValue = testQueue.getValue(iterator);
				isTestCompleted = (expectedQueue[i] == testValue);
				if (!isTestCompleted) {
					cout << "Test failed!" << endl;
					break;
				}
				iterator = testQueue.getNext(iterator);
			}
			if (isTestCompleted)
				cout << "Test completed!" << endl;
			break;
		}
		case 12: {
			Queue testQueue;
			int testElement = 1;
			testQueue.push(testElement);
			if (testQueue.pop() == testElement) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		case 13: {
			Queue testQueue;
			int testElement = 1;
			testQueue.push(testElement);
			testQueue.clear();
			if (testQueue.is_empty()) {
				cout << "Test completed!" << endl;
			}
			else
				cout << "Test failed!" << endl;
			break;
		}
		default:
			cout << "Error" << endl;
			break;
		}
	}
}