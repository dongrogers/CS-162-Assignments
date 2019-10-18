#ifndef ninja_h
#define ninja_h
#include "insect.h"

using namespace std;

class ninja:public Insect{
	public:
	ninja();
	string type();
	bool isAnt();
	virtual ninja* clone() const;
};

#endif
