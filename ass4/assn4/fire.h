#ifndef fire_h
#define fire_h
#include "insect.h"
using namespace std;

class fire:public Insect{
	public:
		fire();
		string type();
		bool isAnt();
		virtual fire* clone() const;
};

#endif
