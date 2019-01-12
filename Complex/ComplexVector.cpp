#include <iostream>
#include "Complex.h"
#include "../linked_list.h"
using namespace std;

class ComplexVector{
private:
	int dimension;
	List<Complex> coordinates;
public:
	ComplexVector() {
		dimension = 0;
	}
	ComplexVector(List<Complex> Vector) {
		coordinates = Vector;
		dimension = Vector.size();
	}
	ComplexVector(ComplexVector &copy) {
		dimension = copy.dimension;
		coordinates = copy.coordinates;
	}
	~ComplexVector() {

	}

	ComplexVector operator+(const ComplexVector &Vector)const;
	void print();
};

void ComplexVector::print() {
	coordinates.print();
}
ComplexVector ComplexVector::operator+(const ComplexVector &Vector)const {
	List<Complex> Vector1(this->coordinates);
	List<Complex> Vector2 = Vector.coordinates;
	List<Complex> newCoordinates;

	while (!Vector1.is_empty() && !Vector.coordinates.is_empty())
		newCoordinates.push_back(Vector1.pop_front() + Vector2.pop_front());

	while (!Vector1.is_empty())
		newCoordinates.push_back(Vector1.pop_front());

	while (!Vector2.is_empty())
		newCoordinates.push_back(Vector2.pop_front());

	return ComplexVector(newCoordinates);
}

void main(){
	List<Complex> Vector;
	Vector.push_back(Complex(-1, 2));
	Vector.push_front(Complex(1, 1));
	Vector.push_back(Complex(2, 9));
	ComplexVector complexVector1(Vector);
	complexVector1.print();
	cout << endl;
	Vector.push_front(Complex(-4, 1));
	Vector.push_back(Complex(2, 2));
	ComplexVector complexVector2(Vector);
	complexVector2.print();
	cout << endl;
	ComplexVector complexVector3(complexVector1 + complexVector2);
	complexVector3.print();

}
