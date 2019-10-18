/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

//#include <iostream>
//#include <cstring>
#include "book.h"

using namespace std;

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
bool is_valid_arguments(char** argv, int argc){
	if(argv[1][0] == '-' && argv[1][1] == 's'){
		for(int i=0; i<strlen(argv[2]); i++){
			if(argv[2][0] <= char('0') && argv[2][0] >= char('9')){
				cout << "Non integer entered for command line." << endl;
				return false;
			}
		}
			if(argv[3][0] == '-' && argv[3][1] == 'f'){
				return true;
			}
			else{
				cout << "Third argument should be -f" << endl;
			}
	}
	else{
		cout << "First argument should be -s" << endl;
	}
	return false;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
string* create_cities(int num){
	string* cities = new string[num];
	return cities;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
state* create_states(int num){
	state* states = new state[num];
	return states;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void get_county_data(county* counties, int num_counties, ifstream &file){
	for(int i=0; i<num_counties; i++){
		file >> counties[i].name >> counties[i].population >> counties[i].avg_income >> counties[i].avg_house >> counties[i].cities;
		int num_cities = counties[i].cities;
		counties[i].city = create_cities(num_cities);
		for(int j=0; j<num_cities; j++){
			file >> counties[i].city[j];
		}
	
	}
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void get_state_data(state* states, int num_states, ifstream &file){
	for(int i=0; i<num_states; i++){
		file >> states[i].name >> states[i].population >> states[i].counties;
		int num_counties = states[i].counties;
		states[i].c = create_counties(num_counties);
		//Fill county
		get_county_data(states[i].c, num_counties, file);
	}

}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
county* create_counties(int num){
	county* counties = new county[num];
	return counties;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void swap_array(string* name1, string* name2){
	string temp = *name1;
	*name1 = *name2;
	*name2 = temp;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void swap_intarray(int* name1, int* name2){
	int temp = *name1;
	*name1 = *name2;
	*name2 = temp;
}

void bubble_sort_name(string arr[], int size){
	for(int i=0; i< (size-1); i++){
		for(int j=0; j<(size-i-1); j++){
			if(arr[j] > arr[j+1]){
				swap_array(&arr[j], &arr[j+1]);
			}
		}
	}
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void bubble_sort(string arr[], int num[], int size){
	for(int i=0; i< (size-1); i++){
		for(int j=0; j<(size-i-1); j++){
			if(num[j] < num[j+1]){
				swap_array(&arr[j], &arr[j+1]);
				swap_intarray(&num[j], &num[j+1]);
			}
		}
	}
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void sort_names(state* states, int num_states, string names[]){
	//Place into array
	for(int i=0; i<num_states; i++){
		names[i] = states[i].name;
	}
	//Bubble Sort
	bubble_sort_name(names, num_states);
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void sort_population(state* states, int num_states, string statenames[], int pop[]){
	//Place into array
	for(int i=0; i<num_states; i++){
		statenames[i] = states[i].name;
		pop[i] = (states[i].population);	
	}
	//Bubble Sort
	bubble_sort(statenames, pop, num_states);
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int total_county_amount(state* states, int num_states){
	int county = 0;
	for(int i=0; i<num_states; i++){
		county += states[i].counties;
	}
	return county;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int county_amount(state* states, int state){
	int county = 0;
	county = states[state].counties;
	return county;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void sort_county_population(state* states, int num_states, string countynames[], int pop[]){
	int totalcounty = total_county_amount(states, num_states), where = 0;
	//Place into array
	for(int i=0; i<num_states; i++){
		int county = county_amount(states, i);
		for(int j=0; j<county; j++){
			countynames[j+where] = states[i].c[j].name;
			pop[j+where] = (states[i].c[j].population);
		}
		where += county;	
	}
	//Bubble Sort
	bubble_sort(countynames, pop, totalcounty);
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void sort_county_names(state* states, int num_states, string names[]){
	int totalcounties = total_county_amount(states, num_states), where = 0;
	//Place into array
	for(int i=0; i<num_states; i++){
		int county = county_amount(states, i);
		for(int j=0; j<county; j++){
			names[j+where] = states[i].c[j].name;
		}
		where += county;
	}
	//Bubble Sort
	bubble_sort_name(names, totalcounties);
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int income_check(state* states, int num_states, string arr[]){
	float income = 0;
	cout << "Enter an income to check counties an amount: " << endl; 
	cin >> income;
	
	for(int i=0; i<num_states; i++){
		for(int j=0; j<states[i].counties; j++){
			if(states[i].c[j].avg_income > income)
				arr[i] = states[i].c[j].name;
		}
	}
	cin.ignore();
	cin.clear();
	cout << endl;
	return income;

}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void largest_pop(state* states, int num_states, string arr[]){
	int check = 0;
	for(int i=0; i<num_states; i++){
		if(states[i].population > check){
			check = states[i].population;
			arr[0] = states[i].name;
		}
	}
	check = 0;
	for(int i=0; i<num_states; i++){
		for(int j=0; j<states[i].counties; j++){
			if(states[i].c[j].population > check){
				check = states[i].c[j].population;
				arr[1] = states[i].c[j].name;
			}
		}
	}
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int file_or_print(){
	int decision = 0;
	cout << "Enter 1 to print information to screen" << endl;
	cout << "Enter 2 to print information to file" << endl;
	while(true){
		cin >> decision;
		if(decision == 1 || decision == 2){
			cin.ignore();
			cin.clear();
			return decision; 
		}
	}
	return decision;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void print_screen(state* states, int num_states, string pop_names[], string c_pop_names[], string sorted_state[], string sorted_county[], string population[], string income[], int inc){
	for(int i=0; i<num_states; i++){
		cout << states[i].name << " " << states[i].population << " " << states[i].counties << "\n";
		for(int j=0; j<states[i].counties; j++){
			cout << states[i].c[j].name << " " << states[i].c[j].population << " " << states[i].c[j].avg_income << " " << states[i].c[j].avg_house << " " << states[i].c[j].cities << " "; 
			for(int k=0; k<states[i].c[j].cities; k++){
				cout << states[i].c[j].city[k] << " " ;
			}
			cout << "\n";
		}
		cout << "\n";
	}

	int county_num = total_county_amount(states, num_states);
	cout << "Largest State Population: " << population[0] << "\n";
	cout << "Largest County Population: " << population[1] << "\n";

	cout << "Counties with income over " << inc << "\n";
	for(int i=0; i<county_num; i++){
		cout << income[i] << " "; 
	}

	cout << "\n";
	cout << "\n";
	cout << "Average household costs for each county" << "\n";
	for(int i=0; i<num_states; i++){
		for(int j=0; j<states[i].counties; j++){
			cout << states[i].c[j].name << " average household cost is " << states[i].c[j].avg_house << endl;
		}
	}

	cout << "\n";
	cout << "States in Alphabetical Order" << "\n";
	for(int i=0; i<num_states; i++){
		cout << sorted_state[i] << " \n";
	}


	cout << "\n";
	cout << "States in Population Order" << "\n";
	for(int i=0; i<num_states; i++){
		cout << pop_names[i] << " \n";
	}

	cout << "\n";
	cout << "Counties in Alphabetical Order" << "\n";
	for(int i=0; i<county_num; i++){
		cout << sorted_county[i] << " \n";
	}

	cout << "\n";
	cout << "Counties in Population Order" << "\n";
	for(int i=0; i<county_num; i++){
		cout << c_pop_names[i] << " \n";
	}
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void print_file(state* states, int num_states, string pop_names[], string c_pop_names[], string sorted_state[], string sorted_county[], string population[], string income[], int inc, ofstream &file){
	for(int i=0; i<num_states; i++){
		file << states[i].name << " " << states[i].population << " " << states[i].counties << "\n";
		for(int j=0; j<states[i].counties; j++){
			file << states[i].c[j].name << " " << states[i].c[j].population << " " << states[i].c[j].avg_income << " " << states[i].c[j].avg_house << " " << states[i].c[j].cities << " "; 
			for(int k=0; k<states[i].c[j].cities; k++){
				file << states[i].c[j].city[k] << " " ;
			}
			file << "\n";
		}
		file << "\n";
	}

	int county_num = total_county_amount(states, num_states);
	file << "Largest State Population: " << population[0] << "\n";
	file << "Largest County Population: " << population[1] << "\n";

	file << "Counties with income over " << inc << "\n";
	for(int i=0; i<county_num; i++){
		file << income[i] << " "; 
	}

	file << "\n";
	file << "\n";
	file << "Average household costs for each county" << "\n";
	for(int i=0; i<num_states; i++){
		for(int j=0; j<states[i].counties; j++){
			file << states[i].c[j].name << " average household cost is " << states[i].c[j].avg_house << endl;
		}
	}

	file << "\n";
	file << "States in Alphabetical Order" << "\n";
	for(int i=0; i<num_states; i++){
		file << sorted_state[i] << " \n";
	}


	file << "\n";
	file << "States in Population Order" << "\n";
	for(int i=0; i<num_states; i++){
		file << pop_names[i] << " \n";
	}

	file << "\n";
	file << "Counties in Alphabetical Order" << "\n";
	for(int i=0; i<county_num; i++){
		file << sorted_county[i] << " \n";
	}

	file << "\n";
	file << "Counties in Population Order" << "\n";
	for(int i=0; i<county_num; i++){
		file << c_pop_names[i] << " \n";
	}
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void delete_info(state **states, int num_states){
	state* stated = *states;
	for(int i=0; i<num_states; i++){
		int counties = county_amount(*states, i);
		for(int j=0; j<counties; j++){	
			delete [] (stated[i]).c[j].city;
		}	
		delete [] stated[i].c;
	}
	delete [] stated;
	states = NULL;
	return;
}




























