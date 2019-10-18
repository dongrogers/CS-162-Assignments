/*********************************************************************
** Program Filename: test_list.c
** Author: Rogers Dong
** Date: June 9th, 2018
** Description: Creates modifiable singly linked lists, able to print, sort, append, remove, insert
** Input: Integers
** Output: Node values from a list
*********************************************************************/ 
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
** Function: length 
** Description: Returns the length of a singly linked list
** Parameters: Struct node pointer
** Pre-Conditions: None
** Post-Conditions: Return integer length
*********************************************************************/ 
int length(struct node* head){
	int count = 0;
	struct node* current = head;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}


/*********************************************************************
** Function: print
** Description: Prints the contents of a singly linked list entirely
** Parameters: Struct node pointer, length of node pointer
** Pre-Conditions: None
** Post-Conditions: Contents printed
*********************************************************************/ 
void print(struct node* head, int num){
	int i;
	struct node* current = head;
	for(i=0; i<num; i++){
		printf("Node %d: %d \n", i+1, current->val);
		current = current->next;
	}

}


/*********************************************************************
** Function: push
** Description: Places a new node to the front of a linked list with a value
** Parameters: Struct node pointer, integer value
** Pre-Conditions: None
** Post-Conditions: New node pointer placed at beginning
*********************************************************************/ 
struct node* push(struct node* head, int num){
	struct node* new_head = (struct node*) malloc(sizeof(struct node));
	new_head->val = num;
	new_head->next = head;
	return new_head;
}


/*********************************************************************
** Function: append
** Description: Places a new node at the end of the linked list with a value
** Parameters: Struct node pointer, integer value
** Pre-Conditions: None
** Post-Conditions: New node pointer placed at end 
*********************************************************************/ 
struct node * append(struct node* head, int num){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->val = num;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else if(head->next == NULL){
		head->next = temp;
	}
	else{
		struct node* current = head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = temp;
	}
	return head;
}


/*********************************************************************
** Function: clear 
** Description: Deletes the entire contents of a node pointer and its contained pointers
** Parameters: Struct node pointer
** Pre-Conditions: None
** Post-Conditions: Memory freed
*********************************************************************/ 
struct node * clear(struct node* head){
	struct node* temp;
	struct node* current = head;
	while(current != NULL){
		temp = current->next;
		free(current);
		current = temp;
	}
	head = NULL;
	current = NULL;
	return head;
}


/*********************************************************************
** Function: remove_node
** Description: Removes an index provided by user in a struct node linked list
** Parameters: Struct node pointer, int value
** Pre-Conditions: None
** Post-Conditions: Node removed from a linked list
*********************************************************************/ 
struct node * remove_node(struct node* head, int index){
	struct node* left, *right, *current = head;
	int count = 1;
	//Error Handle
	if((index > length(head) || (index <= 0))){
		printf("Index there does not exist. \n");
		return head;

	}
	while(count != index+1){
		if(index == 1){
			left = current->next;
			free(current);
			head = left;
			return head;
		}
		if(count+1 == index){
			left = current;
		}
		else if(count == index){
			right = current->next;
			free(current);
			left->next = right;
			return head;
		}
		current = current->next;
		count++;
	}
}


/*********************************************************************
** Function: sort_ascending
** Description: Sorts the pointers in a singly linked list in order from lowest to highest, based on values contained
** Parameters: Struct node pointer
** Pre-Conditions: None
** Post-Conditions: Pointers sorted according to value
*********************************************************************/ 
struct node * sort_ascending(struct node* head){
	int i, j, k, run = 0;
	struct node* old_head = head, *current = head, *right, *temp;
	for(i=0; i<(length(head)-1); i++){
		old_head = head;
		current = head;
		run = 0;
		for(j=0; j<(length(head)-i-1); j++){
			temp = current->next;
			if(current->val > temp->val){
				right = temp->next; 
				current->next = right; 
				temp->next = current; 
				if(run == 0)
					head = temp;
				else
					old_head->next = temp;
			}
			run++;
			current = head;
			for(k=0; k<run; k++){
				if(k==run-1)
					old_head = current;
				current = current->next;
			}
		}
	}
	return head;
}


/*********************************************************************
** Function: sort_descending
** Description: Sorts the pointers in a singly linked list in order from highest to lowest, based on values contained
** Parameters: Struct node pointer
** Pre-Conditions: None
** Post-Conditions: Pointers sorted according to value
*********************************************************************/ 
struct node * sort_descending(struct node* head){
	int i, j, k, run = 0;
	struct node* old_head = head, *right, *temp, *current = head;
	for(i=0; i<(length(head)-1); i++){
		old_head = head;
		current = head;
		run = 0;
		for(j=0; j<(length(head)-i-1); j++){
			temp = current->next;
			if(current->val < temp->val){
				right = temp->next; 
				current->next = right; 
				temp->next = current; 
				if(run == 0)
					head = temp;
				else
					old_head->next = temp;
			}
			run++;
			current = head;
			for(k=0; k<run; k++){
				if(k==run-1)
					old_head = current;
				current = current->next;
			}
		}
	}
	return head;
}
 

/*********************************************************************
** Function: insert_middle
** Description: Creates a new new pointer and places it in the correct index of a linked list
** Parameters: Struct node pointer, int value, int index value
** Pre-Conditions: At least 1 value in node
** Post-Conditions: New pointer placed at index with value
*********************************************************************/ 
struct node * insert_middle(struct node* head, int num, int index){
	struct node* left, *right, *current = head;
	//Error Handle
	if(index != length(head)+1)
		if(index > length(head)){
			printf("Index there does not exist. \n");
			return head;
		}
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->val = num;
	int count = 1;
	while(count != index+1){
		if(index == 1){
			head = push(head, num);
			free(new_node);
			return head;
		}
		if(count+1 == index)
			left = current;
		if(count == index){
			right = current;
			left->next = new_node;
			new_node->next = right;
			return head;
		}
		current = current->next;
		count++;
	}
}

