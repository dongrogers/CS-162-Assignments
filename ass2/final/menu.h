#include <iostream>
#include <string>
#include <fstream>
#include "pizza.h"

using namespace std;

class Menu{
	private:
		int num_pizzas;
		Pizza* pizzas;
	public:
		//Constructs
		Menu();
		Menu search_pizza_by_cost(int upper_bound, int num_pizzas);
		Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients, int num_pizzas);
		Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients, int num_pizzas);
	
		//Accessors
		int get_num_pizza() const;
		Pizza* get_pizzas() const;

		//Mutators
		void set_num_pizzas(int num);
		void load_pizzas();
		void add_to_menu(Pizza pizza_to_add);
		void remove_from_menu(int index_of_pizza_on_menu);
	
		//Copy Constructor
		Menu(const Menu&);	

		//AOO
		const Menu& operator=(const Menu& copy);

		//Destructor
		~Menu();
};

