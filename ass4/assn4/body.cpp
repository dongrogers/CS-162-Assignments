#include "body.h"

bodyguard::bodyguard(){
	armor = 4;
	damage = 0;
}

string bodyguard::type(){
	return "Bodyguard";
}

bodyguard* bodyguard::clone() const{
	return new bodyguard(*this);
}

bool bodyguard::isAnt(){ return true; }
