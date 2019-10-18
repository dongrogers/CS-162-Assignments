#ifndef rect_h
#define rect_h
#include "shape.h"
using namespace std;

class rect:public shape{
	private:
		int length;
		int width;
	public:
		
		rect(string gname, string gcolor, int glength, int gwidth);
		int get_length() const;
		int get_width() const;

		void set_length(int);
		void set_width(int);

		virtual void calc_area();

};

#endif
