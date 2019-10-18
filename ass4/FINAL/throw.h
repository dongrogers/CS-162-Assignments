#ifndef throw_h
#define throw_h
#include "insect.h"

using namespace std;

class thrower:public Insect{
	public:
	thrower();
	string type();
	bool isAnt();
	virtual thrower* clone() const;
};

#endif
