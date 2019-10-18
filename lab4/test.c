#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_int(string op){
	for(int i=0; i<op.length(); i++){
		if ((op[i] < '0') || (op[i] > '9')){
			return 0;
		}
	}
	return 1;
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
	int good = 1;
	string num;
	while(good == 1){
		scanf("%d", num); 
		if(is_int(num) == 1){
			return get_int(num);
		}
		else{
			printf("Bad input \n");
		}
	}
	
}

int get_num_bound(int upper, int lower){
	int num = 0;
	while(1){
		num = get_real_num();
		if(num > upper || num < lower){
			printf("Too big/small \n");
		}
		else{
			break;
		}
	}
}
