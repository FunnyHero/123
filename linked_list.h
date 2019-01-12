#pragma once

#include "../Collection.h"
#include <iostream>
using namespace std;
template<class T>

class Node {

public:

	Node* m_next;
	Node* m_prev;
	T m_data;
};


template<class T>

class List : public Collection<T> {

private:

	Node<T>* m_head;
	Node<T>* m_tail;


public:

	List() : m_head(nullptr), m_tail(nullptr) {}
	List(const List& copy) : m_head(nullptr), m_tail(nullptr) {
		Node<T> *temp = copy.m_head;

		while (temp != nullptr) {
			push_back(temp->m_data);
			temp = temp->m_next;
		}
	}

	~List() {
		while (m_head) {
			m_tail = m_head->m_next;
			delete m_head;
			m_head = m_tail;
		}
	}

	List<T> & operator=(List l) {
		swap(m_head, l.m_head);
		swap(m_tail, l.m_tail);
		return *this;
	}

	Node<T>* find_node(const T& data) const {
		if (is_empty())
			return nullptr;
		Node<T>* temp = m_head;
		while (temp != nullptr) {
			if (temp->m_data == data)
				return temp;
			temp = temp->m_next;
		}
		return nullptr;
	}

	void push_back(const T &data) {
		Node<T>* newNode = new Node<T>;
		newNode->m_data = data;
		newNode->m_next = nullptr;
		if (is_empty()) {
			newNode->m_prev = nullptr;
			m_head = m_tail = newNode;
		}
		else {
			newNode->m_prev = m_tail;
			m_tail->m_next = newNode;
			m_tail = newNode;
		}
	}

	void push_front(const T &data) {
		Node<T> *newNode = new Node<T>;
		newNode->m_data = data;
		newNode->m_next = m_head;
		newNode->m_prev = nullptr;
		if (!is_empty())
			m_head->m_prev = newNode;
		else
			m_tail = newNode;
		m_head = newNode;
	}

	const T pop_back() {
		if (!is_empty()) {
			Node<T>* temp = m_tail;
			const T data = temp->m_data;
			m_tail = m_tail->m_prev;
			if (m_tail)
				m_tail->m_next = nullptr;
			if (temp == m_head)
				m_head = nullptr;
			delete temp;
			return data;
		}
	}

	const T pop_front() {
		if (!is_empty()) {
			Node<T>* temp = m_head;
			const T data = temp->m_data;
			m_head = m_head->m_next;
			if (m_head)
				m_head->m_prev = nullptr;
			if (temp == m_tail)
				m_tail = nullptr;
			delete temp;
			return data;
		}
	}

	const bool is_empty() const {
		return m_head == nullptr;
	}

	const size_t size() const {
		if (is_empty())
			return 0;

		size_t num = 0;
		for (Node<T> *temp = m_head; temp != nullptr; temp = temp->m_next)
			++num;
		return num;
	}

	void print() const {
		if (is_empty())
			return;
		for (Node<T> * temp = m_head; temp != nullptr; temp = temp->m_next)
			cout << temp->m_data << " ";
	}

	void reverse() {
		if (is_empty())
			return;
		for (;;) {
			swap(m_head->m_prev, m_head->m_next);

			Node<T> *temp = m_head->m_prev;
			if (temp == nullptr)
				break;
			m_head = temp;
		}
	}
};
