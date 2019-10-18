#include "wall.h"

using namespace std;

wall::wall(){
	armor = 4;
	damage = 0;
}

string wall::type(){
	return "Wall";
}

wall* wall::clone() const{
	return new wall(*this);
}
		
bool wall::isAnt(){ return true; }
