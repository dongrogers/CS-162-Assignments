#include "house.h"

using namespace std;


/*********************************************************************
** Function: Constructor
** Description: Inits values
** Parameters: None 
** Pre-Conditions: None
** Post-Conditions: Values initialized to 0 or NA or NULL
*********************************************************************/ 
house::house(){
	value = 0;
	location = "NA";
	mortgage = 0;
	mortgage_duration = 0;
	tenants = new tenant;
	//tenants = NULL;
	num_tens = 0;

}


/*********************************************************************
** Function: Start
** Description: Inits random values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initialized
*********************************************************************/ 
void house::start(){
	value = random_house_val();
	location = random_location();
	mortgage = random_mortgage();
	mortgage_duration = duration_mortgage(value, mortgage);
	num_tens = 1;
	set_budget(5000, 500, 1);	
}


//Accessors and Mutators
void house::set_rent(int num) { rent = num; }
int house::get_rent() const { return rent; }
int house::get_budget() const { return tenants[0].get_budget(); } 
int house::get_ten_score() const { return tenants[0].get_score(); }


/*********************************************************************
** Function:
** Description: Inits random values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initialized
*********************************************************************/ 
int house::random_house_val(){
	//600k to 100k
	int val = rand() % 500000 + 100000;
	return val;
}


/*********************************************************************
** Function: print
** Description: Prints all values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Print
*********************************************************************/ 
void house::print(){
	cout << "Property Value: " << value << endl;
	cout << "Location: " << location << endl;
	cout << "Mortgage: " << mortgage << endl;
	cout << "Tenant's Budget: " << tenants[0].get_budget() << endl;
}


/*********************************************************************
** Function: Copy con
** Description: Copies over values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return new copy
*********************************************************************/ 
house::house(const house& copy){
	cout << "House Copy" << endl;
	value = copy.value;
	location = copy.location;
	mortgage = copy.mortgage;
	//might require a deep copy later for tenants
	mortgage_duration = copy.mortgage_duration;
}


/*********************************************************************
** Function: Assn Operator
** Description: Copies over values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return new copy
*********************************************************************/ 
const house& house::operator=(const house& copy){
//	cout << "House AOO" << endl;
	value = copy.value;
	location = copy.location;
	mortgage = copy.mortgage;
	mortgage_duration = copy.mortgage_duration;
	num_tens = copy.num_tens;
	if(num_tens == 0)
		tenants = NULL;
	else{
	//	tenants = new tenant;
		tenants[0] = copy.tenants[0];
	}
	rent = copy.rent;
	return *this;
}


/*********************************************************************
** Function: Deconstructor
** Description: Deletes dynamic
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Freed memory
*********************************************************************/ 
house::~house(){
	//cout << "Tenants Deleted" << endl;
	delete tenants;
}
