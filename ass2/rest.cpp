#include <string>
#include "rest.h"

using namespace std;


/*********************************************************************
** Function: is_int, get_int, get_real_num
** Description: Takes user input as string, returns number
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Integer returned
*********************************************************************/ 
bool is_int(string op){
	for(int i=0; i<op.length(); i++){
		if ((op[i] < '0') || (op[i] > '9')){
			return false;
		}
	}
	return true;
}


int get_int(string num){
	int counter = 0;
	float newnum = 0;
	for(int i=(num.length()-1), j=1; i>=0; i--){
		newnum += ((num[i]-48)*j);
		j = j*10;
	}
	return newnum;
}

int get_real_num(){
	bool good = true;
	string num;
	while(good == true){
		cout << "Enter a number: ";
		cin >> num;
		if(is_int(num) == true){
			return get_int(num);
		}
	}
	
}


/*********************************************************************
** Function: get_num
** Description: Checks if parameter is a valid string with numbers
** Parameters: String
** Pre-Conditions: None
** Post-Conditions: String returned with numbers only
*********************************************************************/ 
void get_num(string &name){
	bool good = false;
	string temp;
	while(good == false){
		getline(cin, temp);
		if(temp == "Q"){
			name = temp;
			return;
		}
		for(int i=0; i<temp.length(); i++){
			if(temp[i] < '0' || temp[i] > '9'){
				if(temp[i] != ' '){
					cout << temp[i] << endl;
					cout << "Bad input, numbers only" << endl;
					break;
				}
			}
			if(i == temp.length()-1){
				name = temp;
				return;	
			}
		}
	}
}


/*********************************************************************
** Function: get_string
** Description: Checks if parameter is a valid string with letters
** Parameters: String
** Pre-Conditions: None
** Post-Conditions: String returned with letters only
*********************************************************************/ 
void get_string(string &name){
	bool good = false;
	string temp;
	while(good == false){
		getline(cin, temp);
		for(int i=0; i<temp.length(); i++){
			if(temp[i] < 'A' || temp[i] > 'z'){
				if(temp[i] != ' '){
					cout << temp[i] << endl;
					cout << "Bad input, letters only" << endl;
					break;
				}
			}
			if(i == temp.length()-1){
				name = temp;
				return;	
			}
		}
	}
}


/*********************************************************************
** Function: get_num_employees
** Description: Gets number of employees be reading lines
** Parameters: Employee file
** Pre-Conditions: None
** Post-Conditions: Number returned
*********************************************************************/ 
int get_num_employees(ifstream &employee){
	string line;
	int employees = 0;
	while(!employee.eof()){
		getline(employee, line);
		if((line[0] >= '0') && (line[0] <= '9'))
			employees++;
	}
	employee.clear();
	employee.seekg(0, employee.beg);
	return employees;
}


/*********************************************************************
** Function: get_num_orders
** Description: Gets number of orders be reading lines
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Number returned
*********************************************************************/ 
int get_num_orders(){
	ifstream orders;
	orders.open("orders.txt");
	string line;
	int employees = 0;
	while(!orders.eof()){
		getline(orders, line);
		if((line[0] >= '0') && (line[0] <= '9'))
			employees++;
	}
	orders.clear();
	orders.seekg(0, orders.beg);
	orders.close();
	return employees;
}


/*********************************************************************
** Function:load_employees
** Description: fills employee struct
** Parameters: employee array, file employee, num employee
** Pre-Conditions: none
** Post-Conditions: struct filled
*********************************************************************/ 
void load_employees(employee* employees, ifstream &employ, int num_emp){
	for(int i=0; i<num_emp; i++){
		employ >> employees[i].id >> employees[i].first_name >> employees[i].last_name >> employees[i].password;
	}
}


/*********************************************************************
** Function:set_hours
** Description: fills hours struct
** Parameters: hours array, file, num of days open
** Pre-Conditions: none
** Post-Conditions: struct filled
*********************************************************************/ 
void set_hours(hours* times, ifstream& file, int num_days){
	for(int i=0; i<num_days; i++){
		file >> times[i].day >> times[i].open_hour >> times[i].close_hour;
	}
}


/*********************************************************************
** Function: load_data
** Description: calls all functions to load all structs/classes
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: classes/structs filled
*********************************************************************/ 
void Restauraunt::load_data(){
	ifstream rest, employ;
	rest.open("restaurant_info.txt");
	employ.open("employee.txt");

	//Employees
	
	int num_emp = get_num_employees(employ);
	employees = new employee[num_emp];
	load_employees(employees, employ, num_emp);
	num_employs = num_emp;

	//Restauraunt
	getline(rest, name); 
	getline(rest, phone);
	getline(rest, address);
	rest >> num_open;	
	menu.load_pizzas();

	//Hours
	week = new hours[num_open];
	set_hours(week, rest, num_open);

	rest.close();
	employ.close();
}


//Default constructor
Restauraunt::Restauraunt(){
	load_data();
}


/*********************************************************************
** Function: id_check
** Description: Checks if user entered good id
** Parameters: Employee array, index of id, num employees
** Pre-Conditions: None
** Post-Conditions: True/False
*********************************************************************/ 
bool id_check(employee* employees, int& id_index, int num_employs){
	string id;
	bool good_id = false;
	while(good_id == false){
		cout << "Enter ID number: ";
		get_num(id);
		if(id[0] == 'Q'){
			cout << "Quitting" << endl;
			return false; 
		}
		for(int i=0; i<num_employs; i++){
			if(id == employees[i].id){
				good_id = true;
				id_index = i;
				return true;
			}
			else if(i == num_employs-1)
				cout << "Bad ID number, does not exist" << endl;
		}
	}
	return true;
}


/*********************************************************************
** Function: pass_check
** Description: Checks if user entered good password
** Parameters: Employee array, index of id, num employees
** Pre-Conditions: None
** Post-Conditions: True/False
*********************************************************************/ 
bool pass_check(employee* employees, int id_index, int num_employs){
	string pass;
	bool good_pass = false;
	while(good_pass == false){
		cout << "Enter password : ";
		getline(cin, pass);
    if(pass[0] == 'Q')
        return false;
		if(pass == employees[id_index].password){
			return true;
		}
		else{
			cout << "Wrong password." << endl;
		}
	}
}


/*********************************************************************
** Function: login
** Description: Checks for login details
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: True/False
*********************************************************************/ 
bool Restauraunt::login(){
	int employee_index = 0;
	cout << "Log in, type Q to quit at any time. " << endl;
//	string id = id_check(employees, employee_index, num_employs);
	if(id_check(employees, employee_index, num_employs) == true){
		if(pass_check(employees, employee_index, num_employs) == true){
			cout << endl;
			cout << "Welcome, " << employees[employee_index].first_name << " " << employees[employee_index].last_name << endl;
			return true;
		}
	}	
	else{
		return false;
	}
}


/*********************************************************************
** Function:view_menu
** Description: prints menu out
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: menu printed
*********************************************************************/ 
void Restauraunt::view_menu(){
	int num = menu.get_num_pizza();
	Pizza* pizzas = menu.get_pizzas();
	for(int i=0; i<num; i++){
		cout << pizzas[i].get_name() << " S " << pizzas[i].get_s_cost() << " M " << pizzas[i].get_m_cost() << " L " << pizzas[i].get_l_cost() << endl;
		string* ingreds = pizzas[i].get_ingred();
		for(int j=0; j<pizzas[i].get_num_ingred(); j++){
			cout << ingreds[j] << " ";
		}
		cout << endl << endl;
	}
}


/*********************************************************************
** Function: view hours
** Description: views hours of restauraunt
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: printed hours and days
*********************************************************************/ 
void Restauraunt::view_hours(){
	for(int i=0; i<num_open; i++){
		cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
	}
	cout << endl;
}


//Accessors
void Restauraunt::view_address() { cout << endl << address << endl << endl; }
void Restauraunt::view_phone() { cout << endl << phone << endl << endl; }


/*********************************************************************
** Function: search_menu_by_price
** Description: checks menu for price range of user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: refined menu returned
*********************************************************************/ 
void Restauraunt::search_menu_by_price(){
	int upper_bound;
	cout << "Enter upper bound ";
	upper_bound = get_real_num();
	int num_pizzas;
	num_pizzas = menu.get_num_pizza();
	menu = menu.search_pizza_by_cost(upper_bound, num_pizzas);
	order_off();
	cout << endl;
}


/*********************************************************************
** Function: fill_string
** Description: fills an array with ingredients
** Parameters: array, size array
** Pre-Conditions: none
** Post-Conditions: ingredients put in string
*********************************************************************/ 
void fill_string(string arr[], int size){
	string word;
	for(int i=0; i<size; i++){
		cout << "Enter ingredient: " << endl;
		get_string(word);
		arr[i] = word;
	}
}


/*********************************************************************
** Function: order_off
** Description: allows user to order off refined menu
** Parameters: none
** Pre-Conditions: some search was done
** Post-Conditions: ordered
*********************************************************************/ 
void Restauraunt::order_off(){
	int order = -1;
	string name_pizza;
	bool good = false;
	cout << "Order off this search? (1 for Yes, 2 for No) " << endl;
	cin >> order;
	if(order == 1){
		cout << "Which pizza do you want to order? (Enter number)" << endl;
		Pizza* list = menu.get_pizzas();
		for(int i=0; i<menu.get_num_pizza(); i++){
			cout << i << ": " << list[i].get_name() << endl; 
		}
		order = get_real_num();
		cout << "You selected: " << list[order].get_name();
		place_order(list, order);
	}
	if(order == 2){
		cout << "Resetting Menu" << endl;
		Pizza* bye = menu.get_pizzas();
		delete [] bye;
		menu.load_pizzas();
	}
}


/*********************************************************************
** Function: search_by_ingredients
** Description: user can search with include/exclude
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: refined menu returned
*********************************************************************/ 
void Restauraunt::search_by_ingredients(){
	int choice, num_ingredients, num_pizzas = menu.get_num_pizza();
	string* ingredients;
	cout << "Do you want to search by including (1) or excluding (2)?" << endl;
	cin >> choice;
	if(choice == 1){
		cout << "How many items do you want to include? " << endl;	
		cin >> num_ingredients;
		string ingredients[num_ingredients];
		fill_string(ingredients, num_ingredients);
		menu = menu.search_pizza_by_ingredients_to_include(ingredients, num_ingredients, num_pizzas);
	}
	else if(choice == 2){
		cout << "How many items do you want to exclude? " << endl;	
		cin >> num_ingredients;
		string ingredients[num_ingredients];
		fill_string(ingredients, num_ingredients);
		menu = menu.search_pizza_by_ingredients_to_exclude(ingredients, num_ingredients, num_pizzas);
		cout << "Finished " << endl;
	}
	order_off();
	cout << endl;
}


/*********************************************************************
** Function: replace_under, replace_add, replace_num
** Description: replaces user input and its spaces with underscores to go into files
** Parameters: some string
** Pre-Conditions: none
** Post-Conditions: spaces turned to underscores
*********************************************************************/ 
void replace_under(string &name){
	get_string(name);
	for(int i=0; i<name.length(); i++){
		if(name[i] == ' ')
			name[i] = '_';
	}
}

void replace_add(string &name){
	for(int i=0; i<name.length(); i++){
		if(name[i] == ' ')
			name[i] = '_';
	}
}

void replace_num(string &name){
	get_num(name);
	for(int i=0; i<name.length(); i++){
		if(name[i] == ' ')
			name[i] = '_';
	}
}


/*********************************************************************
** Function: write_order
** Description: writes out an order to file
** Parameters: ofstream &file, string name, string cc, string add, string phone, string pizza, string quan, string size, int orders
** Pre-Conditions: user entered details
** Post-Conditions: file written
*********************************************************************/ 
void write_order(ofstream &file, string name, string cc, string add, string phone, string pizza, string quan, string size, int orders){
	file << orders << " " << name << " " << cc << " " << add << " " << phone << " " << pizza << " " << size << " " << quan << '\n';
	file.close();
}


/*********************************************************************
** Function: choose_pizza
** Description: when ordering off not a search, places order
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: order placed, file written
*********************************************************************/ 
void Restauraunt::choose_pizza(){
	Pizza* list = menu.get_pizzas();
	view_menu();
	cout << "What pizza do you want? (Starting from 0) ";
	int choice = get_real_num();
	place_order(list, choice);
}


/*********************************************************************
** Function: place_order
** Description: places an order to file
** Parameters: pizza array, index of pizza
** Pre-Conditions: none
** Post-Conditions: order placed, file written
*********************************************************************/ 
void Restauraunt::place_order(Pizza* selection, int index){
	//everytime the program runs, add one to order number they you pulled.
	ofstream file;
	file.open("orders.txt", ios::app);
	num_orders = get_num_orders();
	string cust_name, cust_cc, cust_add, cust_phone, cust_pizza, cust_quan, size;
	cout << "Enter your name: " << endl;
	replace_under(cust_name);
	
	cout << "Enter CC number: " << endl;
	replace_num(cust_cc);
	
	cout << "Enter delivery address: " << endl;
	getline(cin, cust_add);
	replace_add(cust_add);
	
	cout << "Enter phone number: " << endl;
	replace_num(cust_phone);
	
	cust_pizza = selection[index].get_name();
	
	cout << "Enter size: " << endl;
	replace_under(size);

	cout << "Enter quantity of pizzas: " << endl;
	replace_num(cust_quan);
	num_orders++;
	write_order(file, cust_name, cust_cc, cust_add, cust_phone, cust_pizza, cust_quan, size, num_orders);

}


/*********************************************************************
** Function: return_day
** Description: returns index of day
** Parameters: string day
** Pre-Conditions: none 
** Post-Conditions: int returned
*********************************************************************/ 
int return_day(string day){
	if(day == "S")
		return 0;
	if(day == "M")
		return 1;
	if(day == "T")
		return 2;
	if(day == "W")
		return 3;
	if(day == "R")
		return 4;
	if(day == "F")
		return 5;
	if(day == "ST")
		return 6;
}


/*********************************************************************
** Function: change_hours
** Description: changes hours in restauraunt
** Parameters: none 
** Pre-Conditions: user is employee
** Post-Conditions: hours changed
*********************************************************************/ 
void Restauraunt::change_hours(){
	string day_choice, open, close;
	cout << "What day to change? (S, M, T, W, R, F, ST) ";
	get_string(day_choice);
	int day = return_day(day_choice);
	cout << "Enter new opening time: ";
	get_num(open);
	week[day].open_hour = open;
	cout << "Enter new closing time: ";
	get_num(close);
	week[day].close_hour = close;

	cout << week[day].day << week[day].open_hour << week[day].close_hour << endl;
	cout << endl;
}


/*********************************************************************
** Function: add_to_menu
** Description: new pizza is added
** Parameters: none
** Pre-Conditions: user is employee
** Post-Conditions: pizza added and written
*********************************************************************/ 
void Restauraunt::add_to_menu(){
	Pizza* temp = new Pizza[1];
	string pname;
	int scost, mcost, lcost, numing; 
	cout << "Enter Name of Pizza ";
	replace_under(pname);
	cout << "Enter Small Cost ";	
	scost = get_real_num();
	cout << "Enter Medium Cost ";
	mcost = get_real_num();
	cout << "Enter Large Cost ";
	lcost = get_real_num();
	cout << "Enter Number of Ingredients ";
	numing = get_real_num();;
	string* ingreds = new string[numing];
	for(int i=0; i<numing; i++){
		cout << "Enter Ingredient " << i << ": ";
		get_string(ingreds[i]);
	}
	temp[0].set(pname, scost, mcost, lcost, numing, ingreds);
	menu.add_to_menu(temp[0]);
	delete [] temp;
}


/*********************************************************************
** Function: get_index_remove
** Description: checks if number is too big
** Parameters: none
** Pre-Conditions: user is employee
** Post-Conditions: integer returned
*********************************************************************/ 
int get_index_remove(int num_pizzas){
	bool good = true;
	int choice = 0;
	while(good){
		choice = get_real_num();
		if(choice >= num_pizzas)
			cout << "Number too big/invalid" << endl;
		if(choice >= 0 && choice <= (num_pizzas-1))
			return choice;
	}
}


/*********************************************************************
** Function: remove_from_menu
** Description: removes pizzas from menu and file
** Parameters: none
** Pre-Conditions: user is employee
** Post-Conditions: pizza removed
*********************************************************************/ 
void Restauraunt::remove_from_menu(){
	string piza, goodbye;
	int tick = 0, choice = 0;
	char oldname[] = "menu.txt", tempname[] = "temp.txt", newname[] = "temp2.txt";
	ifstream menus;
	ofstream temp;
	menus.open("menu.txt");
	temp.open("temp.txt");

	view_menu(); 
	cout << "Which menu item do you want to remove? (Starting from 0) ";
	choice = get_index_remove(menu.get_num_pizza());

	while(!menus.eof()){
		if(choice-1 != tick){
			getline(menus, piza);
			temp << piza << '\n';
		}
		else{
			getline(menus, goodbye);
		}
		tick++;
	}
	
	menu.remove_from_menu(choice);
	//Rename files	
	rename(oldname, newname);
	rename(tempname, oldname);
	remove("temp2.txt");
}	


/*********************************************************************
** Function: view_orders
** Description: prints out orders
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Restauraunt::view_orders(){
	ifstream orders;
	string order;
	orders.open("orders.txt");
	while(!orders.eof()){
		getline(orders, order);
		cout << order << endl;
	}
	orders.close();
}


/*********************************************************************
** Function: remove_orders
** Description: removes orders from file
** Parameters: none
** Pre-Conditions: user is employee
** Post-Conditions: order removed
*********************************************************************/ 
void Restauraunt::remove_orders(){
	string choice, order;
	char oldname[] = "orders.txt";
	char tempname[] = "temp.txt";
	char newname[] = "temp2.txt";
	ifstream orders;
	ofstream temp;
	orders.open("orders.txt");
	temp.open("temp.txt");
	view_orders();
	cout << "Which order number do you want to remove? ";
	get_num(choice);

	while(!orders.eof()){
		getline(orders, order);
		if(order[0] != choice[0]){
			temp << order << '\n';
		}
	}
	
	//Rename files	
	rename(oldname, newname);
	rename(tempname, oldname);
	remove("temp2.txt");

	
}

//Destructor
Restauraunt::~Restauraunt(){
	delete [] employees;
	delete [] week;
}
