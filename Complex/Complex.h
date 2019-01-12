#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
	double re, im;

public:
	Complex() {
		re = 0;
		im = 0;
	}
	Complex(const double &i_re, const double &i_im) {
		re = i_re;
		im = i_im;
	}
	Complex(const Complex &copy) {
		re = copy.re;
		im = copy.im;
	}
	~Complex() {

	}

	friend ostream & operator<< (ostream &, const Complex &);
	Complex operator + (const Complex &)const;
	Complex operator * (const Complex &)const;
	const double abs() const;
};

Complex Complex::operator + (const Complex &compl)const {
	return Complex(re + compl.re, im + compl.im);
}

Complex Complex::operator * (const Complex &compl)const {
	return Complex(re * compl.re - im * compl.im, re * compl.im + im * compl.re);
}

const double Complex::abs() const {
	return sqrt(re*re + im*im);
}

ostream& operator<< (ostream &out, const Complex &compl) {
	out << compl.re << '+' << '(' << compl.im << ')' << 'i';
	return out;
}

//void main() {
//	Complex c1(-1, 2), c2(2, 9), c3;
//	c3 = c1 + c2;
//	cout << c3 << endl;
//	c3 = c1*c2;
//	cout << c3 << endl;
//	double a = c3.abs();
//	cout << a << endl;
//}
