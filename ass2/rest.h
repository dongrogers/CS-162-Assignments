#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "menu.h"
#include "employee.h"

using namespace std;

class Restauraunt{
	private:
		Menu menu;
		int num_employs;
		int num_open;
		int num_orders;
		employee* employees;
		hours* week;
		string name;
		string phone;
		string address;
	public:
		Restauraunt();
		//Copy
		Restauraunt(const Restauraunt &);
		//Assign Overload
		Restauraunt & operator=(const Restauraunt &);
		void load_data();
		bool login();
		void view_menu();
		void view_hours();
		void view_address();
		void view_phone();
		void search_menu_by_price();
		void search_by_ingredients();
		void order_off();
		void choose_pizza();
		void place_order(Pizza* selection, int index);
		void change_hours();
		void add_to_menu();
		void remove_from_menu();
		void view_orders();
		void remove_orders();
		//Destructor
		~Restauraunt();
};

int get_real_num();
