#ifndef shape_h
#define shape_h
#include <iostream>
#include <string>

using namespace std;

class shape{
	protected:
	string name;
	string color;
	int area;

	public:
	shape();
	virtual void calc_area() = 0;
	string get_name() const;
	string get_color() const;
	int get_area() const;

	void set_name(string set) ;
	void set_color(string set);
	void set_area(int set); 

	void print(shape&);
};

#endif
