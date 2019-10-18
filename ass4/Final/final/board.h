#ifndef board_h
#define board_h
#include <iostream>
#include <string>
#include <vector>
#include "insect.h"
#include "area.h"
#include "bee.h"
#include "harv.h"
#include "throw.h"
#include "lthrow.h"
#include "sthrow.h"
#include "fire.h"
#include "body.h"
#include "ninja.h"
#include "wall.h"

using namespace std;

class board{
	private:
		bool queen;
		int food;
		int beeNum;
		//Array of polymorphable insects
		Area* area;
	public:
		board();
		void run_game();
		void boardStatus();
		bool checkBees();
		bool checkWin();
		void clearDead();
		//Add Bees
		void generateBee();

		//Purchase Functions
		void print_balance();
		bool canBuy(int);
		void printBuy(string, int);
		void getBuy();
		void placeAnt(int);

		void food_add();
		//Attack
		//do for loops of all attacking ants
		//run their location and types
		//compare if statements and attack
		
		//Ant Action Guide
		//For ants that have a pre-req, check the pre req, if true, then call the action, then code the rest in here
		void antActions();
		void beeActions();
		void doActions(int);

		void collectHarvest();
		void checkNinja(int);
		void checkThrower(int);
		void checkLThrower(int);
		void checkSThrower(int);
		void checkFire(int);	
		//How To Buy:
		//P
		//Buy ants;
		void buy_ant();
		void buy_harv();
		void buy_throw(); 
		void buy_lthrow();
		void buy_sthrow();
		void buy_fire();
		void buy_wall();
		void buy_ninja();
		void buy_body();


		//Text Effects
		void colorRed(string);
		void colorRedNum(int);
		void colorGreen(string);
		void colorGreenNum(int);

		~board();
};

#endif
