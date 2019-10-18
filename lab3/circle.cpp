#include "circle.h"

int circle::get_radius() const { return radius; }
void circle::set_radius(int num) { radius = num; }

void circle::calc_area(){
	area = radius*radius*3.14;
}

circle::circle(string gname, string gcolor, int gradius){
	name = gname;
	cout << "Name is " << name << endl;
	color = gcolor;
	cout << "Color is " << color << endl;
	radius = gradius;
	cout << "Radius is " << radius << endl;
	calc_area();
	cout << "Area is " << area << endl;
}
