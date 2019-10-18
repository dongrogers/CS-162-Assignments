// C program for implementation of Bubble sort
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void swap(string *xp, string *yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(string arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(string arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
	string arr[] = {"Oregon", "California", "Cag_Cali", "Rofl", "Zell", "Yikoming", "Jeez"};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "YO LOOK: " << n << endl;
	bubbleSort(arr, n);
	
	printArray(arr, n);
	return 0;
}
