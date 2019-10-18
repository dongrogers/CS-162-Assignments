#ifndef apt_h
#define apt_h
#include "prop.h"
using namespace std;

class apt:public properties{
	private:
		int rooms;
		int rent;
	public:
		apt();
		void start();
		int random_apt_val();

		void set_rent(int num);
		int get_rooms() const;	
		int get_rent() const;

		void print();
		//Copy Constructor
		apt(const apt&);
		const apt& operator=(const apt&);
		~apt();
};

#endif
