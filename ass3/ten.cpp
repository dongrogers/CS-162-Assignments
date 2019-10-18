#include "ten.h"

using namespace std;


/*********************************************************************
** Function: Constructor
** Description: Inits values
** Parameters: None 
** Pre-Conditions: None
** Post-Conditions: Values initialized to 0 or NA or NULL
*********************************************************************/ 
tenant::tenant(){
	budget = 0;
	score = 0;
}


//Accessors
int tenant::get_score() const { return score; }
int tenant::get_budget() const { return budget; }


//Mutators
void tenant::set_budget(int num) { budget = num; }
void tenant::set_score(int num) { score = num; }


/*********************************************************************
** Function: Assn Operator
** Description: Copies over values
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return new copy
*********************************************************************/ 
const tenant& tenant::operator=(const tenant& copy){
	budget = copy.budget;
	score = copy.score;
	return* this;
}
