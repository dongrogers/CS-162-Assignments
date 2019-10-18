#ifndef circle_h
#define circle_h
#include "shape.h"

using namespace std;


class circle:public shape{
	private:
		int radius;
	public:
		circle(string, string, int);
		int get_radius() const;
		void set_radius(int);

		virtual void calc_area();
		
};

#endif
