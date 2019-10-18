#ifndef area_h
#define area_h 
#include <iostream>
#include <string>
#include <vector>
#include "insect.h"
using namespace std;

class Area{
	private:
		//Array of polymorphable insects
		//Each element is a ptr to an object
		vector<Insect*> insects;
	public:
		void status();
		string checkType(int index);
		int getHarvest();

		vector<Insect*> getInsects() const;
		void setInsects(vector<Insect*>);
		int getSize();

		int removeDead(int);

		bool checkBees();
		int checkNumBees();
		bool checkAnts();
		void damageBees(int);
		void beesAttack();

		bool checkNinja();
		void clearNinja();

		bool checkThrowers();
		void doThrower();

		bool checkFires();
		void doFire();
		
		bool checkLThrowers();
		bool checkSThrowers();
		bool checkBody();
		bool checkWall();

		void addBee();
		void addAnt(int);
		void addHarvest();
		void addFire();
		void addThrower();
		void addLThrower();
		void addSThrower();
		void addWall();
		void addNinja();
		void addBodyguard();
		
		void clearArea();
		Area& operator=(const Area &copy);
		~Area();
					
};

#endif
