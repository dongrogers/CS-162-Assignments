#include "sthrow.h"

sthrower::sthrower(){
	damage = 1;
	armor = 1;
}

string sthrower::type(){
	return "Short Thrower";
}

sthrower* sthrower::clone() const{
	return new sthrower(*this);
}
		
bool sthrower::isAnt(){ return true; }
