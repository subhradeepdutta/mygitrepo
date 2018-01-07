#include <stdio.h>
#include <stdlib.h>

/*Definition of a node in the queue*/
typedef struct node
{
/*Data contains the item stored in the queue*/
 char data;
/*Next is a pointer of type node that points to the next element in the queue*/
 struct node *next;
} queue;


/**********************************************************
Description: Function to add elements to the queue (rear)

Input:Accepts a character n that is to be added to the 
	  queue

Output:Returns 1 if successful else returns 0 for failure
**********************************************************/
int Enqueue(char n);

/**********************************************************
Description: Function to remove an element from the queue 
			 (front)

Input:N/A

Output:Returns the char which is deleted else returns '0'
**********************************************************/
char Dequeue();

/**********************************************************
Description: Function to print all the elements in the
			 queue

Input:N/A

Output:N/A
**********************************************************/
void PrintElements();

/**********************************************************
Description: Function to fetch the front node of the queue

Input:N/A

Output: Returns a pointer to the front of the queue else
		returns NULL if queue is empty
**********************************************************/
queue* Front();

/**********************************************************
Description: Function to fetch the rear node of the queue

Input:N/A

Output: Returns a pointer to the rear of the queue else
		returns NULL if queue is empty
**********************************************************/
queue* Rear();

/**********************************************************
Description: Function to check if the queue is empty

Input:N/A

Output: Returns 1 if queue is empty else returns 0
**********************************************************/
int IsEmpty();
