#include <iostream>
using namespace std;

class String {
	char*sPtr;
	int len;
public:
	String() {
		len = 0;
		sPtr = new char[len + 1];
		sPtr[0] = '\0';
	}
	String(const char* sym) {
		mem(sym);
	}
	String(const String &copy) {
		mem(copy.sPtr);
	}
	~String() {
		delete[] sPtr;
	}
	
	int strLength(const char* sym);
	void mem(const char* sym);
	void print();

	void append(String st);
	String substring(int startPos, int num);
	void format(String from, String to);
};


int String::strLength(const char* sym) {
	int length = 0;
	while (sym[length] != '\0') {
		length++;
	}
	return length;
}

void String::mem(const char* sym) {
	len = strLength(sym);
	sPtr = new char[len + 1];
	for (int i = 0; i < len; i++) {
		sPtr[i] = sym[i];
	}
	sPtr[len] = '\0';
}

void String::print() {
	cout << sPtr << endl;
}

void String::append(String st) {
	if (st.len == 0)
		exit(1);
	char*new_sPtr = new char[len + st.len + 1];
	for (int i = 0; i < len; i++) {
		new_sPtr[i] = sPtr[i];
	}
	for (int i = 0; i < st.len; i++)
		new_sPtr[len + i] = st.sPtr[i];
	new_sPtr[len + st.len] = '\0';
	delete[] sPtr;
	sPtr = new_sPtr;
	len += st.len;
}

String String::substring(int startPos, int num) {
	if (startPos >= len || num >= len)
		exit(0);
	len = num;
	char*new_sPtr = new char[len];
	int j = 0;
	for (int i = startPos - 1; i < startPos + num - 1; i++) {
		new_sPtr[j] = sPtr[i];
		j++;
	}
	for (int i = 0; i < len; i++) {
		sPtr[i] = new_sPtr[i];
	}
	sPtr[len] = '\0';
	delete[] new_sPtr;
	return *this;
}

int Find(char *sptr, char *find) {
	if (!*find)
		return 0;
	int position = -1;
	char *tmp1, *tmp2;
	tmp2 = find;
	for (; *sptr != 0; sptr++) {
		position++;
		if (*sptr != *tmp2) {
			continue;
		}
		tmp1 = sptr;
		while (1) {
			if (*tmp2 == 0) {
				return position;
			}
			if (*tmp1++ != *tmp2++) {
				break;
			}
		}
		tmp2 = find;
	}
	return -1;
}

void String::format(String from, String to) {
	if (from.len == 0 || to.len == 0)
		exit(1);
	while (true) {
		int position = Find(sPtr, from.sPtr);
		if (position == -1)
			break;
		char *new_sPtr = new char[len - from.len + to.len + 1];
		for (int i = 0; i < position; i++)
			new_sPtr[i] = sPtr[i];
		for (int i = 0; i < to.len; i++)
			new_sPtr[position + i] = to.sPtr[i];
		int j = position + to.len;
		for (int i = position + from.len; i < len; i++) {
			new_sPtr[j] = sPtr[i];
			j++;
		}
		new_sPtr[len - from.len + to.len] = '\0';
		delete[] sPtr;
		sPtr = new_sPtr;
		len = len - from.len + to.len;
	}
}

void main() {
	String string1 = "roflan string lul", string2 = "gigi za shagi";
	string1.print();
	string2.print();
	string1.substring(8, 7);
	string1.append(string2);
	string1.print();
	string1.format("gi", "OMEGALUL");
	string1.print();
}