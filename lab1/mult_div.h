#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;


bool is_int(char op[]);
bool is_valid_dimensions(char* row, char* col);
struct mult_div_values {
	int mult_table;
	float div_table;
};
mult_div_values** create_table(int row, int col);
void gen_mult(mult_div_values** table, int row, int col);
void gen_div(mult_div_values** table, int row, int col);
void print_table(mult_div_values** table, int row, int col);
void print_div_table(mult_div_values** table, int row, int col);
void delete_table(mult_div_values ** table, int row, int col);
int get_int(string num);
int get_real_num();
bool is_sint(string num);
