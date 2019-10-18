#ifndef prop_h
#define prop_h
#include <iostream>
#include <string>
#include <cstdlib>
#include "ten.h"
/*
#include "house.h"
#include "apt.h"
#include "comp.h"
*/

using namespace std;

class properties{
	protected:
		int value;
		string location;
		int mortgage;
		int mortgage_duration;
		static float const tax = 0.015;
		int num_tens;
		tenant* tenants;
	public:
		float get_tax() const ;
		int get_value() const;
		string get_locate() const;
		int get_mortgage() const;
		int get_rent() const;
		tenant* get_ten() const;
		int get_mortgage_duration() const;
		int get_num_ten() const;

		void set_num_tens(int num);
		void set_value(int new_val);
		void set_budget(int upper_bound, int lower_bound, int num_tens);
		void set_rent(int num); 
		void set_mortgage_duration(int num);
		/*
		void hurricane(properties prop);
		void tornado(properties prop);
		void earthquake(properties prop);
		void fire(properties prop);
		void stock_crash(properties prop);
		void gentrify(properties prop);
		*/

		
		string random_location();
		int random_mortgage();
		int duration_mortgage(int val, int mortgage);
		//Constructor	
		properties();
		~properties();
};


#endif
