#include "prop.h"
using namespace std;


/*********************************************************************
** Function: properties()
** Description: Constructor
** Parameters: None
** Pre-Conditions: Prop init
** Post-Conditions: Prop pop
*********************************************************************/ 
properties::properties(){
	value = 0;
	location = "N/A";
	mortgage = 0;
}


//Accessors
tenant* properties::get_ten() const { return tenants; }
float properties::get_tax() const { return tax; }
int properties::get_value() const { return value; }
string properties::get_locate()const { return location; }
int properties::get_mortgage() const { return mortgage; } 
int properties::get_mortgage_duration() const { return mortgage_duration; }
int properties::get_num_ten() const { return num_tens; }


//Mutators
void properties::set_num_tens(int num) { num_tens = num; }
void properties::set_mortgage_duration(int num) { mortgage_duration = num; }
void properties::set_value(int new_val) { value = new_val; }


/*********************************************************************
** Function: set_budget
** Description: Returns a random budget
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Budget set
*********************************************************************/ 
void properties::set_budget(int upper_bound, int lower_bound, int num_tens){
	for(int i=0; i<num_tens; i++){
		int val = (rand() % (upper_bound-lower_bound) + lower_bound);
		tenants[i].set_budget(val);
		val = rand() % 5+1;
		tenants[i].set_score(val);
	}
}


/*********************************************************************
** Function: rand location
** Description: Returns a random location
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: String
*********************************************************************/ 
string properties::random_location(){
	int val = rand() % 5+1;
	if(val == 1)
		return "SE";
	if(val == 2)
		return "NE";
	if(val == 3)
		return "Midwest";
	if(val == 4)
		return "SW";
	if(val == 5)
		return "NW";
}


/*********************************************************************
** Function: rand mortgage
** Description: Returns a random value
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Integer returned
*********************************************************************/ 
int properties::random_mortgage(){
	int val = rand() % 5000;
	return val;
}


/*********************************************************************
** Function: duration mortgage
** Description: Calculates duration
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Duration set
*********************************************************************/ 
int properties::duration_mortgage(int val, int mortgage){
	int months;
//	cout << "VALUE: " << value << endl;
//	cout << "MORT: " << mortgage << endl;
	months = (val / mortgage);
	return months;
}


properties::~properties(){
}
