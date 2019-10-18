#ifndef house_h
#define house_h
#include "prop.h"
using namespace std;


class house:public properties{
	private:
		int rent;
	public:
		house();

		//Mutate
		void start();

		void set_rent(int num);
		int get_budget() const;
		int get_rent() const;
		int get_ten_score() const;
		int random_house_val();
		void print();
		//Copy Constructor
		house(const house&);
		//AOO
		const house& operator=(const house& old_house);
		~house();
};

#endif
