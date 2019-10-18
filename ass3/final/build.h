#include "prop.h"
#include "house.h"
#include "apt.h"
#include "comp.h"

class buildings{
	private:
		house* ghouses;
		apt* gapts;
		comp* gcomps;
		int num_house;
		int num_apt;
		int num_comp;

	public:

		buildings();

		//Accessors
		house* get_house() const;
		apt* get_apt() const;
		comp* get_comp() const;
		int get_num_house() const;
		int get_num_apt() const;
		int get_num_comp() const;

		//Mutate
		void set_house(house* shouse);
		void set_apt(apt* sapt);
		void set_comp(comp* scomp);
		void set_num_house(int num);
		void set_num_apt(int num);
		void set_num_comp(int num);
		
		void print();
		~buildings();
};


