/****************************************************************
*Name: Subhradeep Dutta
*Date: 1/6/2016
*This program implements a doubly linked list by adding elements
*and deleting elements from the linked list
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int NoOfElements;

struct node
{
    int data;//Refers to the data part of the linked list
    struct node* next;//Refers to the pointer which points to the next element
    struct node* prev;//Refers to the pointer which points to the previous element
};

/**Function Protypes**/
void PrintElements(struct node *start);
void InsertElementInTheBeginning(struct node **start, struct node **end, int x);
void InsertElementAtN(struct node **start, int x, int n);
void DeleteElementAtN(struct node **start, struct node **end, int n);
void PrintReverse(struct node *end);

/*************************************************************************************
Description   : This function is used to print the elements in the linked list
Input         : Pointer to the beginning of the linked list
Output        : N/A
*************************************************************************************/


void PrintElements(struct node *start)
{

    if(start==NULL)//If the list is empty
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        printf("\n The list is ");
        while(start!=NULL)
        {
            printf("%d ",(start)->data);
            start=(start)->next;//Iterate to the next element
        }
    }
}

/*************************************************************************************
Description   : This function is used to insert elements in the beginning of the
                linked list
Input         : Element to be inserted and address of the pointer to start and end
                location of the linked list
Output        : N/A
*************************************************************************************/

void InsertElementInTheBeginning(struct node **start, struct node **end, int x)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)//Check if malloc was successful
    {
        printf("Memory allocation failed");
        return;
    }
    new_node->data=x;
    if(*start==NULL)
    {
        *end=new_node;//Make the tail point to the only element in the list, special case where head and tail point to the same element
    }
    else
    {
        (*start)->prev=new_node;//Make the first node of the list point to the newly created node
    }
    new_node->prev=NULL;//The newly created node is 1st in the list so prev refers to NULL
    new_node->next=*start;//Copy the location of already existing element from start pointer
    *start=new_node;//Make start point to the newly created node
    NoOfElements++;

}

/*************************************************************************************
Description   : This function is used to insert elements in the nth position of the
                linked list
Input         : Element and position to be inserted, address to the pointer to
                beginning of linked list
Output        : N/A
*************************************************************************************/

void InsertElementAtN(struct node **start, int x, int n)//Here the starting position for the linked list is assumed to be 1
{
    int i;
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)//Check if malloc was successful
    {
        printf("Memory allocation failed");
        return;
    }
    new_node->data=x;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(n==1)//Special case when insertion at the beginning of the linked list
    {
        new_node->next=*start;//Next pointer of the newly created node now points to the first element in the list
        (*start)->prev=new_node;//Prev pointer of the first node points to the newly created node
        *start=new_node;//Start now points to the newly created node
        NoOfElements++;
        return;
    }
    struct node *ptr;
    ptr=*start;
    for(i=0;i<n-2;i++)//n-2 to iterate to the (n-1)th location
    {
        if (ptr->next == NULL)
            return;
        ptr=ptr->next;
    }
    new_node->next=ptr->next;//Copy the location of the next element from ptr
    ptr->next->prev=new_node;//Make the next node point back to the newly created node
    ptr->next=new_node;//Make ptr point to the newly created node
    new_node->prev=ptr;
    NoOfElements++;
}


/*************************************************************************************
Description   : This function is used to delete elements in the nth position of the
                linked list
Input         : Position to be deleted, address of pointer to beginning of linked
                list and end of linked list
Output        : N/A
*************************************************************************************/
void DeleteElementAtN(struct node **start, struct node **end, int n)
{
    int i;
    struct node* temp=NULL;
    struct node* ptr=NULL;
    ptr=*start;
    if(n==1 && NoOfElements>1)//Special case for the starting node
    {
        *start=ptr->next;//The start location pointer is now pointing to 2nd node
        free(ptr);
        (*start)->prev=NULL;
        NoOfElements--;//Reduce the number of elements by 1
        return;
    }
    if(n==NoOfElements && NoOfElements>1)//Special case for the last node
    {
        ptr=*end;
        *end=(*end)->prev;//Shift the end to the second last node
        (*end)->next=ptr->next;//Copy the next pointer from the last node onto the second last node
        free(ptr);
        NoOfElements--;
        return;
    }
    if(n==1 && NoOfElements==1)//Special case when only one node is left
    {
        free(ptr);
        *start=NULL;
        *end=NULL;
        NoOfElements--;
        return;
    }
    for(i=0;i<n-2;i++)//n-2 to iterate to the (n-1)th location
    {
        if (ptr->next == NULL)
            return;
        ptr=ptr->next;
    }
    temp=ptr->next;//Nth node which is supposed to be deleted
    ptr->next=temp->next;//Reassign the link part of Nth node to the (N-1)th node to point to the (N+1)th node
    temp->next->prev=ptr;
    free(temp);
    NoOfElements--;//Update the number of elements
    return;

}




/*************************************************************************************
Description   : This function is used to print the elements of the linked list in
                reverse order using recursion
Input         : Pointer to the end of the linked list
Output        : N/A
*************************************************************************************/

void PrintReverse(struct node *end)
{
    if(end==NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ",end->data);
    PrintReverse(end->prev);

}


int main()
{

    char choice;
    int flag=1;
    int x=0, n=0, i=0;
    struct node *HEAD, *TAIL;//Pointer that points to beginning of the list and end of the list
    struct node *ptr;//Pointer to iterate through the list
    HEAD=NULL; //Assigning HEAD to null when there are no elements in the list
    TAIL=NULL; //Assigning TAIL to null when there are no elements in the list

    printf("Enter numbers to be inserted into the list\n Press q to quit\n");
    while(scanf("%d",&x)==1)//Check if scanf was succesful
    {
        InsertElementInTheBeginning(&HEAD, &TAIL, x);
        PrintElements(HEAD);
        printf("\n\rEnter numbers to be inserted into the list\n Press q to quit\n");
    }

    while(flag==1)//As long as flag is 1 loop runs infintely
    {
        printf("\nMake a selection");
        printf("\nPress 1 to insert elements");
        printf("\nPress 2 to delete elements");
        printf("\nPress 3 to print the current list");
        printf("\nPress 4 to print the current list in reverse order");
        printf("\nPress 9 to quit\n");
        getchar();
        scanf(" %c",&choice);
        switch(choice)
        {
            case '1':
                printf("Enter the number and position to be inserted\n");

                if(scanf(" %d",&i)==1&&scanf(" %d",&n)==1)//Check if scanf was successful
                {
                    if(n>NoOfElements && NoOfElements!=0)//Condition to check if the nth location is greater than the list size
                    {
                        printf("\nLocation exceeds list size");
                        printf("\nSetting position to last location");
                        n=NoOfElements;
                    }
                    else if(NoOfElements==0)
                    {
                        printf("\nList is empty \n Inserted element in the beginning");
                        InsertElementInTheBeginning(&HEAD, &TAIL, i);
                        PrintElements(HEAD);
                        break;
                    }
                    printf("\n The value %d will be inserted at %d position",i, n);
                    InsertElementAtN(&HEAD, i, n);
                    PrintElements(HEAD);
                }
                break;
//
            case '2':
                printf("Enter the position to be deleted\n");
                if(scanf("%d",&n)==1)
                {
                    if(n>NoOfElements && NoOfElements!=0)//Condition to check if the nth location is greater than the list size
                    {
                        printf("\nLocation exceeds list size");
                        printf("\nSetting position to last location");
                        n=NoOfElements;
                    }
                    else if(NoOfElements==0)
                    {
                        printf("\nList is empty");
                        flag=0;
                        break;
                    }
                    DeleteElementAtN(&HEAD, &TAIL, n);
                    printf("\n The value at %d position is now deleted",n);
                    PrintElements(HEAD);
                }
                break;
//
            case '3':
                PrintElements(HEAD);
                break;
//
            case '9':
                flag=0;
                break;


            case '4':
                printf("\n Printing elements in reverse order\n");
                PrintReverse(TAIL);
                break;



            default:
                printf("Incorrect choice");
                break;
        }
    }

     /**Freeing memory**/

    while(HEAD!=NULL)
    {
        ptr=HEAD;
        HEAD=ptr->next;
        free(ptr);

    }
    printf("\nMemory cleared");

    return 0;
}

