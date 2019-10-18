#ifndef harv_h
#define harv_h
#include "insect.h"
using namespace std;

class harvest:public Insect{
	private:
			
	public:
		harvest();
		string type();
		bool isAnt();
		virtual harvest* clone() const;
		


};

#endif
