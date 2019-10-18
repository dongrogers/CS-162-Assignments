#include "ninja.h"

ninja::ninja(){
	armor = 1;
	damage = 1;
}

string ninja::type(){
	return "Ninja";
}

ninja* ninja::clone() const{
	return new ninja(*this);
}
		
bool ninja::isAnt() { return false; }
