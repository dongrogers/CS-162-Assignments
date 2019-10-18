#include <stdio.h>
#include <stdlib.h>
int main(){
	int size, row, col, i, j, r, add;
	srand(time(NULL));
	while(1){
		printf("Width: Enter size between 1 and 10 \n");
		scanf("%d", &row);
		if(row < 0 || row > 10)
			printf("Bad input. \n");
		else
			break;
	}
	while(1){
		printf("Height: Enter size between 1 and 10 \n");
		scanf("%d", &col);
		if(col < 0 || col > 10)
			printf("Bad input. \n");
		else
			break;
	}
	int** arr = (int**)malloc(sizeof(int)*row);
	for(i=0; i<row; i++)
		arr[i] = (int*)malloc(sizeof(int)*col);

	for(i=0; i<row; i++){
		printf("\n");
		for(j=0; j<col; j++){
			r = rand() % 50+1;
			arr[i][j] = r;
			printf("%d ", r);
		}
	}

	//Get addition
	printf("\n Enter a value to add \n");
	scanf("%d", &add);
	
	//Add to each element
	for(i=0; i<row; i++){
		printf("\n");
		for(j=0; j<col; j++){
			arr[i][j] += add;
			printf("%d ", arr[i][j]);
		}
	}
	

	
}
