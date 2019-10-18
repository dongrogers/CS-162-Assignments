#include <iostream>
#include "menu.h"

using namespace std;

/*********************************************************************
** Function: get_num_pizzas
** Description: Finds number of pizzas
** Parameters: ifstream file
** Pre-Conditions: ifstream made
** Post-Conditions: num pizzas returned
*********************************************************************/ 
int get_num_pizzas(ifstream &menu){
	string line;
	int pizza = 0;
	while(!menu.eof()){
		getline(menu, line);
		if((line[0] >= 'A') &&  (line[0] <= 'z'))
			pizza++;
	}
	menu.clear();
	menu.seekg(0, menu.beg);
	return pizza;
}


/*********************************************************************
** Function: load_pizzas
** Description: assigns values for all pizzas
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: pizza values loaded
*********************************************************************/ 
void Menu::load_pizzas(){
	ifstream menu_txt;
	menu_txt.open("menu.txt");
	num_pizzas = get_num_pizzas(menu_txt);
	pizzas = new Pizza[num_pizzas];
	for(int i=0; i<num_pizzas; i++){
		string name;
		int s_cost, m_cost, l_cost, num_ing;
		menu_txt >> name >> s_cost >> m_cost >> l_cost >> num_ing;
		string* ingreds = new string[num_ing];
		for(int j=0; j<num_ing; j++)
			menu_txt >> ingreds[j];
		pizzas[i].set(name, s_cost, m_cost, l_cost, num_ing, ingreds);
	}
}

//Constructor
Menu::Menu(){
	num_pizzas = 0;
	pizzas = NULL;
}


/*********************************************************************
** Function: grow_array
** Description: grows array by one and does a deep copy
** Parameters: address of pizza array, size of array
** Pre-Conditions: none
** Post-Conditions: array grown by one, memory deleted and reassigned
*********************************************************************/ 
void grow_array(Pizza** old_pizza, int &num_p){
	Pizza* temp = new Pizza[num_p+1];
	for(int i=0; i<num_p; i++){
		temp[i] = (*old_pizza)[i];
	//	cout << "PIZZA GREW, ADDING BACK " << temp[i].get_name() << endl;
	}
	delete [] (*old_pizza);
	(*old_pizza) = temp;
	num_p++;
}


/*********************************************************************
** Function: search_pizza_by_cost
** Description: searches pizzas by cost, returns refined menu
** Parameters: upper cost bound, num of pizzas
** Pre-Conditions: none
** Post-Conditions: new menu returned
*********************************************************************/ 
Menu Menu::search_pizza_by_cost(int upper_bound, int num_pizzas){
	int cost, included = 0;
	Menu temp_menu;
	cout << endl;
	for(int i=0; i<num_pizzas; i++){
		cost = pizzas[i].get_s_cost();
		if(cost <= upper_bound){
			cout << pizzas[i].get_name() << " is under $" << upper_bound << endl;
			grow_array(&temp_menu.pizzas, included);
			temp_menu.pizzas[included-1] = pizzas[i];
		}
	}
	temp_menu.num_pizzas = included;
	return temp_menu;
}


/*********************************************************************
** Function: search_pizza_by_ingredients_to_include
** Description: searches pizzas by including ingredients
** Parameters: array of ingredients, num ingred, num pizzas
** Pre-Conditions: none
** Post-Conditions: refined menu
*********************************************************************/ 
Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients, int num_pizzas){
	int included = 0;
	Menu temp_menu;
	cout << endl;
	for(int i=0; i<num_pizzas; i++){
		for(int j=0; j<pizzas[i].get_num_ingred(); j++){
			for(int k=0; k<num_ingredients; k++){
				string* pizza_ingreds = pizzas[i].get_ingred();
				if(pizza_ingreds[j] == ingredients[k]){
					cout << pizzas[i].get_name() << " has " << pizza_ingreds[j] << endl;
					grow_array(&temp_menu.pizzas, included);
					temp_menu.pizzas[included-1] = pizzas[i];
					break;
				}
			}
		}
	}
	temp_menu.num_pizzas = included;
	return temp_menu;
}


/*********************************************************************
** Function: search_pizza_by_ingredients_to_exclude
** Description: searches pizzas by including ingredients
** Parameters: array of ingredients, num ingred, num pizzas
** Pre-Conditions: none
** Post-Conditions: refined menu
*********************************************************************/ 
Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients, int num_pizzas){
	int included = 0;
	Menu temp_menu;
	cout << endl;
	for(int i=0; i<num_pizzas; i++){
		for(int j=0; j<pizzas[i].get_num_ingred(); j++){
			for(int k=0; k<num_ingredients; k++){
				string* pizza_ingreds = pizzas[i].get_ingred();
				if(pizza_ingreds[j] == ingredients[k]){
					j = pizzas[i].get_num_ingred();
					break;
				}
				if((k == num_ingredients-1) && (j == pizzas[i].get_num_ingred()-1)){
					cout << pizzas[i].get_name() << " does not have " << ingredients[k] << endl;
					grow_array(&temp_menu.pizzas, included);
					temp_menu.pizzas[included-1] = pizzas[i];
					break;
				}
			}
		}
	}
	temp_menu.num_pizzas = included;
	return temp_menu;
	
}


//Accessors
int Menu::get_num_pizza() const { return num_pizzas; }
Pizza* Menu::get_pizzas() const { return pizzas; } 


//Mutator
void Menu::set_num_pizzas(int num) { num_pizzas = num; }


/*********************************************************************
** Function: add_to_menu
** Description: adds an item user wants to menu
** Parameters: a pizza element
** Pre-Conditions: user is employee
** Post-Conditions: added to file and menu
*********************************************************************/ 
void Menu::add_to_menu(Pizza pizza_to_add){
	grow_array(&pizzas, num_pizzas);
	cout << "Grew" << endl;
	pizzas[num_pizzas-1] = pizza_to_add;

	ofstream menuwrite;
	menuwrite.open("menu.txt", ios::app);
	menuwrite << pizza_to_add.get_name() << " " << pizza_to_add.get_s_cost() << " " << pizza_to_add.get_m_cost() << " " << pizza_to_add.get_l_cost() << " " << pizza_to_add.get_num_ingred() << " ";
	string* ingredients = pizza_to_add.get_ingred();
	for(int i=0; i<pizza_to_add.get_num_ingred(); i++){
		menuwrite << ingredients[i] << " ";
	}
	menuwrite << '\n';
	menuwrite.close();
	return;
}


/*********************************************************************
** Function: shrink_array
** Description: makes array smaller by 1, deep copy
** Parameters: address of pizza array, size of array
** Pre-Conditions: none
** Post-Conditions: array grown by one, memory deleted and reassigned
*********************************************************************/ 
void shrink_array(Pizza** old_pizza, int &num_p, int exclude){
	Pizza* temp = new Pizza[num_p-1];
	int tick = 0;
	for(int i=0; i<num_p; i++){
		if(i != exclude){
			temp[tick] = (*old_pizza)[i];
			tick++;
		}
	}
	delete [] (*old_pizza);
	(*old_pizza) = temp;
	num_p--;
}


/*********************************************************************
** Function: remove_from_menu
** Description: removes an item from menu
** Parameters: index of pizza
** Pre-Conditions: none
** Post-Conditions: menu returned smaller
*********************************************************************/ 
void Menu::remove_from_menu(int index_of_pizza_on_menu){
	shrink_array(&pizzas, num_pizzas, index_of_pizza_on_menu);
	return;
}


//Copy constructor
Menu::Menu(const Menu& copy){
	num_pizzas = copy.num_pizzas;
	pizzas = new Pizza[num_pizzas];
	for(int i=0; i<num_pizzas; i++){
		pizzas[i] = copy.pizzas[i];	
	} 
}

//Assignment overload constructor
const Menu& Menu::operator=(const Menu& copy){
	num_pizzas = copy.num_pizzas;
	if(pizzas != NULL)
		delete [] pizzas;
	if(num_pizzas == 0)
		pizzas = NULL;
	else{
		pizzas = new Pizza[num_pizzas];
		for(int i=0; i<num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];	
		}
	}
	return *this; 
}


//Destructor
Menu::~Menu(){
	delete [] pizzas;
}


