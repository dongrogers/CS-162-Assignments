#ifndef body_h 
#define  body_h
#include "insect.h"

using namespace std;

class bodyguard:public Insect{
	public:
	bodyguard();
	virtual string type();
	virtual bool isAnt();
	virtual bodyguard* clone() const;
};

#endif
