#include <iostream>
#include "student_db.h"

using namespace std;

state* create_student_db(int num_student){
	state* studs = new state[num_student];
	return studs;
}

void get_student_db_info(state *studs, int num_student, ifstream &file){
	for(int i=0; i<num_student; i++){
		file >> studs[i].id_num >> studs[i].first_name >> studs[i].last_name >> studs[i].major;
	}	
}

void print_students(state *studs, int num_students){
	for(int i=0; i<num_students; i++){
		cout << studs[i].id_num << " " << studs[i].first_name << " " << studs[i].last_name << " " << studs[i].major << endl;
	}
}

int* id_nums(state *studs, int num_students, int arr[]){
	for(int i=0; i<num_students; i++){
		arr[i] = studs[i].id_num;
	}
	return arr;
}

string* last_names(state *studs, int num_students, string arr[]){
	for(int i=0; i<num_students; i++){
		arr[i] = studs[i].last_name;
	}
	return arr;
}

int majors(state *studs, int num_students, string arr[]){
	int where = 0, count = 0;
	for(int i=0; i<num_students; i++){
		arr[where] = studs[i].major;
		where++;
		for(int j=0; j<i-1; j++)
			if(arr[i] == arr[j])
				where--;
	}
	for(int i=0; i<num_students; i++){
		if(arr[i][0] >= 'A' && arr[i][0] <= 'Z')
			count++;
	}
	return count;
}

void swap_array(string* name1, string* name2){
	string temp = *name1;
	*name1 = *name2;
	*name2 = temp;
}

void swap_num_array(int* name1, int* name2){
	int temp = *name1;
	*name1 = *name2;
	*name2 = temp;
}

void sort_nums(int arr[], int size){
	for(int i=0; i< (size-1); i++){
		for(int j=0; j<(size-i-1); j++){
			if(arr[j] > arr[j+1]){
				swap_num_array(&arr[j], &arr[j+1]);
			}
		}
	}
}

void sort(string arr[], int size){
	for(int i=0; i< (size-1); i++){
		for(int j=0; j<(size-i-1); j++){
			if(arr[j] > arr[j+1]){
				swap_array(&arr[j], &arr[j+1]);
			}
		}
	}
}

void print_array(string arr[], int size){
	for(int i=0; i<size; i++){
		cout << "Rank " << i << ": " << arr[i] << endl;
	}
}

void print_int_array(int arr[], int size){
	for(int i=0; i<size; i++){
		cout << "Rank " << i << ": " << arr[i] << endl;
	}
}

void write_array(string names[], int id[], int size, int majors, ofstream &file){
	file << "SORTED LAST NAMES.\n";
	for(int i=0; i<size; i++){
		file << names[i] << " ";
	}
	file << "\n";
	file << "SORTED ID NUMBERS.\n";
	for(int i=0; i<size; i++){
		file << id[i] << " ";
	}
	file << "\n";
	file << "NUM OF UNIQUE MAJORS.\n";
	file << majors;
}

void delete_mem(state* states){
	delete [] states;
	states = NULL;
}
