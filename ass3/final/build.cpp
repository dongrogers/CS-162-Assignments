#include "build.h"


/*********************************************************************
** Function: Constructor
** Description: Initialize values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/ 
buildings::buildings(){
	num_house = 3;
	num_apt = 3;
	num_comp = 3;
}


//Accessors
house* buildings::get_house() const { return ghouses; }
apt* buildings::get_apt() const { return gapts; }
comp* buildings::get_comp() const { return gcomps; }
int buildings::get_num_house() const { return num_house; }
int buildings::get_num_apt() const { return num_apt; }
int buildings::get_num_comp() const { return num_comp; }

//Mutators
void buildings::set_house(house* shouse) { ghouses = shouse; }
void buildings::set_apt(apt* sapt) { gapts = sapt; }
void buildings::set_comp(comp* scomp) { gcomps = scomp; }
void buildings::set_num_house(int num) { num_house = num; }
void buildings::set_num_apt(int num) { num_apt = num; }
void buildings::set_num_comp(int num) { num_comp = num; }


/*********************************************************************
** Function: print
** Description: Prints all values of every property
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints
*********************************************************************/ 
void buildings::print(){
	for(int i=0; i<num_house; i++){
		cout << "Houses" << endl;
		cout << "Property Value: " << ghouses[i].get_value() << endl;
		cout << "Location: " << ghouses[i].get_locate() << endl;
		cout << "Mortgage: " << ghouses[i].get_mortgage() << endl;
	}	
	for(int i=0; i<num_apt; i++){
		cout << "Apts" << endl;
		cout << "Property Value: " << gapts[i].get_value() << endl;
		cout << "Location: " << gapts[i].get_locate() << endl;
		cout << "Mortgage: " << gapts[i].get_mortgage() << endl;
	}	
	for(int i=0; i<num_comp; i++){
		cout << "Comp" << endl;
		cout << "Property Value: " << gcomps[i].get_value() << endl;
		cout << "Location: " << gcomps[i].get_locate() << endl;
		cout << "Mortgage: " << gcomps[i].get_mortgage() << endl;
	}
	cout << "Number of Houses: " << num_house << endl;
	cout << "Number of Apts: " << num_apt<< endl;
	cout << "Number of Comps: " << num_comp << endl;
}


/*********************************************************************
** Function: Deconstructor
** Description: Deletes properties
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Freed
*********************************************************************/ 
buildings::~buildings(){
	if(num_house > 0){
		delete [] ghouses;
	}
	if(num_house > 0){
		delete [] gapts;
	}
	if(num_comp > 0)
		delete [] gcomps;
}
