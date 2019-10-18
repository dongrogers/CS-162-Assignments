#include <iostream>
#include <string>
#include "pizza.h"

using namespace std;

//Constructor
Pizza::Pizza(){
	name = "Test";	
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
}

//Nondefault constructor
Pizza::Pizza(string name_, int s_cost, int m_cost, int l_cost, int num_ingred, string *ingreds){
	name = name_;
	small_cost = s_cost;
	medium_cost = m_cost;
	large_cost = l_cost;
	num_ingredients = num_ingred;
	ingredients = ingreds;
}

//Accessors
string Pizza::get_name() const { return name; }
int Pizza::get_s_cost() const { return small_cost; } 
int Pizza::get_m_cost() const { return medium_cost; }
int Pizza::get_l_cost() const { return large_cost; }
int Pizza::get_num_ingred() const { return num_ingredients; }
string* Pizza::get_ingred() const { return ingredients; }


//Mutator
void Pizza::set(string pizza_name, int scost, int mcost, int lcost, int num_ing, string* ingreds){
	name = pizza_name;
	small_cost = scost;
	medium_cost = mcost;
	large_cost = lcost;
	num_ingredients = num_ing;
	ingredients = ingreds;
}

//Copy constructor
Pizza::Pizza(const Pizza& copy){
//	cout << "Copy Construct Pizza " << endl;
	cout << copy.name << endl;
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	if(num_ingredients == 0)
		ingredients = NULL;
	else{
		ingredients = new string[num_ingredients];
		for(int i=0; i<num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}
}

//Assignment overload constructor
const Pizza& Pizza::operator=(const Pizza& copy){
//	cout << "AOO Construct Pizza " << endl;
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	if(ingredients != NULL){
	//	delete [] ingredients;
	}
	if(num_ingredients == 0)
		ingredients = NULL;
	else{
		ingredients = new string[num_ingredients];
		for(int i=0; i<num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}
	return *this;
}

//Deconstructor
Pizza::~Pizza(){
	delete [] ingredients;
//	cout << "Ingredients finished" << endl;
	
}
