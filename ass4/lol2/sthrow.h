#ifndef sthrow_h
#define sthrow_h
#include "insect.h"

using namespace std;

class sthrower:public Insect{
	public:
	sthrower();
	virtual string type();
	virtual bool isAnt();
	virtual sthrower* clone() const;
};

#endif
