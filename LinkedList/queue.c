#include <stdio.h>
#include "queue.h"

queue *front = NULL, *rear=NULL;


int IsEmpty()
{
	//When queue is empty front and rear both are NULL
	if((front== NULL) && (rear == NULL))
		return(1);
	else
		return(0);
}

int Enqueue(char n)
{
	queue *temp = (queue*)malloc(sizeof(queue));
	//Check if malloc was successful
	if(temp == NULL)
	{
		printf("Allocation failed");
		return(0);
	}
	temp->data = n;
	temp->next = NULL;
	//Special case if the queue was initially empty
	if(IsEmpty())
	{
		front = temp;
		rear = temp;
		return(1);
	}
	//Repoint the rear to the newly added node
	rear->next = temp;
	rear = temp;
	return(1);
}

char Dequeue()
{
	queue *temp = front;
	char del_val;
	if(IsEmpty())
	{
		printf("Queue is empty");
		return('0');
	}
	//Special case when only one element is left
	else if(front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	del_val = temp->data;
	free(temp);
	return(del_val);
}

void PrintElements()
{
	if(IsEmpty())
	{
		printf("Queue is empty");
		return;
	}
	queue *temp = front;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%c ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

queue* Front()
{
	if(front == NULL)
		return(NULL);
	else
		return (front);
}
queue* Rear()
{
	if(rear == NULL)
		return(NULL);
	else
		return (rear);
}
