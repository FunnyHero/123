#pragma once
#include <string>

template<class T>
class Collection {
protected:
	Collection() = default;
	~Collection() = default;

	virtual void push_back(const T &) = 0;
	virtual const T pop_back() = 0;
	virtual const bool is_empty() const = 0;
	virtual const size_t size() const = 0;
	virtual void print() const = 0;
	virtual void reverse() = 0;
};