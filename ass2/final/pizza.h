#include <iostream>
#include <string>

using namespace std;

class Pizza{
	private:
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		int num_ingredients;
		string* ingredients;
	public:
		//Constructs
		Pizza();
		Pizza(string name_, int s_cost, int m_cost, int l_cost, int num_ingred, string *ingreds);
		
		//Access
		string get_name() const;
		int get_s_cost() const;
		int get_m_cost() const;
		int get_l_cost() const;
		int get_num_ingred() const;
		string* get_ingred() const;
		
		//Mutators
		void set(string pizza_name, int scost, int mcost, int lcost, int num_ing, string* ingreds);

		//Copy Constructor
		Pizza(const Pizza& copy);
		
		//Assn Overload
		const Pizza& operator=(const Pizza& copy);

		//Destructor
		~Pizza();

};

