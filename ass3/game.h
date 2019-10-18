#include <iostream>
#include <string>
#include "prop.h"
#include "house.h"
#include "apt.h"
#include "comp.h"
#include "build.h"
#include "ten.h"

class Game{
	private:
		//Will store the buildings players can buy or sell
		buildings list;
		house* houses;
		apt* apts;
		comp* comps;

		int num_house;
		int num_apt;
		int num_comp;

		int money;
		int turn;
	public:
		Game();
		void run_menu();
		void choice_redirect(int choice);
		int get_money() const;
		int get_turn() const;
		void set_houses();
		void initial_turn();
		//Eror Check
		int get_num_bound(int upper, int lower);
		void check_gen();	
		void game_start();

		//Events
		void go_events();
		void run_event(properties* prop, int prop_num, int event);
		//
		void hurricane(properties* prop, int size);
		void tornado(properties* prop, int size);
		void earthquake(properties* prop, int size);
		void fire(properties* prop, int size);
		void stock_crash(properties* prop, int size);
		void gentrify(properties* prop, int size);
		//
		
		//Mortgages/Tax
		void print_balance();
		void business_increase();
		void pay_mortgage();
		void pay_tax();
		//Collect Rent
		void house_rent();
		void apt_rent();
		void comp_rent();
		void collect_rent();

		//Shrink array
		void shrink_house_array(house** old_house, int size, int exclude);
		void shrink_apt_array(apt** old_apt, int size, int exclude);
		void shrink_comp_array(comp** old_comp, int size, int exclude);
		int get_inrange();
		void sell_prop();
		void sell_house();
		void sell_apt();
		void sell_comp();
		//Grow array
		void grow_house_array(house** old_house, int index);
		void grow_apt_array(apt** old_apt, int index);
		void grow_comp_array(comp** old_comp, int index);
		int view_purchase(int index, int indexapt, int indexcomp);
		void buy_prop();
		//Buying
		void buy_house(int, int);
		void buy_apt(int, int);
		void buy_comp(int, int);
		//Rent control
		int print_props(int prop_type);
		int get_index(int prop_type);
		void adjust_rent();
		void set_rent(int prop_type, int index);
		void change_rent();
		//
		//Overload
		~Game();
};
