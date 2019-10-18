#include "insect.h"

Insect::Insect(){
	armor = 0;
	damage = 0;
}

int Insect::get_armor() const { return armor; } 
int Insect::get_dmg() { return damage; } 

void Insect::takeDamage(int dmg) { armor-= dmg; }

void Insect::set_armor(int num) { armor = num; }

Insect* Insect::clone() const{

}
