#include "bee.h"

bee::bee(){
	armor = 3;
	damage = 1;
}

string bee::type(){
	return "Bee";
}

bee* bee::clone() const{
	return new bee(*this);
}
		
bool bee::isAnt(){
	return false;
}
