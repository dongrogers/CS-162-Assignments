#include "shape.h"

string shape::get_name() const{ return name; }
string shape::get_color() const { return color; }
int shape::get_area() const { return area; }

void shape::set_name(string set) { name = set; }
void shape::set_color(string set) { color = set; }
void shape::set_area(int set) { area = set; }

shape::shape(){
	name = "NA";
	color = "NA";
	area = 0;
}

void shape::print(shape& pass){
	cout << "Name is " << pass.get_name() << endl;
	cout << "Color is " << pass.get_color() << endl;
	cout << "Area is " << pass.get_area() << endl;
}
