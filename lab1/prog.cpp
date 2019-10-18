#include "mult_div.h"

using namespace std;

int main(int argc, char** argv){
	int row, col;
	bool good = true;
	if((argc != 3) ||((is_int(argv[1]) == false) || (is_int(argv[2]) == false))){
		cout << "Bad Arguments" << endl;
		good = false;
	}
	
	if(good == true){
		row = atoi(argv[1]);
		col = atoi(argv[2]);
	}
	else{
		cout << "Enter a row" << endl;
		row = get_real_num();
		cout << "Enter a col" << endl;
		col = get_real_num();
	}
	mult_div_values** table = create_table(row, col);

	gen_mult(table, row, col);
	cout << "Multiplication Table: " << endl;
	print_table(table, row, col);

	gen_div(table, row, col);
	cout << "Division Table:" << endl;
	print_div_table(table, row, col);
	return 0;
}
