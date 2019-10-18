#include "game.h"

bool operator>(const properties& lhs, const properties& rhs){
	int check = 0;
	if(lhs.get_num_ten() > rhs.get_num_ten()){
		cout << "Left has greater number of tenants." << endl;
		check++;
	}
	else
		cout << "Right has greater number of tenants." << endl;
	if(lhs.get_value() > rhs.get_value()){
		cout << "Left has greater value. " << endl;
		check++;
	}
	else
		cout << "Right has greater value. " << endl;
	if(check == 2)
		return true;
	else
		return false;
}

bool operator<(const properties& lhs, const properties& rhs){
	int check = 0;
	if(lhs.get_num_ten() > rhs.get_num_ten())
		cout << "Left has greater number of tenants." << endl;
	else{
		cout << "Right has greater number of tenants." << endl;
		check++;
	}
	if(lhs.get_value() > rhs.get_value())
		cout << "Left has greater value. " << endl;
	else{
		cout << "Right has greater value. " << endl;
		check++;
	}
	if(check == 2)
		return true;
	else
		return false;
}

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
		else{
			cout << "Bad Input" << endl;
		}
	}
	
}


/*********************************************************************
** Function: choice
** Description: redirects user to menu
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: function ran
*********************************************************************/ 
void Game::choice_redirect(int choice){
	if(choice == 1)
		buy_prop();
	if(choice == 2)
		sell_prop();
	if(choice == 3)
		adjust_rent();
}


/*********************************************************************
** Function: go events
** Description: runs events on all properties
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: events ran
*********************************************************************/ 
void Game::go_events(){
	int event = 0;	
	event = rand() % 6+1;
	if(num_house > 0)
		run_event(houses, 1, event);
	if(num_apt > 0)
		run_event(apts, 1, event);
	if(num_comp > 0)
		run_event(comps, 1, event);
}


/*********************************************************************
** Function: check gen
** Description: checks if list needs a repop
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: list repopped
*********************************************************************/ 
void Game::check_gen(){
	if(list.get_num_house() == 0){
		if(list.get_num_apt() == 0){
			if(list.get_num_comp() == 0){
				cout << "Repopulating" << endl;
				game_start();
			}
		}
	}
}


/*********************************************************************
** Function: print stuff
** Description: prints a menu 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void print_stuff(){
	cout << endl;
	cout << "    1. Buy Property" << endl;
	cout << "    2. Sell Property " << endl;
	cout << "    3. Adjust Rent" << endl; 
	cout << "    4. Continue Game" << endl;
	cout << "    5. Quit Game" << endl;
	cout << endl;
}


/*********************************************************************
** Function: initial turn
** Description: runs payments and debts
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: paid payments
*********************************************************************/ 
void Game::initial_turn(){
	cout << "--------------------------------" << endl;
	cout << "Turn: " << turn << endl;
	cout << "--------------------------------" << endl;
	collect_rent();
	pay_mortgage();
	print_balance();
	cout << "What would you like to do?" << endl;	
	if(turn == 12){
		turn = 0;
		pay_tax();
	}
}


/*********************************************************************
** Function: run menu
** Description: runs program until winner or quit
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Game::run_menu(){
	int choice = 0;
	while(true){
		initial_turn();
		print_stuff();	
		choice = get_num_bound(5, 1);
		choice_redirect(choice);
		if(choice == 5)
			return;	
		go_events();
		if(money >= 1000000){ 
			cout << "You win, lots money." << endl;
			return;
		}
		if(money <= 0){
			cout << "You lose, no money left." << endl;
			return;
		} 
		check_gen();
		turn++;
	}

}


/*********************************************************************
** Function: constructor
** Description: inits 0 values and begins game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Game::Game(){
	num_house = 0;
	num_apt = 0;
	num_comp = 0;
	turn = 0;
	money = 500000;
	//print_balance();
	game_start();
	cout << "Checking < " << endl;
	cout << ((list.get_house())[0] < (list.get_house())[1]) << endl;

	cout << "Checking > " << endl;
	cout << ((list.get_house())[0] > (list.get_house())[1]) << endl;
	//buy_prop();
	//run_menu();
}


/*********************************************************************
** Function: prints balance
** Description: prints balance
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: print balance
*********************************************************************/ 
void Game::print_balance(){
	cout << "--------------------------------" << endl;
	cout << "Your Balance is $" << money << endl;
	cout << "--------------------------------" << endl;
}


/*********************************************************************
** Function: game start
** Description: inits the array of props to buy
** Parameters: none
** Pre-Conditions: no gen array yet ** Post-Conditions: none
*********************************************************************/ 
void Game::game_start(){
	house* g_houses = new house[3];
	for(int i=0; i<3; i++)
		g_houses[i].start();
	apt* g_apts = new apt[3];
	for(int i=0; i<3; i++)
		g_apts[i].start();
	comp* g_comps = new comp[3];
	for(int i=0; i<3; i++)
		g_comps[i].start();

	list.set_house(g_houses);
	list.set_apt(g_apts);
	list.set_comp(g_comps);
	list.set_num_house(3);
	list.set_num_apt(3);
	list.set_num_comp(3);
}


/*********************************************************************
** Function: run event
** Description:  runs a random event
** Parameters: prop, num props, event type
** Pre-Conditions: none
** Post-Conditions: event ran
*********************************************************************/ 
void Game::run_event(properties* prop, int num_prop, int event){
	if(event == 1){
		cout << "Hurricane! Dropping SE properties by 50%" << endl;
		hurricane(prop, num_prop);
	}
	else if(event == 2){
		cout << "Tornado! Dropping Midwest properties by 30%" << endl;
		tornado(prop, num_prop);
	}
	else if(event == 3){
		cout << "Earthquake! Dropping Northwest properties by 10%" << endl;
		earthquake(prop, num_prop);
	}
	else if(event == 4){
		cout << "Wildfire! Dropping Southwest properties by 25%" << endl;
		fire(prop, num_prop);
	}
	else if(event == 5){
		cout << "Stock Crash! Dropping all properties by 30%" << endl;
		stock_crash(prop, num_prop);
	}
	else if(event == 6){
		cout << "Gentrification. Increasing all property values by 20%" << endl;
		gentrify(prop, num_prop);
	}
	cout << endl;

}


/*********************************************************************
** Function: hurricane
** Description: reduces prop value based on locale
** Parameters: property, size of property
** Pre-Conditions: none
** Post-Conditions: property value reduced
*********************************************************************/ 
void Game::hurricane(properties* prop, int size){
	int temp_value;
	int return_value;
	for(int i=0; i<size; i++){
		if(prop[i].get_locate() == "SE"){
			return_value = (temp_value*50/100);
			prop[i].set_value(return_value);
			cout << "New Value: " << prop[i].get_value() << endl;
		}
		cout << "done" << endl;
	}
		cout << "done" << endl;
}


/*********************************************************************
** Function:tornado
** Description: reduces prop value based on locale
** Parameters: property, size of property
** Pre-Conditions: none
** Post-Conditions: property value reduced
*********************************************************************/ 
void Game::tornado(properties* prop, int size){
	int temp_value;
	int return_value;
	for(int i=0; i<size; i++){
		if(prop[i].get_locate() == "Midwest"){
			temp_value = prop[i].get_value();
			cout << "Old Value: " << temp_value << endl;
			return_value = (temp_value*70/100);
			prop[i].set_value(return_value);
			cout << "New Value: " << prop[i].get_value() << endl;
		}
	}
}


/*********************************************************************
** Function:earthquake
** Description: reduces prop value based on locale
** Parameters: property, size of property
** Pre-Conditions: none
** Post-Conditions: property value reduced
*********************************************************************/ 
void Game::earthquake(properties* prop, int size){
	int temp_value;
	int return_value;
	for(int i=0; i<size; i++){
		if(prop[i].get_locate() == "Northwest"){
			temp_value = prop[i].get_value();
			cout << "Old Value: " << temp_value << endl;
			return_value = (temp_value*90/100);
			prop[i].set_value(return_value);
			cout << "New Value: " << prop[i].get_value() << endl;
		}
	}
}



/*********************************************************************
** Function:fire
** Description: reduces prop value based on locale
** Parameters: property, size of property
** Pre-Conditions: none
** Post-Conditions: property value reduced
*********************************************************************/ 
void Game::fire(properties* prop, int size){
	int temp_value;
	int return_value;
	for(int i=0; i<size; i++){
		if(prop[i].get_locate() == "Southwest"){
			temp_value = prop[i].get_value();
			cout << "Old Value: " << temp_value << endl;
			return_value = (temp_value*75/100);
			prop[i].set_value(return_value);
			cout << "New Value: " << prop[i].get_value() << endl;
		}		
	}
}



/*********************************************************************
** Function:stock_crash
** Description: reduces prop value based on locale
** Parameters: property, size of property
** Pre-Conditions: none
** Post-Conditions: property value reduced
*********************************************************************/ 
void Game::stock_crash(properties* prop, int size){
	int temp_value;
	int return_value;
	for(int i=0; i<size; i++){
		temp_value = prop[i].get_value();
		cout << "Old Value: " << temp_value << endl;
		return_value = (temp_value*0.7);
		prop[i].set_value(return_value);
		cout << "New Value: " << prop[i].get_value() << endl;
	}
}


/*********************************************************************
** Function: random
** Description: returns random string
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: random string
*********************************************************************/ 
string rando_location(){
	int value = rand() % 5 + 1;
	if(value == 1)
		return "SE";
	if(value == 2)
		return "NE";
	if(value == 3)
		return "Midwest";
	if(value == 4)
		return "SW";
	if(value == 5)
		return "NW";
}


/*********************************************************************
** Function: gentrify
** Description: reduces prop value based on locale
** Parameters: property, size of property
** Pre-Conditions: none
** Post-Conditions: property value reduced
*********************************************************************/ 
void Game::gentrify(properties* prop, int size){
	int temp_value;
	int return_value;
	string location = rando_location();
	for(int i=0; i<size; i++){
		if(prop[i].get_locate() == location){
			temp_value = prop[i].get_value();
			cout << "Old Value: " << temp_value << endl;
			return_value = (temp_value*120/100);
			prop[i].set_value(return_value);
			cout << "New Value: " << prop[i].get_value() << endl;
		}
	}
}


/*********************************************************************
** Function: pay
** Description: pays debts
** Parameters: none
** Pre-Conditions: 12 turns
** Post-Conditions: paid
*********************************************************************/ 
void Game::pay_tax(){
	int total = 0;
	int temp = 0;	
	for(int i=0; i<num_house; i++){
		temp = houses[i].get_value();
		total += (temp*1.5/100);
	}
	for(int i=0; i<num_apt; i++){
		temp = apts[i].get_value();
		total += (temp*1.5/100);
	}
	for(int i=0; i<num_comp; i++){
		temp = comps[i].get_value();
		cout << temp << endl;
		total += (temp*1.5/100);
	}
	cout << "Paying Yearly Tax of $" << total << endl;
	money -= total;
}


/*********************************************************************
** Function: business increase
** Description: increase business value 
** Parameters: none
** Pre-Conditions: each turn
** Post-Conditions: increase value
*********************************************************************/ 
void Game::business_increase(){
	int temp = 0;
	int inc = 0;
	for(int i=0; i<num_comp; i++){
		temp = comps[i].get_value();
		inc = temp*1/100;
		temp += inc;
		comps[i].set_value(temp);
		cout << "Increasing value of Business " << i << " by " << inc << endl;
	}
}


/*********************************************************************
** Function: pay mortgage
** Description: pays debts
** Parameters: none
** Pre-Conditions: 12 turns
** Post-Conditions: paid
*********************************************************************/ 
void Game::pay_mortgage(){
	int total = 0;
	int temp_month = 0;
	for(int i=0; i<num_house; i++){
		temp_month = houses[i].get_mortgage_duration();
		houses[i].set_mortgage_duration(temp_month-1);
		total += houses[i].get_mortgage();
	}
	for(int i=0; i<num_apt; i++){
		temp_month = apts[i].get_mortgage_duration();
		apts[i].set_mortgage_duration(temp_month-1);
		total += apts[i].get_mortgage();
	}
	for(int i=0; i<num_comp; i++){
		temp_month = comps[i].get_mortgage_duration();
		comps[i].set_mortgage_duration(temp_month-1);
		total += comps[i].get_mortgage();
		
	}
	cout << "Paying Mortgage of $" << total << endl;
	money -= total;
	business_increase();
}


/*********************************************************************
** Function: get num bound
** Description: returns num based on bounds
** Parameters: upper and lower bound
** Pre-Conditions: none
** Post-Conditions: returns num
*********************************************************************/ 
int Game::get_num_bound(int upper, int lower){
	int num;
	while(true){
		num = get_real_num();
		if(num > upper || num < lower)
			cout << "Too big/small" << endl;
		else
			break;
	}
	return num;
}


/*********************************************************************
** Function: print prop
** Description: prints out property
** Parameters: prop type of 1 2 or 3
** Pre-Conditions: none
** Post-Conditions: printed props
*********************************************************************/ 
int Game::print_props(int prop_type){
	int index = 0;
	if(prop_type == 1){
	for(int i=0; i<num_house; i++){
			cout << endl;
			cout << "House " << i << ": "  << endl;
			houses[i].print();
			cout << endl;
	}
	index = get_num_bound(num_house-1, 0);
	}
	if(prop_type == 2){
	for(int i=0; i<num_apt; i++){
			cout << endl;
			cout << "Apartment " << i << ": "  << endl;
			apts[i].print();
			cout << endl;
	}
	index = get_num_bound(num_comp-1, 0);
	}
	if(prop_type == 3){
	for(int i=0; i<num_comp; i++){
			cout << endl;
			cout << "Business " << i << ": "  << endl;
			comps[i].print();
			cout << endl;
	}
	index = get_num_bound(num_comp-1, 0);
	}
	return index;
}


/*********************************************************************
** Function: adjust rent
** Description: allows user to change rent
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: rent changed
*********************************************************************/ 
void Game::adjust_rent(){
	//Index will be on which prop of that prop typasde
	int rent;
	cout << "Which property do you want to adjust? " << endl;
	int prop_type = get_inrange();
	int index = print_props(prop_type);
	if(prop_type == 1){
		cout << "What should rent be on this house? (500-5000)" << endl;
		cout << "Tenant's Budget: " << houses[index].get_budget() << endl;
		rent = get_num_bound(5000, 500);
		houses[index].set_rent(rent);
	}
	if(prop_type == 2){
		cout << "What should rent be on this apartment building? (500-5000)" << endl;
		rent = get_num_bound(5000,500);
		apts[index].set_rent(rent);
	}
	if(prop_type == 3){
		tenant* tens = comps[index].get_ten();
		for(int i=0; i<comps[index].get_num_spaces(); i++){
			cout << "What should rent be on room " << i << "? (2000-10000)" << endl;
			cout << endl;
			cout << "Tenant's Budget: " << tens[i].get_budget() << endl;
			rent = get_num_bound(10000,2000);
			comps[index].set_rent(rent, i);
		}
	}
}


/*********************************************************************
** Function: rent
** Description: pays rent according to property type
** Parameters: none
** Pre-Conditions: turn
** Post-Conditions: rent paid
*********************************************************************/ 
void Game::house_rent(){
	int temp = 0;
	for(int i=0; i<num_house; i++){
		if(houses[i].get_num_ten() == 0){
			cout << "No tenants left at House " << i+1 << endl;
		}
		else{
			tenant* ten = houses[i].get_ten();
			cout << endl;
			if(houses[i].get_rent() > houses[i].get_budget()){
				cout << "Rent is too high for House " << i << endl;
				if(houses[i].get_ten_score() > 2){
					cout << "Tenant has score of " << houses[i].get_ten_score() << " and has left." << endl;
					houses[i].set_num_tens(0);
					tenant* ten = houses[i].get_ten();
					ten[0].set_budget(0);
				}
				else
					cout << "Tenant has score of " << ten[i].get_score() << " and will stay, but not pay rent. " << endl;				
				cout << "--------------------------------" << endl;
			}	
			else{
				money += houses[i].get_rent();
				cout << "--------------------------------" << endl;
				cout << "Collected $" << houses[i].get_rent() << " from House " << i+1 << endl; 
			}
		}
	}	
}


/*********************************************************************
** Function: rent
** Description: pays rent according to property type
** Parameters: none
** Pre-Conditions: turn
** Post-Conditions: rent paid
*********************************************************************/ 
void Game::apt_rent(){
	int temp = 0;
	for(int i=0; i<num_apt; i++){
		if(apts[i].get_num_ten() == 0){
			cout << "No tenants left at Apartment " << i+1 << endl;
		}
		else{
			tenant* ten = apts[i].get_ten();
			cout << endl;
			for(int j=0; j<apts[i].get_rooms(); j++){
				if(apts[i].get_rent() > ten[j].get_budget()){
					if(ten[j].get_budget() != 0);
						cout << "Rent is too high for Apartment " << i+1 << " and room " << j <<  endl;
					if(ten[j].get_score() > 2){
						cout << "Tenant has score of " << ten[j].get_score() << " and has left." << endl;
						temp = apts[i].get_num_ten();
						apts[i].set_num_tens(temp-1);
						ten[j].set_budget(0);
					}
					else
						cout << "Tenant " << j << " has score of " << ten[j].get_score() << " and will stay, but not pay rent. " << endl;				
				cout << "--------------------------------" << endl;
			}
				else{
					money += apts[i].get_rent();
					cout << "--------------------------------" << endl;
					cout << "Collected $" << apts[i].get_rent() << " from Apartment " << i+1 << " and room " << j << endl; 
				}
			}
			cout << endl;
		}
	}	
}


/*********************************************************************
** Function: rent
** Description: pays rent according to property type
** Parameters: none
** Pre-Conditions: turn
** Post-Conditions: rent paid
*********************************************************************/ 
void Game::comp_rent(){
	int temp = 0;
	for(int i=0; i<num_comp; i++){
		if(comps[i].get_num_ten() == 0){
			cout << "No tenants left at Business " << i+1 << endl;
			cout << comps[i].get_num_ten() << endl;

		}
		else{
			tenant* ten = comps[i].get_ten();
			space* spa = comps[i].get_spaces();
			cout << endl;
			for(int j=0; j<comps[i].get_num_spaces(); j++){
				if(spa[j].get_rent() > ten[j].get_budget()){
					cout << "Rent is too high for Business " << i+1 << " and space " << j <<  endl;
					if(ten[j].get_score() > 2){
						cout << "Tenant has score of " << ten[j].get_score() << " and has left." << endl;
						temp = comps[i].get_num_ten();
						comps[i].set_num_tens(temp-1);
						spa[j].set_rent(0);
					}
					else
						cout << "Tenant has score of " << ten[j].get_score() << " and will stay, but not pay rent. " << endl;
					cout << "--------------------------------" << endl;
				}
				else{
					money += spa[i].get_rent();
					cout << "--------------------------------" << endl;
					cout << "Collected $" << spa[i].get_rent() << " from Business " << i+1 << " and room " << j << endl; 
				}
			}
			cout << endl;
		}
	}	
}


/*********************************************************************
** Function: collect rent
** Description: pays rent according to all property type
** Parameters: none
** Pre-Conditions: turn
** Post-Conditions: rent paid
*********************************************************************/ 
void Game::collect_rent(){
	cout << "--------------------------------" << endl;
	cout << "Collecting Rent" << endl;
	cout << "--------------------------------" << endl;
	house_rent();
	apt_rent();
	comp_rent();
		
	cout << "--------------------------------" << endl;
	cout << "Rent Collected" << endl;
	cout << "--------------------------------" << endl;
}


/*********************************************************************
** Function: view purchase
** Description: prints purchaseable props
** Parameters: index of random props
** Pre-Conditions: none
** Post-Conditions: printed out purchases
*********************************************************************/ 
int Game::view_purchase(int index, int indexapt, int indexcomp){
	house* temp_houses = list.get_house();
	apt* temp_apts = list.get_apt();
	comp* temp_comps = list.get_comp();
	int prop_type;

	cout << "What property do you want to buy? Enter a number" << endl;
	if(list.get_num_house() > 0){
	cout << "1. House" << endl;
	temp_houses[index].print();
	cout << endl;
	}

	if(list.get_num_apt() > 0){
	cout << "2. Apartment" << endl;
	temp_apts[indexapt].print();
	cout << endl;
	}

	if(list.get_num_comp() > 0){
	cout << "3. Business Complex" << endl;
	temp_comps[indexcomp].print();
	cout << endl;
	}

	while(true){	
		prop_type = get_num_bound(3, 1);
		if((prop_type == 1) && (list.get_num_house() > 0) && (temp_houses[index].get_value() > money))
			cout << "Not enough money." << endl;
		else if((prop_type == 2) && (list.get_num_apt() > 0) && (temp_apts[indexapt].get_value() > money))
			cout << "Not enough money." << endl;	
		else if((prop_type == 3) && (list.get_num_comp() > 0) && (temp_comps[indexcomp].get_value() > money))
			cout << "Not enough money." << endl;
		else
			break;

	}
	return prop_type;
}


/*********************************************************************
** Function: get in range
** Description: prints purchaseable props
** Parameters: index of random props
** Pre-Conditions: none
** Post-Conditions: return index
*********************************************************************/ 
int Game::get_inrange(){
	int prop_type;
	cout << "1 for House, 2 for Apartment, 3 for Business." << endl;
	while(true){	
		prop_type = get_real_num();
		if(prop_type > 3 || prop_type < 1){
			cout << "You do not have any or invalid number" << endl;
		}
		else if((prop_type == 1) && (num_house == 0)){
			cout << "You don't have houses" << endl;
		}
		else if((prop_type == 2) && (num_apt == 0)){
			cout << "You don't have apartments" << endl;
		}
		else if((prop_type == 3) && (num_comp == 0)){
			cout << "You don't have businesses" << endl;
		}
		else
			break;
	}
	return prop_type;
}


/*********************************************************************
** Function: get rand
** Description: returns rand based on upper and lower
** Parameters: upper lower int
** Pre-Conditions: none
** Post-Conditions: return rand
*********************************************************************/ 
int get_rand(int upper, int lower){
	if(upper-lower != 0){
		int num = rand() % (upper-lower) + lower;
		return num;
	}
	else
		return 0;
}


/*********************************************************************
** Function: set rent
** Description: set rent after each purchase
** Parameters: none
** Pre-Conditions: prop purchased
** Post-Conditions: rent set
*********************************************************************/ 
void Game::set_rent(int prop_type, int index){
	//Index will be on which prop of that prop typasde
	int rent;
	if(prop_type == 1){
		cout << "What should rent be on this house? (500-5000)" << endl;
		cout << "Tenant's Budget: " << houses[index].get_budget() << endl;
		rent = get_num_bound(5000, 500);
		houses[index].set_rent(rent);
	}
	if(prop_type == 2){
		cout << "What should rent be on this apartment building? (500-5000)" << endl;
		rent = get_num_bound(5000,500);
		apts[index].set_rent(rent);
	}
	if(prop_type == 3){
		tenant* tens = comps[index].get_ten();
		for(int i=0; i<comps[index].get_num_spaces(); i++){
			cout << "What should rent be on room " << i << "? (2000-10000)" << endl;
			cout << endl;
			cout << "Tenant's Budget: " << tens[i].get_budget() << endl;
			rent = get_num_bound(10000,2000);
			comps[index].set_rent(rent, i);
		}
	}
}


/*********************************************************************
** Function: buy prop
** Description: buys a property 
** Parameters: none
** Pre-Conditions: money is greater than val
** Post-Conditions: prop bought and assigned
*********************************************************************/ 
void Game::buy_prop(){
	//Rand will change based on num house avail
	int indexhouse = get_rand(list.get_num_house(), 0);
	int indexapt = get_rand(list.get_num_apt(), 0);
	int indexcomp = get_rand(list.get_num_comp(), 0);
	int prop_type = view_purchase(indexhouse, indexapt, indexcomp);
	
	if((prop_type == 1) && (list.get_num_house() > 0)){
		buy_house(prop_type, indexhouse);
		return;
	}
	else if((prop_type == 2) && (list.get_num_apt() > 0)){
		buy_apt(prop_type, indexapt);	
		return;
	}
	else if((prop_type == 3) && (list.get_num_comp() > 0)){
		buy_comp(prop_type, indexcomp);
		return;
	}
	else{
		cout << "--------------------------------" << endl;
		cout << "Can not 3buy that." << endl;
		cout << "--------------------------------" << endl;
		prop_type = view_purchase(indexhouse, indexapt, indexcomp);
	}
}


/*********************************************************************
** Function: buy prop
** Description: buys a property 
** Parameters: none
** Pre-Conditions: money is greater than val
** Post-Conditions: prop bought and assigned
*********************************************************************/ 
void Game::buy_house(int prop_type, int index){
	//Retrieve from Buildings
	house* temp_house = list.get_house();
	int gsize = list.get_num_house();
	
	//Print
	cout << "--------------------------------" << endl;
	cout << "--------------------------------" << endl;
	cout << "Deducting $" << temp_house[index].get_value() << " from account." << endl;
	money -= temp_house[index].get_value();
	print_balance();
	cout << "--------------------------------" << endl;

	//Add to players
	grow_house_array(&temp_house, index);
	houses[num_house-1] = (list.get_house())[index];
	shrink_house_array(&temp_house, gsize, index);
	//Give rent
	set_rent(prop_type, num_house-1);

	//Resize generated
	list.set_house(temp_house);
	list.set_num_house(gsize-1);
}


/*********************************************************************
** Function: buy prop
** Description: buys a property 
** Parameters: none
** Pre-Conditions: money is greater than val
** Post-Conditions: prop bought and assigned
*********************************************************************/ 
void Game::buy_apt(int prop_type, int index){
	//Retrieve from Buildings
	apt* temp_apts = list.get_apt();
	int gsize = list.get_num_apt();
	
	//Print
	cout << "--------------------------------" << endl;
	cout << "--------------------------------" << endl;
	cout << "Deducting $" << temp_apts[index].get_value() << " from account." << endl;
	money -= temp_apts[index].get_value();
	print_balance();
	cout << "--------------------------------" << endl;

	//Add to players
	grow_apt_array(&temp_apts, index);
	apts[num_apt-1] = (list.get_apt())[index];
	shrink_apt_array(&temp_apts, gsize, index);
	//Give rent
	set_rent(prop_type, num_apt-1);

	//Resize generated
	list.set_apt(temp_apts);
	list.set_num_apt(gsize-1);
}


/*********************************************************************
** Function: buy prop
** Description: buys a property 
** Parameters: none
** Pre-Conditions: money is greater than val
** Post-Conditions: prop bought and assigned
*********************************************************************/ 
void Game::buy_comp(int prop_type, int index){
	//Retrieve from Buildings
	comp* temp_comps = list.get_comp();
	int gsize = list.get_num_comp();
	
	//Print
	cout << "--------------------------------" << endl;
	cout << "--------------------------------" << endl;
	cout << "Deducting $" << temp_comps[index].get_value() << " from account." << endl;
	money -= temp_comps[index].get_value();
	print_balance();
	cout << "--------------------------------" << endl;

	//Add to players
	grow_comp_array(&temp_comps, index);
	comps[num_comp-1] = (list.get_comp())[index];
	shrink_comp_array(&temp_comps, gsize, index);
	//Give rent
	set_rent(prop_type, num_comp-1);

	//Resize generated
	list.set_comp(temp_comps);
	list.set_num_comp(gsize-1);

}


/*********************************************************************
** Function: sell prop
** Description: sells prop if no tenants are inside
** Parameters: none
** Pre-Conditions: no tenants inside, prop owned
** Post-Conditions: prop sold for money
*********************************************************************/ 
void Game::sell_prop(){
	//Get the index at which prop they want to sell
	cout << "What property type do you want to sell? Enter a number" << endl;
	int prop_type = get_inrange();
	if(prop_type == 1){
		sell_house();
	}
	if(prop_type == 2){
		sell_apt();
	}
	if(prop_type == 3){
		sell_comp();
	}
}


/*********************************************************************
** Function: sell prop
** Description: sells prop if no tenants are inside
** Parameters: none
** Pre-Conditions: no tenants inside, prop owned
** Post-Conditions: prop sold for money
*********************************************************************/ 
void Game::sell_house(){
	//Still need to add the randomize money sell value
	for(int i=0; i<num_house; i++){
			cout << endl;
			cout << "House " << i << ": "  << endl;
			houses[i].print();
			cout << endl;
	}
	cout << "Which house do you want to sell? Enter a number" << endl;
	int house_type = get_num_bound(num_house-1, 0);
	if(houses[house_type].get_num_ten() > 0){
		cout << endl;
		cout << "Cannot sell, Tenants are still inside" << endl;
		cout << endl;
	}
	else if(num_house == 1){
		num_house = 0;
		cout << "--------------------------------" << endl;
		cout << "Sold House for $" << houses[house_type].get_value() << endl;
		money += houses[house_type].get_value();
		print_balance();
		delete [] houses;
	}
	else{
		houses[house_type].print();
		shrink_house_array(&houses, num_house, house_type);
		num_house -= 1;
		cout << "Sold" << endl;
	}
}


/*********************************************************************
** Function: sell prop
** Description: sells prop if no tenants are inside
** Parameters: none
** Pre-Conditions: no tenants inside, prop owned
** Post-Conditions: prop sold for money
*********************************************************************/ 
void Game::sell_apt(){
	//Still need to add the randomize money sell value
	for(int i=0; i<num_apt; i++){
			cout << endl;
			cout << "Apt " << i << ": "  << endl;
			apts[i].print();
			cout << endl;
	}
	cout << "Which apartment do you want to sell? Enter a number" << endl;
	int apt_type = get_num_bound(num_apt-1, 0);
	if(apts[apt_type].get_num_ten() > 0){
		cout << endl;
		cout << "Cannot sell, Tenants are still inside" << endl;
		cout << endl;
	}
	else if(num_apt == 1){
		num_apt = 0;
		cout << "--------------------------------" << endl;
		cout << "Sold Apartment for $" << apts[apt_type].get_value() << endl;
		money += apts[apt_type].get_value();
		print_balance();
		delete [] apts;

	}
	else{
		apts[apt_type].print();
		shrink_apt_array(&apts, num_apt, apt_type);
		num_apt -= 1;
	}
}


/*********************************************************************
** Function: sell prop
** Description: sells prop if no tenants are inside
** Parameters: none
** Pre-Conditions: no tenants inside, prop owned
** Post-Conditions: prop sold for money
*********************************************************************/ 
void Game::sell_comp(){
	//Still need to add the randomize money sell value
	for(int i=0; i<num_comp; i++){
			cout << endl;
			cout << "Business " << i << ": "  << endl;
			comps[i].print();
			cout << endl;
	}
	cout << "Which business do you want to sell? Enter a number" << endl;
	int comp_type = get_num_bound(num_comp-1, 0);
	if(comps[comp_type].get_num_ten() > 0){
		cout << endl;
		cout << "Cannot sell, Tenants are still inside" << endl;
		cout << endl;
	}
	else if(num_comp == 1){
		num_comp = 0;
		cout << "--------------------------------" << endl;
		cout << "Sold Business for $" << comps[comp_type].get_value() << endl;
		money += comps[comp_type].get_value();
		print_balance();
		delete [] comps;

	}

	else{
		comps[comp_type].print();
		shrink_comp_array(&comps, num_comp, comp_type);
		num_comp -= 1;
		cout << "Sold" << endl;
	}
}


/*********************************************************************
** Function: shrink array
** Description: makes array smaller and leaves out a bought property 
** Parameters: memory of prop, size of array, which index to leave out
** Pre-Conditions: property bought
** Post-Conditions: array shrunk
*********************************************************************/ 
void Game::shrink_house_array(house** old_house, int size, int exclude){
	house* temp = new house[size-1];
	int tick = 0;
	for(int i=0; i<size; i++){
		if(i != exclude){
			temp[tick] = (*old_house)[i];
			tick++;
		}
	}
	delete [] (*old_house);
	(*old_house) = temp;
	int gnum = list.get_num_house();
	//decrease number of generated houses here	
}


/*********************************************************************
** Function: shrink array
** Description: makes array smaller and leaves out a bought property 
** Parameters: memory of prop, size of array, which index to leave out
** Pre-Conditions: property bought
** Post-Conditions: array shrunk
*********************************************************************/ 
void Game::shrink_apt_array(apt** old_apt, int size, int exclude){
	apt* temp = new apt[size-1];
	int tick = 0;
	for(int i=0; i<size; i++){
		if(i != exclude){
			temp[tick] = (*old_apt)[i];
			tick++;
		}
	}
	delete [] (*old_apt);
	(*old_apt) = temp;
	int gnum = list.get_num_apt();
	//decrease number of generated houses here	
}


/*********************************************************************
** Function: shrink array
** Description: makes array smaller and leaves out a bought property 
** Parameters: memory of prop, size of array, which index to leave out
** Pre-Conditions: property bought
** Post-Conditions: array shrunk
*********************************************************************/ 
void Game::shrink_comp_array(comp** old_comp, int size, int exclude){
	comp* temp = new comp[size-1];
	int tick = 0;
	for(int i=0; i<size; i++){
		if(i != exclude){
			temp[tick] = (*old_comp)[i];
			tick++;
		}
	}
	delete [] (*old_comp);
	(*old_comp) = temp;
	int gnum = list.get_num_comp();
	//decrease number of generated houses here	
}


/*********************************************************************
** Function: grow array
** Description: makes property array larger by 1
** Parameters: memory of array, index of array
** Pre-Conditions: property bought
** Post-Conditions: array grown
*********************************************************************/ 
void Game::grow_house_array(house** old_house, int index){
	house* temp = new house[num_house+1];
	for(int i=0; i<num_house; i++){
		temp[i] = houses[i];
	}
	if(num_house != 0)
		delete [] houses;
	houses = temp;
	num_house++;
}


/*********************************************************************
** Function: grow array
** Description: makes property array larger by 1
** Parameters: memory of array, index of array
** Pre-Conditions: property bought
** Post-Conditions: array grown
*********************************************************************/ 
void Game::grow_apt_array(apt** old_apt, int index){
	apt* temp = new apt[num_apt+1];
	for(int i=0; i<num_apt; i++){
		temp[i] = apts[i];
	}
	if(num_apt != 0)
		delete [] apts;
	apts = temp;
	num_apt++;
}	


/*********************************************************************
** Function: grow array
** Description: makes property array larger by 1
** Parameters: memory of array, index of array
** Pre-Conditions: property bought
** Post-Conditions: array grown
*********************************************************************/ 
void Game::grow_comp_array(comp** old_comp, int index){
	comp* temp = new comp[num_comp+1];
	for(int i=0; i<num_comp; i++){
		temp[i] = comps[i];
	}
	if(num_comp != 0)
		delete [] comps;
	comps = temp;
	num_comp++;
}	


/*********************************************************************
** Function: deconstructor
** Description: deletes all properties if owned
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: memory freed
*********************************************************************/ 
Game::~Game(){
	if(num_house > 0)
		delete [] houses;
	if(num_apt > 0)
		delete [] apts;
	if(num_comp > 0)
		delete [] comps;
}
