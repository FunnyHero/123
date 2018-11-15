#include<iostream>
using namespace std;


struct msg {
	msg() {
		prev = nullptr; // NULL -> #define NULL 0
	}
	//char* currency_name_fst;
	double currency_amt_fst;
	//char* currency_name_scd;
	double currency_amt_scd;
	msg* prev;
};


// Stack implementation using dynamic memory

msg* create_msg() {
	return new msg();
}

void init_msg(msg* msg_ptr) {
	//(*msg).currency_name_fst;
	//msg->currency_name_fst; strcpy()
	msg_ptr->currency_amt_fst = 130.0;
	msg_ptr->currency_amt_scd = 70.0;
}

// main //C89

msg* g_top(nullptr);

bool is_empt() {
	return g_top == nullptr;
}

void push(msg* msg_ptr) {
	if (!is_empt()) {
		msg_ptr->prev = g_top;
	}
	g_top = msg_ptr;
}

msg* pop() {
	if (!is_empt()) {
		msg* top = g_top;
		g_top = g_top->prev;
		return top;
	}
}


void del( msg* msg_ptr) {
	delete msg_ptr;
}


void fill_stack() {
	for (int i = 0; i < 10; ++i) {
		msg* msg_ptr = create_msg();
		init_msg(msg_ptr);
		push(msg_ptr);
	}
}


void read() {
	//TODO: read from top of stack
	for (int i = 0; i < 10; ++i) {
		msg x=*pop();
		cout << x.currency_amt_fst <<" "<< x.currency_amt_scd << endl;
	}
	//TODO: print to stdout
	//TODO: delete
}

void main() {
	fill_stack();
	read();
	system("pause");
}
// @deadWasabi