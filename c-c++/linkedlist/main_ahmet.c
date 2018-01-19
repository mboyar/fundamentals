#include <stdio.h>  
#include <math.h>
#include <stdlib.h> 

#define IGNORE_SEGMENTATION_FAULT_POSSIBLITY_OF_UPPER_LEVEL_FUNCTIONS // enable to accept NULL address pointer as an valid address input...

typedef struct _linkListElem {
    int val;
    struct _linkListElem *next;
    } linkListElem;

    
#ifdef IGNORE_SEGMENTATION_FAULT_POSSIBLITY_OF_UPPER_LEVEL_FUNCTIONS
bool addlinkToList(linkListElem **head, int a, int b) {
#else 
bool addlinkToList(linkListElem *head, int a, int b) {
#endif
    // this function should find the link in the linked list that has equal or closest value to 
    // a, then it should insert a new element into the linked list right after that element,
    // and the val of t he new element should be b
	int diff_prev = 0x7fffffff, diff_current = 0;
	
	linkListElem * current = *head;
	linkListElem * closest;	
	linkListElem * prev;
	linkListElem * closest_prev;
	linkListElem * new_node;
	
	if (current == NULL)
	#ifdef IGNORE_SEGMENTATION_FAULT_POSSIBLITY_OF_UPPER_LEVEL_FUNCTIONS
	{
		*head = (linkListElem*)malloc(sizeof(linkListElem));
		
		if(*head == NULL)
			return false;

		(*head)->val = b;
		(*head)->next = NULL;
		return true;
	}	
	#else 
		return false;
	#endif
		
	new_node = (linkListElem*)malloc(sizeof(linkListElem));
	
	if(new_node == NULL)
		return false;
	
	new_node->val = b;
	
		
    while (current != NULL) {
    	
    	prev = current;
		diff_current = abs(current->val - a); 
		if ( diff_current < diff_prev) // diff_prev is set to max positive interger to decrease cpu load(if we think for MCU design, also program memory) as decreasing use count of subtraction and abs operations..
		{
			diff_prev = diff_current;
			closest_prev = prev;
			closest = current->next;
		}
		
		current= current->next;
    }
		
	new_node->next = closest;
	closest_prev->next = new_node;	
	
	return true;

}


linkListElem * BuildTestLinkedList() {
	
	linkListElem *head =  (linkListElem*)malloc(sizeof(linkListElem));
	linkListElem *second = (linkListElem*)malloc(sizeof(linkListElem));;
	linkListElem *third =  (linkListElem*)malloc(sizeof(linkListElem));	
	
	if( (head && second && third) == NULL )
		return NULL;
	
	head->val = 1; 
	head->next = second; 
	second->val = 7; 
	second->next = third;
	third->val = 18;
	third->next = NULL;

	return head;
}

void ShowAll(linkListElem * head) {

	linkListElem *current = head;
	
	while (current != NULL) {
		
		printf("value: %d\n",current->val);
		current = current->next;
	}
	
}

int main(int argc, char** argv) {
	
	int value_a, value_b;

#ifdef IGNORE_SEGMENTATION_FAULT_POSSIBLITY_OF_UPPER_LEVEL_FUNCTIONS
	linkListElem * list = NULL;	
#else
	linkListElem * list = BuildTestLinkedList();
		
	if(list == NULL)
	{
		printf("\n Test LinkedList couldn't be created. Memory allocation failure!!!\n\n");
		
		system("pause");
		return 0;
	}
#endif	

#ifndef IGNORE_SEGMENTATION_FAULT_POSSIBLITY_OF_UPPER_LEVEL_FUNCTIONS	
	ShowAll(list);
#endif
	
	
	while(1)
	{
		printf("\nPlease Enter Value a:");
		scanf("%d", &value_a);
	
		printf("\nPlease Enter Value b:");
		scanf("%d", &value_b);
	
	#ifdef IGNORE_SEGMENTATION_FAULT_POSSIBLITY_OF_UPPER_LEVEL_FUNCTIONS	
		if(!addlinkToList(&list,value_a,value_b))
	#else 	
		if(!addlinkToList(list,value_a,value_b))
	#endif
		{
			printf("\nMemory Allocation Failure.. New link could not be created!!!\n"); // It can be a NULL head pointer too.
			
			system("pause");	
			return 0;
		}
	
		printf("\nAfter insertion of value b to linkedlist just after the value which equal or closest to value a\n");
		
		ShowAll(list);
	}

	return 0;
}
