#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rect.h"
using namespace std;

int main(){
	circle circ("big", "green", 50);
	shape* take = &circ;
	cout << endl;
	cout << "Polymorphed" << endl;
	take->print(circ);
	cout << endl;


	rect rekt("small", "blue", 50, 50);
	shape* take2 = &rekt;
	cout << endl;
	cout << "Polymorphed" << endl;
	take2->print(rekt);
	cout << endl;
	cout << "Test" << endl;
	cout << take2->get_name() << endl;
}
