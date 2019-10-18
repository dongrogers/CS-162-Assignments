#include "rect.h"

int rect::get_length() const { return length; }
int rect::get_width() const { return width; }

void rect::set_length(int num) { length = num; }
void rect::set_width(int num) { width = num; }

void rect::calc_area(){
	area = length*width;
}

rect::rect(string gname, string gcolor, int glength, int gwidth){
	name = gname;
	cout << "Name is " << name << endl;
	color = gcolor;
	cout << "Color is " << color << endl;
	length = glength;
	width = gwidth;
	cout << "Length is " << length << endl;
	cout << "Width is " << width << endl;
	calc_area();
	cout << "Area is " << area << endl;
}
