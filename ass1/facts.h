//book.h
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

struct county{
	string name;
	string* city;
	int cities;
	int population;
	float avg_income;
	float avg_house;

};

struct state{
	string name;
	struct county *c;
	int counties;
	int population;
};


void get_state_data(state* states, int num_states, ifstream &file);
state* create_states(int num);
county* create_counties(int num);
void get_county_data(county* counties, int num_counties, ifstream &file);
bool is_valid_arguments(char** argv, int argc);
void print_data(state* states, int num_states);
void largest_pop(state* states, int num_states, string arr[]);
int income_check(state* states, int num_states, string arr[]);
void swap_array(string* name1, string* name2);
void swap_intarray(int* name1, int* name2);
void sort_names(state* states, int num_states, string names[]);
void sort_population(state* states, int num_states, string statenames[], int pop[]);
void sort_county_population(state* states, int num_states, string countynames[], int pop[]);
void sort_county_names(state* states, int num_states, string names[]);
int county_amount(state* states, int num_states);
void print_file(state* states, int num_states, string pop_names[], string c_pop_names[], string sorted_state[], string sorted_county[], string population[], string income[], int inc, ofstream &file);
void print_screen(state* states, int num_states, string pop_names[], string c_pop_names[], string sorted_state[], string sorted_county[], string population[], string income[], int inc);
int total_county_amount(state* states, int num_states);
int file_or_print();
void delete_info(state **states, int num_states);
