/****************************************************************
*Name: Subhradeep Dutta
*Date: 12/30/2016
*This program implements a linked list by adding elements
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
};


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
        NoOfElements++;
        return start;
    }
    struct node *ptr;
    ptr=start;
    for(i=0;i<n-2;i++)//n-2 to iterate to the (n-1)th location
    {
        if (ptr->next == NULL)
            return start;
        ptr=ptr->next;
    }
    new_node->next=ptr->next;//Copy the location of the next element from ptr
    ptr->next=new_node;//Make ptr point to the newly created element
    NoOfElements++;
    return start;
}


/*************************************************************************************
Description   : This function is used to delete elements in the nth position of the
                linked list
Input         : Position to be deleted, pointer to beginning of linked
                list
Output        : Pointer to the beginning of the linked list
*************************************************************************************/
struct node* DeleteElementAtN(struct node *start, int n)
{
    int i;
    struct node* temp=NULL;
    struct node* ptr=NULL;
    ptr=start;
    if(n==1)//Special case for the starting node
    {
        start=ptr->next;//The start location pointer is now pointing to 2nd node
        free(ptr);
        NoOfElements--;//Reduce the number of elements by 1
        return start;
    }
    for(i=0;i<n-2;i++)//n-2 to iterate to the (n-1)th location
    {
        if (ptr->next == NULL)
            return start;
        ptr=ptr->next;
    }
    temp=ptr->next;//Nth node which is supposed to be deleted
    ptr->next=temp->next;//Reassign the link part of Nth node to the (N-1)th node to point to the (N+1)th node
    free(temp);
    NoOfElements--;//Update the number of elements
    return start;

}


/*************************************************************************************
Description   : This function is used to reverse the elements of the linked list
                by iterative technique
Input         : Pointer to the beginning of the linked list
Output        : Pointer to the beginning of the linked list
*************************************************************************************/

struct node* IterativeReverseList(struct node *start)
{
    struct node * current, *prev, *post;
    current=start;
    prev=NULL;
    while(current!=NULL)
    {
        post=current->next;//Store the location of next node
        current->next=prev;//Repoint the current node's next to previous node
        prev=current;//Shift the previous pointer to point to the current node
        current=post;//Shift the current pointer to point to the next node
    }
    start=prev;
    return start;
}


/*************************************************************************************
Description   : This function is used to print the elements of the linked list in
                reverse order using recursion
Input         : Pointer to the beginning of the linked list
Output        : Pointer to the beginning of the linked list
*************************************************************************************/

void PrintReverse(struct node *start)
{
    if(start==NULL)
    {
        printf("\n");
        return;
    }
    PrintReverse(start->next);
    printf("%d ",start->data);

}


/*************************************************************************************
Description   : This function is used to reverse the elements of the linked list
                by recursive technique
Input         : Pointer to the beginning of the linked list
Output        : Pointer to the beginning of the linked list
*************************************************************************************/

struct node* RecursiveReverseList(struct node *start)
{
    if(start->next==NULL)//Limiting condition when the last node is reached
    {
        return start;//Return the address of the last node
    }
    else
    {
        struct node *newstart=RecursiveReverseList(start->next);//Stores the location of the last node which is the new head
        start->next->next=start;//Make the next node point to the previous node
        start->next=NULL;//Make the current node point to NULL
        return newstart;//Return address of the head
    }
}



int main()
{

    char choice;
    int flag=1;
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

    while(flag==1)//As long as flag is 1 loop runs infintely
    {
        printf("\nMake a selection");
        printf("\nPress 1 to insert elements");
        printf("\nPress 2 to delete elements");
        printf("\nPress 3 to reverse the list");
        printf("\nPress 4 to print the current list");
        printf("\nPress 5 to print the current list in reverse order");
        printf("\nPress 6 to reverse the list using recursion");
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
                        HEAD=InsertElementInTheBeginning(HEAD,i);
                        PrintElements(HEAD);
                        break;
                    }
                    printf("\n The value %d will be inserted at %d position",i, n);
                    HEAD=InsertElementAtN(HEAD, i, n);
                    PrintElements(HEAD);
                }
                break;

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
                    HEAD=DeleteElementAtN(HEAD, n);
                    printf("\n The value at %d position is now deleted",n);
                    PrintElements(HEAD);
                }
                break;

            case '4':
                PrintElements(HEAD);
                break;

            case '9':
                flag=0;
                break;

            case '3':
                HEAD=IterativeReverseList(HEAD);
                printf("\n The list is now reversed");
                PrintElements(HEAD);
                break;

            case '5':
                printf("\n Printing elements in reverse order\n");
                PrintReverse(HEAD);
                break;

            case '6':
                printf("\n Reversed list using recursion\n");
                HEAD=RecursiveReverseList(HEAD);
                PrintElements(HEAD);
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

