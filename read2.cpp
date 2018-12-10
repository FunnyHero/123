#include<iostream>
using namespace std;

struct node_t {
	node_t() {
		prev = nullptr;
	}
	int value;
	node_t* prev;
};


class stack {
private:
	
public:
	node_t* top;
	stack() {
		top = nullptr;
	};
	~stack() {
		delete top;
	};

	void push(int);
	int* pop();
	bool is_empty();
	node_t* reverse(node_t*);
};


void stack::push(int value) {
	node_t* tmp = new node_t();
	tmp->value = value;
	tmp->prev = top;
	top = tmp;
}


int* stack::pop() {
	if (!is_empty()) {
		int* tmp_val = new int(top->value);
		node_t* tmp_top = top;
		top = top->prev;
		delete tmp_top;
		return tmp_val;
	}
	return nullptr;
}

bool stack::is_empty() {
	return top == nullptr;
}


node_t* stack::reverse(node_t* t) {
	//todo
	node_t *temp, *scd = t, *rev = nullptr;
	while (scd != nullptr) {
		temp = scd->prev;
		scd->prev = rev;
		rev = scd;
		scd = temp;
	}
	return rev;
}



int main() {
	// int val;
	stack my_stack;

	for (int i = 0; i < 10; ++i) {
		my_stack.push(i);
	}
	my_stack.top=my_stack.reverse(my_stack.top);
	while(!my_stack.is_empty()) {
		cout << *my_stack.pop() << endl;
	}
	return 0;
}


// API
// Application Programming Interface
