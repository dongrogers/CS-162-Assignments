#ifndef lthrow_h
#define lthrow_h
#include "insect.h"

using namespace std;

class lthrower:public Insect{
	public:
		lthrower();
		virtual string type();
		virtual bool isAnt();
		virtual lthrower* clone() const;
};

#endif
