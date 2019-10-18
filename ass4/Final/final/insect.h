#ifndef insect_h
#define insect_h
#include <iostream>
using namespace std;

class Insect{
	protected:
		int armor;
		int damage;
		int location;
	public: 
		Insect();
		int get_armor() const;
		int get_dmg();

		void takeDamage(int);
		
		void set_armor(int);
		void set_dmg(int);
		
		virtual bool isAnt() = 0;
		virtual Insect* clone() const;
		//Returns a string of what type of insect/ant
		virtual string type() = 0;
};

#endif	
