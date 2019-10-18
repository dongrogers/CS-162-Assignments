#include <iostream>
#include "rest.h"

using namespace std;

/*********************************************************************
** Function: employee_choices
** Description: Calls class functions
** Parameters: Restauraunt
** Pre-Conditions: User logged in
** Post-Conditions: Rest changed
*********************************************************************/ 
int employee_choices(Restauraunt &rest){
		//Redirect
		int choice = get_real_num();
		if(choice == 1)
			rest.change_hours();
		if(choice == 2)
			rest.view_orders();
		if(choice == 3)
			rest.remove_orders();
		if(choice == 4)
			rest.add_to_menu();
		if(choice == 5)
			rest.remove_from_menu();
		if(choice == 6)
			rest.view_menu();
		if(choice == 7)
			rest.view_hours();
		if(choice == 8)
			rest.view_address();
		if(choice == 9)
			rest.view_phone();
		if(choice == 10)
			return 10;
}
	

/*********************************************************************
** Function: employee_menu
** Description: Starts up employee with login
** Parameters: Restauraunt
** Pre-Conditions: Restauraunt crated
** Post-Conditions: Print, prompt
*********************************************************************/ 
void employee_menu(Restauraunt &rest){
	if(rest.login() == true){
	while(true){
		//Prints
		cout << "What would you like to do?" << endl;
		cout << endl;
		cout << "    1. Change hours" << endl;
		cout << "    2. View Orders " << endl;
		cout << "    3. Remove Order" << endl; 
		cout << "    4. Add Item to Menu" << endl;
		cout << "    5. Remove Item from Menu" << endl; 
		cout << "    6. View Menu" << endl;
		cout << "    7. View Hours" << endl; 
		cout << "    8. View Address" << endl;
		cout << "    9. View Phone " << endl; 
		cout << "    10. Log Out" << endl;
		cout << endl;
		int choice = employee_choices(rest);
		if(choice == 10)
			return;
	}
	}
	else
		return;
}


/*********************************************************************
** Function: Customer choices
** Description: Allows customer to use menu
** Parameters: Restauraunt
** Pre-Conditions: Customer enters numbers
** Post-Conditions: Rest changed
*********************************************************************/ 
int customer_choices(Restauraunt &rest){
		//Redirect
		int choice = get_real_num();
		if(choice == 1)
			rest.view_menu();
		if(choice == 2)
			rest.search_menu_by_price();
		if(choice == 3)
			rest.search_by_ingredients();
		if(choice == 4)
			rest.choose_pizza();
		if(choice == 5)
			rest.view_hours();
		if(choice == 6)
			rest.view_address();
		if(choice == 7)
			rest.view_phone();
		if(choice == 8)
			return 8;
}


/*********************************************************************
** Function: customer_menu
** Description: Prints out what customer can do
** Parameters: Restauraunt
** Pre-Conditions: User wants to be customer
** Post-Conditions: Printed, rest changed
*********************************************************************/ 	
void customer_menu(Restauraunt &rest){
	while(true){
		//Prints
		cout << "What would you like to do?" << endl;
		cout << endl;
		cout << "    1. View Menu" << endl;
		cout << "    2. Search by Cost " << endl;
		cout << "    3. Search by Ingredients " << endl; 
		cout << "    4. Place Order" << endl;
		cout << "    5. View Hours" << endl; 
		cout << "    6. View Address" << endl;
		cout << "    7. View Phone" << endl; 
		cout << "    8. Log Out" << endl;
		cout << endl;
		int choice = customer_choices(rest);
		if(choice == 8)
			return;
	}
}


/*********************************************************************
** Function: cust_or_emp
** Description: Checks if user wants to be customer or employee, or quit
** Parameters: Restauraunt
** Pre-Conditions: None
** Post-Conditions: Program runs
*********************************************************************/ 
void cust_or_emp(Restauraunt &rest){
	int choice = 0;
	cout << "Are you a customer or employee? (1 for Customer, 2 for Employee, 3 to Quit) ";
	choice = get_real_num();
	if(choice == 1)
		customer_menu(rest);
	if(choice == 2)
		employee_menu(rest);
	if(choice == 3)
		return;
	else
		return;

}


/*********************************************************************
** Function: main
** Description: runs program
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: restauraunt created
*********************************************************************/ 
int main(){
	Restauraunt rest;
	cust_or_emp(rest);
	
}
