#include <stdio.h>
#include <stdlib.h>
 
int NumElements = 0;

typedef struct node
{
    int number;
    struct node * next;
}node;

void print_elements(node *start)
{
    if(start == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("\n\r");
    while(start!=NULL)
    {
        printf("%d ", start->number);
        start = start->next;
    }
    printf("\n\r");
}

node *InsertElements(node* start, int position, int n)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->number = n;
    newnode->next = NULL;
    node *ptr = start;
    if(position ==1)
    {
        newnode->next = start;
        start = newnode;
        NumElements++;
        return start;
    }
    for(int i = 1; i<position-1;i++)
    {
        if(ptr->next == NULL)
        {
            return start;
        }
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next= newnode;
    NumElements++;
    return start;
}

node *DeleteElement(node *start, int position)
{
    node *ptr = start;
    if(position > NumElements)
    {
        printf("Index out of bounds");
        return start;
    }
    if(position == 1)
    {
        start = ptr->next;
        ptr->next = NULL;
        free(ptr);
        NumElements--;
        return start;
    }
    for(int i=1;i<position-1;i++)
    {
        if(ptr->next == NULL)
        {
            return start;
        }
        ptr=ptr->next;
    }
    node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next = NULL;
    NumElements--;
    free(temp);
    return start;
}

/*Reverse linked list using iteration*/

node *reverse_iterative(node *start)
{
    node *current, *prev, *post;
    current = start;
    prev = NULL;
    post = NULL;
    while(current!=NULL)
    {
        post = current->next;
        current->next = prev;
        prev = current;
        current = post;
    }
    start = prev;
    return start;
}

/*Reverse linked list using recursion*/

node *reverse_recursive(node* start)
{
    if(start->next == NULL)
    {
        return start;
    }
    else
    {
        node *newstart = reverse_recursive(start->next);
        start->next->next = start;
        start->next = NULL;
        return newstart;
    }
}

/*Fetch nth node in a linked list*/

void NthNode(node *start, int index)
{
    if(index>NumElements)
    {
        printf("Index out of bounds");
        return;
    }
    node *ptr= start;
    while(ptr!=NULL)
    {
        index--;
        if(index == 0)
        {
            printf("\n\rThe element is %d", ptr->number);
            return;
        }
        ptr=ptr->next;

    }
}

/*Print elements in reverse order*/

void PrintReverse(node *start)
{
    if(start==NULL)
    {
        printf("\n");
        return(start);
    }
    PrintReverse(start->next);
    printf("%d ",start->number);
}



node *ReferenceGenerator(node *start)
{
    start=start->next;
    return start;
}

/*Given only a reference to a node delete that node*/

void DeleteByReference(node *start)
{
    node *ptr = start->next;
    start->number = ptr->number;
    start->next = ptr->next;
    free(ptr);
    NumElements--;

}

/*Middle element in the linked list*/

void MiddleElement(node * start)
{
	node *fast = start;
	node *slow = start;
	while(fast!= NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("\n Middle element %d", slow->number);
}

int LengthOfLinkedList(node *start)
{
	int counter = 0;
	while(start->next!=NULL)
	{
		counter++;
		start = start->next;
	}
	counter++;
	return counter;
}

node *InsertInSortedList(node *start, int value)
{
	node *ptr = start, *backupptr=NULL;
	int temp = 0;
	while(ptr!=NULL)
	{
		if(value>=ptr->number)
		{
			backupptr = ptr;
			ptr = ptr->next;
			continue;
		}
		node *newnode = (node *)malloc(sizeof(node));
		temp = ptr->number;
		ptr->number = value;
		newnode->number = temp;
		newnode->next = ptr->next;
		ptr->next = newnode;
		NumElements++;
		return start;
	}
	node *newnode = (node *)malloc(sizeof(node));
	newnode->number = value;
	newnode->next = backupptr->next;
	backupptr->next = newnode;
	return start;
}

node *DeleteDuplicatesInSortedList(node *start)
{
	node *ptr = start;
	node *prev = NULL;
	while(ptr!=NULL && ptr->next!=NULL)
	{
		prev=ptr;
		ptr = ptr->next;
		if(prev->number == ptr->number)
		{
			prev->next = ptr->next;
			free(ptr);
			ptr= prev->next;
		}
	}
	return start;
}

void DeleteDuplicatesInUnsortedList(node *start)
{
	node *ptr1, *ptr2, *duplicate;
	ptr1 = start;
	while(ptr1!=NULL && ptr1->next!=NULL)
	{
		ptr2 = ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->number == ptr2->next->number)
			{
				duplicate = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(duplicate);
				NumElements--;
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1= ptr1->next;
	}
}

node *RotateLinkedListCounterClockWise(node *start, int rotation)
{
	node *kth, *last, *ptr;
	ptr = start;
	int count = 0;
	while(ptr!=NULL)
	{
		count++;
		if(count == rotation)
		{
			kth = ptr;
		}
		last = ptr;
		ptr = ptr->next;
	}
	last->next = start;
	start = kth->next;
	kth->next = NULL;
	return(start);
}

node *RotateLinkedListClockWise(node *start, int rotation)
{
	int length = LengthOfLinkedList(start);
	node *kth, *last, *ptr;
	ptr = start;
	int count = 0;
	while(ptr!=NULL)
	{
		count++;
		if(count == (length - rotation))
		{
			kth = ptr;
		}
		last = ptr;
		ptr = ptr->next;
	}
	last->next = start;
	start = kth->next;
	kth->next = NULL;
	return(start);
}

void LoopCreator(node *start)
{
	node *ptr = start;
	node *temp = NULL;
	ptr = ptr->next;
	ptr = ptr->next;
	temp = ptr;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}



node *LoopDetector(node *start)
{
	node *fast = start;
	node *slow = start;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			printf("\nLoop detected");
			slow = start;
			while(slow->next!=fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}
			fast->next = NULL;
		}
	}
	return(start);
}

node *SortedMerge(node* start, node *start1, node *target)
{
	node *ptr1 = start;
	node *ptr2 = start1;
	node *ptr3 = target;
	node *temp = NULL;
	while(ptr1!=NULL || ptr2!=NULL)
	{
		if(ptr1!=NULL && ptr2!=NULL)
		{
			if(ptr1->number >= ptr2->number)
			{
				node *newnode = (node *)malloc(sizeof(node));
				newnode->number = ptr2->number;
				newnode->next = ptr3->next;
				ptr3->next = newnode;
				ptr2 = ptr2->next;
				
			}
			else if(ptr1->number < ptr2->number)
			{
				node *newnode = (node *)malloc(sizeof(node));
				newnode->number = ptr1->number;
				newnode->next = ptr3->next;
				ptr3->next = newnode;
				ptr1 = ptr1->next;
				
			}
			ptr3 = ptr3->next;
		}
		else
		{
			if(ptr1==NULL)
			{
				node *newnode = (node *)malloc(sizeof(node));
				newnode->number = ptr2->number;
				newnode->next = ptr3->next;
				ptr3->next = newnode;
				ptr2 = ptr2->next;
			}
			else if(ptr2==NULL)
			{
				node *newnode = (node *)malloc(sizeof(node));
				newnode->number = ptr1->number;
				newnode->next = ptr3->next;
				ptr3->next = newnode;
				ptr1 = ptr1->next;
			}
		}
	}
	return(target);
}


int main()
{
    node *HEAD = NULL;
    node *HEAD1 = NULL;
    node *RESULT = NULL;
    node *ref = NULL;
    HEAD = InsertElements(HEAD,1,1);
    HEAD = InsertElements(HEAD,2,2);
    HEAD = InsertElements(HEAD,3,9);
    HEAD = InsertElements(HEAD,4,14);

    HEAD1 = InsertElements(HEAD1,1,4);
    HEAD1 = InsertElements(HEAD1,2,12);
    HEAD1 = InsertElements(HEAD1,3,15);

    print_elements(HEAD);
    print_elements(HEAD1);

    RESULT = InsertElements(RESULT,1,0);
    RESULT = SortedMerge(HEAD1, HEAD, RESULT);
    print_elements(RESULT);
    // LoopCreator(HEAD);
    // HEAD = LoopDetector(HEAD);
    // print_elements(HEAD);
    // HEAD = RotateLinkedListCounterClockWise(HEAD,3);
    // print_elements(HEAD);
    // HEAD = RotateLinkedListClockWise(HEAD,3);
    // print_elements(HEAD);
    // HEAD = InsertInSortedList(HEAD,2);
    // print_elements(HEAD);
    // MiddleElement(HEAD);
    // DeleteDuplicatesInUnsortedList(HEAD);
    // print_elements(HEAD);
    // HEAD = reverse_iterative(HEAD);
    // print_elements(HEAD);
    // HEAD = reverse_recursive(HEAD);
    // print_elements(HEAD);
    // HEAD = DeleteElement(HEAD,3);
    // HEAD = DeleteElement(HEAD,1);
    // print_elements(HEAD);
    // NthNode(HEAD, 2);
    // PrintReverse(HEAD);
    // ref = ReferenceGenerator(HEAD);
    // DeleteByReference(ref);
    // print_elements(HEAD);
    return(0);
}
