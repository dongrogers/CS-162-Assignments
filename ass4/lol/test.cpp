#include "test.h"
using namespace std;
bool is_int(string op){
	for(int i=0; i<op.length(); i++){
		if ((op[i] < '0') || (op[i] > '9')){
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
		cout << "Enter a number: ";
		cin >> num;
		if(is_int(num) == true){
			return get_int(num);
		}
		else{
			cout << "Bad Input" << endl;
		}
	}
	
}

int get_num_bound(int upper, int lower){
	int num;
	while(true){
		num = get_real_num();
		if(num > upper || num < lower){
			cout << "Too big/small, try again" << endl;
		}
		else{
			cout << string(1, '\n');
			break;
		}
	}
	return num;
}
