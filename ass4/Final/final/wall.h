#ifndef wall_h 
#define wall_h
#include "insect.h"
using namespace std;

class wall:public Insect{
	private:
			
	public:
	wall();
	virtual string type();
	virtual bool isAnt();
	virtual wall* clone() const;
};

#endif
