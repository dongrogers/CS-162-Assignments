#include "throw.h"

thrower::thrower(){
	armor = 1;
	damage = 1;
}

string thrower::type(){
	return "Thrower";
}

thrower* thrower::clone() const{
	return new thrower(*this);
}

bool thrower::isAnt() { return true; }
