#pragma once

#include "../linked_list.h"
#include <iostream>
using namespace std;

class Pair {

public:
	size_t m_key;
	string m_val;

	Pair() = default;
	Pair(const size_t& key) : m_key(key), m_val("") {}
	Pair(const size_t& key, const string& val) : m_key(key), m_val(val) {}
	Pair(const Pair& copy) : m_key(copy.m_key), m_val(copy.m_val) {}
	friend ostream& operator<<(ostream& out, const Pair& p) {
		out << p.m_val;
		return out;
	}
	const bool operator==(const Pair& p) {
		return m_key == p.m_key;
	}
};

class Map {
private:
	size_t m_capacity;
	List<Pair>* m_table;

	const size_t hash(const size_t& key) const {
		return key % m_capacity;
	}
public:
	Map(const size_t &capacity) : m_capacity(capacity) { m_table = new List<Pair>[capacity](); }
	~Map() {
		delete[] m_table;
	};
	
	void insert(const size_t &, const string &);
	const string get(const size_t &) const;
	Pair* find(const size_t &) const;
	void print() const;
	const bool is_empty() const;

};
void Map::insert(const size_t &key, const string &val) {
	m_table[hash(key)].push_back(Pair(key, val));
}

const string Map::get(const size_t& key) const {
	return find(key)->m_val;
}

Pair* Map::find(const size_t &key) const {
	if (is_empty())
		return nullptr;
	return &m_table[hash(key)].find_node(Pair(key))->m_data;
}

void Map::print() const {
	if (!is_empty())
		return;

	for (size_t i(0); i < m_capacity; ++i) {
		if (!m_table[i].is_empty())
			m_table[i].print();
	}
}

const bool Map::is_empty() const {
	size_t i(0);
	bool empty(true);

	while (empty && i < m_capacity)
		if (!m_table[i++].is_empty())
			empty = false;
	return empty;
}
