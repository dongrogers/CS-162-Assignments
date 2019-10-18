#include "fire.h"

fire::fire(){
	armor = 1;
	damage = 0;
}

string fire::type(){
	return "Fire";
}

fire* fire::clone() const{
	return new fire(*this);
}

bool fire::isAnt(){ return true; }
