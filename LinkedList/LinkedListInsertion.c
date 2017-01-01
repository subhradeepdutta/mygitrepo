/****************************************************************
*Name: Subhradeep Dutta
*Date: 12/30/2016
*This program adds an element to the beginning and nth position
*of a linked list and then displays the elements in the list
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int NoOfElements;

struct node
{
    int data;//Refers to the data part of the linked list
    struct node* next;//Refers to the pointer which points to the next element
};


/*************************************************************************************
Description   : This function is used to print the elements in the linked list
Input         : Pointer to the beginning of the linked list
Output        : N/A
*************************************************************************************/


void PrintElements(struct node *start)
{

    if(start==NULL)//If the list is empty
        printf("List is empty");
    else
    {
        printf("\n The list is ");
        while(start!=NULL)
        {
            printf("%d ",start->data);
            start=start->next;//Iterate to the next element
        }
    }
}

/*************************************************************************************
Description   : This function is used to insert elements in the beginning of the
                linked list
Input         : Element to be inserted
Output        : Pointer to the new beginning of the linked list
*************************************************************************************/

struct node* InsertElementInTheBeginning(struct node *start, int x)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)//Check if malloc was successful
    {
        printf("Memory allocation failed");
        return start;//Return the original pointer to the beginning
    }
    new_node->data=x;
    new_node->next=start;//Copy the location to the next element from the start pointer
    start=new_node;//Make start point to the newly inserted element
    NoOfElements++;
    return new_node;

}

/*************************************************************************************
Description   : This function is used to insert elements in the nth position of the
                linked list
Input         : Element and position to be inserted, pointer to beginning of linked
                list
Output        : Pointer to the beginning of the linked list
*************************************************************************************/

struct node* InsertElementAtN(struct node *start,int x, int n)//Here the starting position for the linked list is assumed to be 1
{
    int i;
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)//Check if malloc was successful
    {
        printf("Memory allocation failed");
        return start;
    }
    new_node->data=x;
    new_node->next=NULL;
    if(n==1)
    {
        new_node->next=start;
        start=new_node;
        return start;
    }
    struct node *ptr;
    ptr=start;
    for(i=0;i<n-2;i++)//n-2 to iterate to the (n-1)th location
    {
        if (ptr->next == NULL)
            return NULL;
        ptr=ptr->next;
    }
    new_node->next=ptr->next;//Copy the location of the next element from ptr
    ptr->next=new_node;//Make ptr point to the newly created element
    NoOfElements++;
    return start;
}

int main()
{

    int x=0, n=0, i=0;
    struct node *HEAD;//Pointer that points to beginning of the list
    struct node *ptr;//Pointer to iterate through the list
    HEAD=NULL; //Assigning HEAD to null when there are no elements in the list
    printf("Enter numbers to be inserted into the list\n Press q to quit\n");
    while(scanf("%d",&x)==1)//Check if scanf was succesful
    {
        HEAD=InsertElementInTheBeginning(HEAD,x);
        PrintElements(HEAD);
        printf("\n\rEnter numbers to be inserted into the list\n Press q to quit\n");
    }
        printf("Enter the number and position to be inserted");
        getchar();
        if(scanf(" %d",&i)==1&&scanf(" %d",&n)==1)//Check if scanf was successful
        {
            if(n>NoOfElements)//Condition to check if the nth location is greater than the list size
            {
                printf("\nLocation exceeds list size");
                printf("\nSetting position to last location");
                n=NoOfElements;
            }
            printf("\n The value %d will be inserted at %d position",i, n);
            HEAD=InsertElementAtN(HEAD, i, n);
            PrintElements(HEAD);
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

