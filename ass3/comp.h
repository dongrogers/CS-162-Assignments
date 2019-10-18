#ifndef comp_h
#define comp_h
#include "prop.h"
using namespace std;

class space{
	private:
		string size;
		int rent;
	public:
		string get_size() const;
		int get_rent() const;
		void rand_set();
		void set_size(string size);
		void set_rent(int rent);
		const space& operator=(const space&);
};

class comp:public properties{
	private:
		int num_spaces;
		space* spaces;
	public:
		comp();
		void start();
		int random_comp_val();
		space* get_spaces() const;
		int get_num_spaces() const;
		int get_rent() const;
		void set_rent(int num, int index);
		void print();
		//AOO
		const comp& operator=(const comp&);
		//Destruct
		~comp();
};

#endif
