#include "map.h"
using namespace std;

void main() {
	Map m(3);
	m.insert(4, "hi");
	cout << m.get(4);
}