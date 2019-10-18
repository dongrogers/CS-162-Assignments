#include <iostream>
#include "student_db.h"

using namespace std;

int main(){
	ifstream file;
	ofstream write;
	file.open("input.txt");
	write.open("write.txt");
	if(file.is_open())
		cout << "Opened " << "input.txt" << endl;
	else
		cout << "Not open " << endl;
	
	int num_students;
	file >> num_students;

	//Create structs
	state* studs = create_student_db(num_students);
	get_student_db_info(studs, num_students, file);
	
	//Get id nums
	int id_arr[num_students];
	id_nums(studs, num_students, id_arr);

	//Get last names
	string last_arr[num_students];
	last_names(studs, num_students, last_arr);

	//Get unique majors
	string major_arr[num_students];
	int majos = majors(studs, num_students, major_arr);

	//Sort	
	sort(last_arr, num_students);
	sort_nums(id_arr, num_students);

	//Write
	write_array(last_arr, id_arr, num_students, majos, write);
	cout << "Wrote to write.txt" << endl;
	delete_mem(studs);
	write.close();
	
}
