#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct state{
	int id_num;
	string first_name;
	string last_name;
	string major;
};


state* create_student_db(int num_student);
void get_student_db_info(state *studs, int num_student, ifstream &file);
void print_students(state *studs, int num_students);
int* id_nums(state *studs, int num_students, int arr[]);
string* last_names(state *studs, int num_students, string arr[]);
int majors(state *studs, int num_students, string arr[]);
void swap_array(string* name1, string* name2);
void swap_num_array(int* name1, int* name2);
void print_array(string arr[], int size);
void print_int_array(int arr[], int size);
void sort_nums(int arr[], int size);
void sort(string arr[], int size);
void write_array(string names[], int id[], int size, int majors,  ofstream &file);
void delete_mem(state* states);
