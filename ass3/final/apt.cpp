#include "apt.h"

using namespace std;

/*********************************************************************
** Function: apt()
** Description: Constructor
** Parameters: None
** Pre-Conditions: Apt init
** Post-Conditions: Apt pop
*********************************************************************/ 
apt::apt(){
	value = 0;
	location = "NA";
	mortgage = 0;
	mortgage_duration = 0;
	rooms = 0;
	rent = 0;
	num_tens = 0;
	tenants = NULL;
}


/*********************************************************************
** Function: Start
** Description: Apt randomized values
** Parameters: None
** Pre-Conditions: Apt init
** Post-Conditions: Game started
*********************************************************************/ 
void apt::start(){
	value = random_apt_val();
	location = random_location();
	mortgage = random_mortgage();
	mortgage_duration = duration_mortgage(value, mortgage);
	rooms = rand() % 10 + 1;
	num_tens = rooms;
	tenants = new tenant[rooms];
	set_budget(5000, 500, rooms);
}


/*********************************************************************
** Function: Random Apt Val
** Description: Set random val
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Rand val returned
*********************************************************************/ 
int apt::random_apt_val(){
	//600k to 300k
	int value = rand() % 300000 + 300000;
	return value;
}


/*********************************************************************
** Function: Accessors/Mutators
** Description: Access/Mutate
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return
*********************************************************************/ 
void apt::set_rent(int num) { rent = num; }
int apt::get_rooms() const { return rooms; } 
int apt::get_rent() const{ return rent; }


/*********************************************************************
** Function: Print
** Description: Print basic values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Printed
*********************************************************************/ 
void apt::print(){
	cout << "Property Value: " << value << endl;
	cout << "Location: " << location << endl;
	cout << "Mortgage: " << mortgage << endl;
	cout << "Number of Spaces " << rooms << endl;
}


/*********************************************************************
** Function: Constructor 
** Description: Copies values
** Parameters: Reference
** Pre-Conditions: None
** Post-Conditions: Copied
*********************************************************************/ 
apt::apt(const apt& copy){
	value = copy.value;
	location = copy.location;
	mortgage = copy.mortgage;
	//might require a deep copy later for tenants
	tenants = copy.tenants;
	mortgage_duration = copy.mortgage_duration;
}


/*********************************************************************
** Function: Constructor 
** Description: Copies values
** Parameters: Reference
** Pre-Conditions: None
** Post-Conditions: Copied
*********************************************************************/ 
const apt& apt::operator=(const apt& copy){
	value = copy.value;
	location = copy.location;
	mortgage = copy.mortgage;
	mortgage_duration = copy.mortgage_duration;
	num_tens = copy.num_tens;
	rooms = copy.rooms;
	rent = copy.rent;
	if(tenants != NULL)
		delete [] tenants;
	else{
		tenants = new tenant[copy.rooms];
		for(int i=0; i<copy.rooms; i++){
			tenants[i] = copy.tenants[i];
		}
	}
	return *this;
}


/*********************************************************************
** Function: Deconstructor
** Description: Deletes dynamic
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Freed
*********************************************************************/ 
apt::~apt(){
	delete [] tenants;
}
