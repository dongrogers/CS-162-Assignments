#include "./mult_div.h" 

using namespace std;


bool is_int(char op[]){
	for(int i=0; i<strlen(op); i++){
		if ((op[i] < '0') || (op[i] > '9')){
			return false;
		}
	}
	return true;
}

bool is_sint(string num){
	for(int i=0; i<num.length(); i++){
		if ((num[i] < '0') || (num[i] > '9')){
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
		cin >> num;
		if(is_sint(num) == true){
			return get_int(num);
		}
	}
	
}

mult_div_values** create_table(int row, int col){
	mult_div_values** table = new mult_div_values*[row];
	for(int i=0; i<row; i++){
		table[i] = new mult_div_values[col];
	}
	return table;
}


void gen_mult(mult_div_values** table, int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			(table[i][j]).mult_table = (i+1)*(j+1);
		}
	}
}

void gen_div(mult_div_values** table, int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			table[i][j].div_table = (float(table[i][i].mult_table) / float(table[i][j].mult_table));		}
	}
}


void print_table(mult_div_values** table, int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
		cout << table[i][j].mult_table << " ";
		}
		cout << endl;
	}
}

void print_div_table(mult_div_values** table, int row, int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
		cout << table[i][j].div_table << " ";
		}
		cout << endl;
	}
}


