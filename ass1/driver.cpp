#include <iostream>
#include "book.h"

using namespace std;

int main(int argc, char** argv){
	int num_states = (atoi(argv[2]));

	//Check args
	if((argc != 5) || (is_valid_arguments(argv, argc) == false)){
		cout << "Invalid arguments" << endl;
		return 0;
	}
	ifstream infile;
	infile.open(argv[4]);

	//Check file open
	if(infile.is_open())
		cout << "Opened " << argv[4] << endl;
	else{
		cout << "File " << argv[4] << " does not exist " << endl;
		return 0;
	}

	//Get data from file
	state* states = create_states(num_states);
	get_state_data(states, num_states, infile);

	//Collect info here
	int county_amount = total_county_amount(states, num_states);
	string population[2];
	string income_counties[county_amount+1];
	string state_names[num_states];
	string county_names[county_amount];
	string staten_pop[num_states];
	string countyn_pop[county_amount];
	int state_pop[num_states];
	int county_pop[county_amount];
	

	//Get info
	largest_pop(states, num_states, population);
	int income = income_check(states,num_states, income_counties);

	sort_names(states, num_states, state_names);
	sort_population(states, num_states, staten_pop, state_pop);
	sort_county_population(states, num_states, countyn_pop, county_pop);
	sort_county_names(states, num_states, county_names);
	

	//Print to screen or file
	int choice = file_or_print();
	if(choice == 1){
		print_screen(states, num_states, staten_pop, countyn_pop, state_names, county_names, population, income_counties, income);
	}
	if(choice == 2){
		ofstream write;
		char filename[256];
		cout << "What should the file name be written to: (ex. dog.txt)" << endl;
		cin.getline(filename, 256);
		write.open(filename);
		print_file(states, num_states, staten_pop, countyn_pop, state_names, county_names, population, income_counties, income, write);
	}

	//Finish and delete
	delete_info(&states, num_states);
	return 0;
}
