#include "lthrow.h"

lthrower::lthrower(){
	damage = 1;
	armor = 1;
}

string lthrower::type(){
	return "Long Thrower";
}

lthrower* lthrower::clone() const{
	return new lthrower(*this);
}

bool lthrower::isAnt(){ return true; }
