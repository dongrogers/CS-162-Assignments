#include "comp.h"

using namespace std;


/*********************************************************************
** Function: rand space
** Description: Returns a random size
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: String
*********************************************************************/ 
string rand_space(){
int num = rand() % 3+1;
if(num == 1)
	return "Small";
if(num == 2)
	return "Medium";
if(num == 3)
	return "Large";
}


//Accessors
string space::get_size() const { return size; }
int space::get_rent() const { return rent; }
space* comp::get_spaces() const { return spaces; } 
int comp::get_num_spaces() const { return num_spaces; } 


//Mutators
void space::set_size(string gsize) { size = gsize; }
void space::set_rent(int grent) { rent = grent; }
void space::rand_set() { size = rand_space(); }
void comp::set_rent(int num, int index) { spaces[index].set_rent(num); }


/*********************************************************************
** Function: Assignment overload operator
** Description: Copies over space variables
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Copied over
*********************************************************************/ 
const space& space::operator=(const space& copy){
	size = copy.size;
	rent = copy.rent;
	return* this;
}


/*********************************************************************
** Function: Constructor
** Description: Inits values
** Parameters: None 
** Pre-Conditions: None
** Post-Conditions: Values initialized to 0 or NA or NULL
*********************************************************************/ 
comp::comp(){
	value = 0;
	location = "NA";
	mortgage = 0;
	mortgage_duration = 0;
	num_spaces = 0;
	num_tens = 0;
	spaces = NULL;
	tenants = NULL;

}


/*********************************************************************
** Function: Start
** Description: Inits random values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initialized
*********************************************************************/ 
void comp::start(){
	value = random_comp_val();
	location = random_location();
	mortgage = random_mortgage();
	mortgage_duration = duration_mortgage(value, mortgage);
	num_spaces = rand() % 5 + 1;
	num_tens = num_spaces;
	spaces = new space[num_spaces];
	for(int i=0; i<num_spaces; i++)
		spaces[i].rand_set();
	tenants = new tenant[num_spaces];
	set_budget(10000, 2000, num_spaces);
}


/*********************************************************************
** Function:
** Description: Inits random values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initialized
*********************************************************************/ 
int comp::random_comp_val(){
	//600k to 300k
	int value = rand() % 200000 + 400000;
	return value;
}


/*********************************************************************
** Function: get_rent
** Description: Adds up rent of all complex spaces
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return rent
*********************************************************************/ 
int comp::get_rent() const{
	int total = 0;
	for(int i=0; i<num_spaces; i++){
		total += spaces[i].get_rent();
	}
	return total;
}


/*********************************************************************
** Function: print
** Description: Prints all values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Print
*********************************************************************/ 
void comp::print(){
	cout << "Property Value: " << value << endl;
	cout << "Location: " << location << endl;
	cout << "Mortgage: " << mortgage << endl;
	cout << "Number of Spaces: " << num_spaces << endl;
	cout << "Space Sizes: ";
	for(int i=0; i<num_spaces; i++)
		cout << spaces[i].get_size() << " ";
	cout << endl;
}


/*********************************************************************
** Function: Assn Operator
** Description: Copies over values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return new copy
*********************************************************************/ 
const comp& comp::operator=(const comp& copy){
	value = copy.value;
	location = copy.location;
	mortgage = copy.mortgage;
	tenants = copy.tenants;
	mortgage_duration = copy.mortgage_duration;
	num_spaces = copy.num_spaces;
	num_tens = copy.num_tens;
//	if(spaces != NULL)
//		delete [] spaces;
//	if(tenants != NULL);
//		delete [] tenants;
//	else{
		spaces = new space[copy.num_spaces];
		tenants = new tenant[copy.num_spaces];
		for(int i=0; i<copy.num_spaces; i++){
			spaces[i] = copy.spaces[i];
			tenants[i] = copy.tenants[i];
		}
//	}
	return* this;
}


/*********************************************************************
** Function: Deconstructor
** Description: Deletes dynamic
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Freed memory
*********************************************************************/ 
comp::~comp(){
	delete [] spaces;
	delete [] tenants;
}
