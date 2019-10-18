#include "harv.h"

using namespace std;

harvest::harvest(){
	armor = 1;
}

string harvest::type(){
	return "Harvester";
}

harvest* harvest::clone() const{
	return new harvest(*this);
}
		
bool harvest::isAnt() { return true; }
