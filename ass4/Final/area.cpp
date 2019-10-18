#include "board.h"
#include "area.h"

using namespace std;

//Accessors and Mutators
vector<Insect*> Area::getInsects() const { return insects; }
void Area::setInsects(vector<Insect*> set) { insects = set; }


/*********************************************************************
** Function: getSize
** Description: Returns size of vector
** Parameters:
** Pre-Conditions:
** Post-Conditions: Integer returned
*********************************************************************/ 
int Area::getSize() { 
	int size = 0;
	size = insects.size();
	return size;
}


/*********************************************************************
** Function: Status
** Description: Prints all insects in area
** Parameters:
** Pre-Conditions:
** Post-Conditions: Print
*********************************************************************/ 
void Area::status(){
	for(int i=0; i<insects.size(); i++){
		cout << insects[i]->type() << ": " << "Armor: " << insects[i]->get_armor()  << " | " << "Damage: " << insects[i]->get_dmg() << endl;
	}
}


/*********************************************************************
** Function: checkType
** Description: Checks what kind of insect is at a certain area
** Parameters: Int
** Pre-Conditions:
** Post-Conditions: Return name 
*********************************************************************/ 
string Area::checkType(int index){
	return insects[index]->type();
}


//Text Editor Function
void colorRed(string text){
	cout << "\033[1;31m" << text << "\033[0m";
}


/*********************************************************************
** Function: addBee
** Description: Adds bee
** Parameters:
** Pre-Conditions:
** Post-Conditions:  Bee added
*********************************************************************/ 
void Area::addBee(){
	insects.push_back(new bee);
}


/*********************************************************************
** Function: addAnt
** Description: Adds ant if a user has bought one
** Parameters:
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/ 
void Area::addAnt(int choice){
	if(choice == 1)
		addHarvest();
	else if(choice == 2)
		addThrower();
	else if(choice == 3)
		addFire();
	else if(choice == 4)
		addLThrower();
	else if(choice == 5)
		addSThrower();
	else if(choice == 6)
		addNinja();
	else if(choice == 7)
		addBodyguard();
	else if(choice == 8)
		addWall();
}


/*********************************************************************
** Function: getHarvest
** Description: Returns total number of food collected
** Parameters:
** Pre-Conditions: Has Harvest
** Post-Conditions: Food returned
*********************************************************************/ 
int Area::getHarvest(){
	int food = 0;
	cout << insects.size() << "TEST " << endl;
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Harvester"){
			food++;
		}
	}
	return food;
}


/*********************************************************************
** Function: checkBees
** Description: Checks if bees exist in area
** Parameters:
** Pre-Conditions:
** Post-Conditions: Bool
*********************************************************************/ 
bool Area::checkBees(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Bee")
			return true;
	}
}


/*********************************************************************
** Function: checkNumBees
** Description: Checks number of bees
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Int
*********************************************************************/ 
int Area::checkNumBees(){
	int num = 0;
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Bee")
			num++;
	}
	return num;
}


/*********************************************************************
** Function: beesAttack
** Description: Reduces armor of all non bees by 1
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:  Bees attack
*********************************************************************/ 
void Area::beesAttack(){
//	cout << "SIZE BEING ATTACKED:" << insects.size() << endl;
	for(int i=0; i<insects.size(); i++){
		//cout << insects[i]->type() << endl;
		if((checkBody() == true) && (insects[i]->type() != "Bodyguard")){
			i++;
		}
		if(insects[i]->type() == "Bodyguard"){
			insects[i]->takeDamage(1);
			break;
		}
		else if((insects[i]->type() != "Bee") && (insects[i]->type() != "Ninja")){
			insects[i]->takeDamage(1);
			break;	
		}
	}
}


/*********************************************************************
** Function: removeDead
** Description: Removes dead insects from area
** Parameters: Integer
** Pre-Conditions:
** Post-Conditions: Dead removed
*********************************************************************/ 
int Area::removeDead(int num){
	int beesDead = 0;
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->get_armor() <= 0){
			colorRed("Removing Dead "); 
			cout << insects[i]->type();
			if(insects[i]->type() == "Bee")
				beesDead++;
			colorRed(" in Area ");
			cout << num+1 << endl;
			delete insects[i];
			insects.erase(insects.begin()+i);
		}
	}
	return beesDead;
}


/*********************************************************************
** Function: checkAnts
** Description: Checks if ants exist
** Parameters:
** Pre-Conditions:
** Post-Conditions: Bool
*********************************************************************/ 
bool Area::checkAnts(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->isAnt() == true)
			return true;
	}
	return false;
}


/*********************************************************************
** Function: damageBees
** Description: Hurts all bees in an area
** Parameters: Number
** Pre-Conditions:
** Post-Conditions: Bee damaged
*********************************************************************/ 
void Area::damageBees(int dmg){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Bee"){
			insects[i]->takeDamage(dmg);
		}
	}
}


/*********************************************************************
** Function: checkThrowers/Ninja
** Description: Check for existence
** Parameters:
** Pre-Conditions:
** Post-Conditions: Bool
*********************************************************************/ 
bool Area::checkThrowers(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Thrower")
			return true;
	}
}


bool Area::checkNinja(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Ninja")
			return true;
	}
}
/*********************************************************************/ 



/*********************************************************************
** Function: doThrower
** Description: Checks if thrower can attack
** Parameters:
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/ 
void Area::doThrower(){
	if(checkThrowers() == true){
		for(int i=0; i<insects.size(); i++){
			if(insects[i]->type() == "Bee"){
				insects[i]->takeDamage(1);
				colorRed("Thrower Ant: Damaged Bee for 1 damage.");
				cout << endl;
			}
		}
	}
}


/*********************************************************************
** Function: Check for all Ants
** Description: Checks for existence in area
** Parameters:None
** Pre-Conditions:None
** Post-Conditions: Bool
*********************************************************************/ 
bool Area::checkLThrowers(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Long Thrower")
			return true;
	}
}

bool Area::checkSThrowers(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Short Thrower")
			return true;
	}
}

bool Area::checkFires(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Fire")
			if(insects[i]->get_armor() == 0)
				return true;
	}
}

bool Area::checkBody(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Bodyguard")
			return true;
	}
	return false;
}

bool Area::checkWall(){
	for(int i=0; i<insects.size(); i++){
		if(insects[i]->type() == "Wall")
			return true;
	}
	return false;
}


/*********************************************************************
** Function: doFire
** Description: Checks if fire ants can explode and kill all ants
** Parameters:
** Pre-Conditions:
** Post-Conditions: Ants killed
*********************************************************************/ 
void Area::doFire(){
	if(checkFires() == true){
		colorRed("Fire Ant: All Bees killed.");
		cout << endl;
		for(int i=0; i<insects.size(); i++){
			if(insects[i]->type() == "Bee"){
				insects[i]->set_armor(0);
			}
		}
	}
}


/*********************************************************************
** Function: addAnt
** Description: Adds ant to area
** Parameters:
** Pre-Conditions: Ant bought
** Post-Conditions:  Ant added
*********************************************************************/ 
void Area::addHarvest(){
	insects.push_back(new harvest);	
}

void Area::addThrower(){
	insects.push_back(new thrower);	
}

void Area::addFire(){
	insects.push_back(new fire);	
}

void Area::addLThrower(){
	insects.push_back(new lthrower);	
}

void Area::addSThrower(){
	insects.push_back(new sthrower);	
}

void Area::addWall(){
	insects.push_back(new wall);	
}

void Area::addNinja(){
	insects.push_back(new ninja);	
}

void Area::addBodyguard(){
	insects.push_back(new bodyguard);	
}


/*********************************************************************
** Function: clearArea()
** Description: Clears the entire array unless its being passed
** Parameters:
** Pre-Conditions:
** Post-Conditions: Array cleared
*********************************************************************/ 
void Area::clearArea(){
	vector<Insect*> temp;
	if((checkAnts() == true) || (checkNinja() == true)){
		for(int i=0; i<insects.size(); i++){
			if(insects[i]->type() != "Bee"){
				temp.push_back(insects[i]->clone());
			}
			delete insects[i];
		}
		insects.clear();
		insects = temp;
		return;
	}
	else{
		for(int i=0; i<insects.size(); i++){
			delete insects[i];
		}
		insects.clear();
	}
}


/*********************************************************************
** Function: Assignment
** Description: Assigns right to left
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:  New copy
*********************************************************************/ 
Area& Area::operator=(const Area &copy){
	int numInsects = copy.insects.size();
	for(int i=0; i<numInsects; i++){
		if((copy.insects[i]->isAnt() == false) && (copy.insects[i]->type() != "Ninja"))
			insects.push_back(copy.insects[i]->clone());
	}
}

Area::~Area(){
	for(int i=0; i<insects.size(); i++){
		delete insects[i];
	}
	insects.clear();
}
