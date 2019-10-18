#ifndef bee_h
#define bee_h
#include "insect.h"

using namespace std;

class bee:public Insect{
	protected:
	public:
		bee();
		virtual string type();
		virtual bool isAnt();
		virtual bee* clone() const;
};

#endif
