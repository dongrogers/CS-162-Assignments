#include "board.h"

using namespace std;


/*********************************************************************
** Function: board()
** Description: Constructor, sets up basic data
** Parameters: None
** Pre-Conditions:
** Post-Conditions: Vals set
*********************************************************************/ 

board::board(){
	cout << string(50, '\n');
	area = new Area[10];
	beeNum = 25;
	food = 50;
	queen = true;
	run_game();


}

void space(int num){
	cout << string(num, '\n');
}


/*********************************************************************
** Function: checkWin
** Description: Checks for bees in queen 
** Parameters: None
** Pre-Conditions:
** Post-Conditions: Bool
*********************************************************************/ 

bool board::checkWin(){
	if(area[0].checkBees() == true)
		return true;
	return false;
}


/*********************************************************************
** Function: checkBees
** Description: Checks num bees left
** Parameters: None
** Pre-Conditions:
** Post-Conditions: Bool 
*********************************************************************/ 

bool board::checkBees(){
	bool beesOnBoard = true;
	for(int i=0; i<10; i++){
		if(area[i].checkBees() == true)
			return true;
		else
			beesOnBoard = false;
	}
	if((beeNum <= 0) && (beesOnBoard == false))
		return false;
	return true;
}

/*********************************************************************
** Function: runGame
** Description: Runs the bulk of the game, is set on a loop 
** Parameters: None
** Pre-Conditions:
** Post-Conditions: Game ends
*********************************************************************/ 
void board::run_game(){
	while(1){
		//Generate Bee
		if(beeNum > 0){
			colorGreen("BEES LEFT : ");
			colorRedNum(beeNum);
		}
		space(1);
		if(beeNum > 0)
			generateBee();
		//Buy and Place Ant
		buy_ant();
		space(50);
		//ants attack
		antActions();
		clearDead();
		//bees attack
		beeActions();
		clearDead();
		//print board
		boardStatus();
		print_balance();
		if(checkWin() == true){
			colorRed("You lose. Bees have reached the queen");
			space(2);
			return;
		}
		if(checkBees() == false){
			colorRed("You win. No bees left");
			space(2);
			return;
		}
	}
}


/*********************************************************************
** Function: Text Editing Functions
** Description: Turns text into colors for better interface
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Text turned colors
*********************************************************************/ 
void board::colorRed(string text){
	cout << "\033[1;31m" << text << "\033[0m";
}

void board::colorRedNum(int num){
	cout << "\033[1;31m" << num << "\033[0m";
}

void board::colorGreen(string text){
	cout << "\033[1;35m" << text << "\033[0m";
}

void board::colorGreenNum(int num){
	cout << "\033[1;35m" << num << "\033[0m";
}
/*********************************************************************/ 


/*********************************************************************
** Function: printBuy 
** Description: Prints a purchase
** Parameters: Ant name and cost
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::printBuy(string ant, int foodCost){
	cout << "You got a "; 
	colorRed(ant);
	cout << " " << foodCost << " food deducted" << endl;
	food -= foodCost;
}


/*********************************************************************
** Function: printBalance
** Description: Prints balance
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::print_balance(){
	colorGreen("Food Balance: ");
	colorGreenNum(food);
	space(2);
}


/*********************************************************************
** Function: printList
** Description: Prints list of ants 
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void printList(){
	cout << "What ant do you want? " << endl;
	cout << "1. Harvester " << endl;
	cout << "2. Thrower " << endl;
	cout << "3. Fire " << endl;
	cout << "4. Long Thrower " << endl;
	cout << "5. Short Thrower " << endl;
	cout << "6. Ninja " << endl;
	cout << "7. Bodyguard " << endl;
	cout << "8. Wall " << endl;
	cout << "0. Skip Buy this Turn" << endl;

}


/*********************************************************************
** Function: printBalance
** Description: Prints balance
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::getBuy(){
	int buy = 0;
	bool goodBuy = false;
	while(1){
		buy = get_num_bound(8, 0);
		if(canBuy(buy) == true)
			break;
	}
		if(buy == 0)
			return;
		else if(buy == 1)
			buy_harv();
		else if(buy == 2)
			buy_throw();
		else if(buy == 3)
			buy_fire();
		else if(buy == 4)
			buy_lthrow();
		else if(buy == 5)
			buy_sthrow();
		else if(buy == 6)
			buy_ninja();
		else if(buy == 7)
			buy_body();
		else if(buy == 8)
			buy_wall();
}


/*********************************************************************
** Function:generateBee 
** Description: Generates bee at end of array 
** Parameters:
** Pre-Conditions:
** Post-Conditions: Bee memory allocated
*********************************************************************/ 
void board::generateBee(){
	area[9].addBee();	
}


/*********************************************************************
** Function: placeAnt
** Description: Places ant on board
** Parameters: Type of ant
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::placeAnt(int type){
	//Get Area
	cout << "What area should this ant go in? (Area 1 - Area 10)" << endl;
	int choice = 0;

	//Checking for Ants
	while(1){
		choice = get_num_bound(10, 0);
		if(choice == 0)
			return;
		else if(area[choice-1].getSize() != 0){
			if(((area[choice-1].checkAnts() == true) && (type != 7)) || (area[choice-1].checkBody() == true))
				cout << "Already an ant in that area, choose a different area or enter 0 to cancel." << endl;
			else
				break;
		}
		else if(area[choice-1].getSize() == 0)
			break;
	}

	//Insert
	area[choice-1].addAnt(type);

	//Print Text
	cout << "Ant placed in ";
	colorRed("Area ");
	colorRedNum(choice);
	cout << endl;
	space(1); 
}


/*********************************************************************
** Function: Buy Ant
** Description: Simple buy control 
** Parameters:
** Pre-Conditions:
** Post-Conditions: Ant bought
*********************************************************************/ 
void board::buy_ant(){
	//Prints
	printList();
	//Redirects Buy and Assigns Area
	getBuy();
	//End buy
}


/*********************************************************************
** Function: canBuy
** Description:  Checks if food amount is enough
** Parameters:
** Pre-Conditions:
** Post-Conditions: Bool
*********************************************************************/ 
bool board::canBuy(int type){
	if((type == 1) && (food < 2))
		return false;
	else if((type == 2) && (food < 4)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}			
	else if((type == 3) && (food < 4)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}
	else if((type == 4) && (food < 3)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}
	else if((type == 5) && (food < 3)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}
	else if((type == 6) && (food < 6)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}	
	else if((type == 7) && (food < 4)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}
	else if((type == 8) && (food < 4)){
		colorGreen("Not enough food to buy this ant!");
		return false;
	}
	else{
		return true;
	}
}


/*********************************************************************
** Function: Functions for Buying 
** Description: Places the ant on board, prints out statement
** Parameters: None
** Pre-Conditions: User bought ant
** Post-Conditions: Ant bought and placed
*********************************************************************/ 
void board::buy_harv(){
	printBuy("Harvester Ant", 2);
	placeAnt(1);
}

void board::buy_throw(){
	printBuy("Thrower Ant", 4);
	placeAnt(2);
}

void board::buy_lthrow(){
	printBuy("Long Thrower Ant", 3);
	placeAnt(4);
}

void board::buy_sthrow(){
	printBuy("Short Thrower Ant", 3);
	placeAnt(5);
}

void board::buy_fire(){
	printBuy("Fire Ant", 4);
	placeAnt(3);
}

void board::buy_wall(){
	printBuy("Wall", 4);
	placeAnt(8);
}

void board::buy_ninja(){
	printBuy("Ninja Ant", 6);
	placeAnt(6);
}

void board::buy_body(){
	printBuy("Bodyguard Ant", 4);
	placeAnt(7);
}

/*********************************************************************/ 


/*********************************************************************
** Function: boardStatus
** Description: Prints all insects
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::boardStatus(){
	for(int i=0; i<10; i++){
		cout << "Area ";
		colorRedNum(i+1);
		cout << ":" << endl;
		area[i].status();
		space(1);
	}
}



/*********************************************************************
** Function: clearDead
** Description: Clears any ant with armor 0
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Dead cleared
*********************************************************************/ 
void board::clearDead(){
	for(int i=0; i<10; i++){
		beeNum -= area[i].removeDead(i);
	}
}


/*********************************************************************
** Function: antActions
** Description: Runs through actions for 10 areas
** Parameters: None
** Pre-Conditions: 
** Post-Conditions: Actions done
*********************************************************************/ 
void board::antActions(){
	for(int i=0; i<10; i++){
		doActions(i);
	}
}


/*********************************************************************
** Function: doActions
** Description: Does an action in each area if exists
** Parameters: Integer
** Pre-Conditions:
** Post-Conditions: Action done
*********************************************************************/ 
void board::doActions(int area){
	//All Ant Actions
	checkThrower(area);
	checkLThrower(area);
	checkSThrower(area);
	checkNinja(area);	
}


/*********************************************************************
** Function: beeActions
** Description: Does Bees actions involving move and attack
** Parameters:
** Pre-Conditions:
** Post-Conditions: Bees move and attack
*********************************************************************/ 
void board::beeActions(){
	for(int i=1; i<10; i++){
		for(int j=0; j<area[i].checkNumBees(); j++){
			//Attacking Current Square
			if((area[i].checkAnts() == true) && (area[i].checkBees() == true)){
				area[i].beesAttack();
				checkFire(i);
				clearDead();
			}

			//Attacking Next Square
			else if((area[i-1].checkAnts() == true) && (area[i].checkBees() == true)){
				area[i-1].beesAttack();
				checkFire(i);
				clearDead();
			}
			//Move Forward
			if((area[i-1].checkWall() == false) && (area[i].checkBees() == true)){
				colorGreen("Advancing Bees forward to Area ");
				colorGreenNum(i);
				colorGreen(" from Area " );
				colorGreenNum(i+1);
				space(1);
				area[i-1] = area[i];
				area[i].clearArea();
				break;
			}
		}	
	}
}


/*********************************************************************
** Function: collectHarvest
** Description:  Looks for harvest ants and collects food
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: COllected
*********************************************************************/ 
void board::collectHarvest(){
	int count = 0; 
	for(int i=0; i<10; i++){
		count += area[i].getHarvest();	
	}

	if(count > 0){
		colorRed("Harvester Ants");
		cout << ": Adding ";
		colorGreenNum(count);
		cout << " food." << endl;
	}
}


/*********************************************************************
** Function: checkThrower
** Description: Checks if thrower ant can attack ants
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::checkThrower(int index){
	area[index].doThrower();
}


/*********************************************************************
** Function: checkNinja
** Description: Checks if ninja can attack
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void board::checkNinja(int index){
	if((area[index].checkBees() == true) && (area[index].checkNinja() == true)){
		colorRed("Ninja Ant: Damaged Bee for 1 Damage in Area ");
		colorRedNum(index);
		space(1);
		area[index].damageBees(1);

	}
}


/*********************************************************************
** Function: checkLThrower
** Description: Checks if ants 4 spaces away, attacks
** Parameters:
** Pre-Conditions:
** Post-Conditions: Attacks
*********************************************************************/ 
void board::checkLThrower(int index){
	if(index <= 5){
		if(area[index].checkLThrowers() == true){ 
			for(int i=index; i<=(10-i); i++){
				if(area[i+4].checkBees() == true){
					colorRed("Long Thrower Ant: Damaged Bee for 1 Damage in Area ");
					colorRedNum(i+5);
					space(1);
					area[i+4].damageBees(1);
					break;
				}
			}
		}	
	}
}


/*********************************************************************
** Function: checkSThrower
** Description: Checks if ants 2 spaces within exists
** Parameters: Integer
** Pre-Conditions: None
** Post-Conditions: Attacked
*********************************************************************/ 
void board::checkSThrower(int index){
	if(area[index].checkSThrowers() == true){
		if(index >= 0 && index <= 7)
			for(int i=0; i<3; i++){
				if(area[index+i].checkBees() == true){
					colorRed("Short Thrower Ant: Damaged Bee for 1 Damage in Area ");
					colorRedNum(i+index+1);
					space(1);
					area[index+i].damageBees(1);
					return;
				}
			}
		else if(index >= 8 && index <= 9){
			if(area[8].checkBees() == true){
				colorRed("Short Thrower Ant: Damaged Bee for 1 Damage in Area ");
				colorRedNum(9);
				space(1);
				area[8].damageBees(1);
				return;
			}
			else if(area[9].checkBees() == true)
				colorRed("Short Thrower Ant: Damaged Bee for 1 Damage in Area ");
				colorRedNum(10);
				space(1);
				area[9].damageBees(1);
				return;
		}
	}	
}



/*********************************************************************
** Function: checkFire
** Description: Checks if any fire ants are dead, kills all bees
** Parameters: Int 
** Pre-Conditions: None
** Post-Conditions: Bees killed
*********************************************************************/ 
void board::checkFire(int index){
	//Check while bees attack
	area[index].doFire();
}

board::~board(){
	delete [] area;
}
