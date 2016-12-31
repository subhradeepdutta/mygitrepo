/****************************************************************
*Name: Subhradeep Dutta
*Date: 12/30/2016
*This program adds an element to the beginning of a linked list
*and then displays the elements in the list
*****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void PrintElements();
void InsertElement(int x);

struct node
{
    int data;//Refers to the data part of the linked list
    struct node* next;//Refers to the pointer which points to the next element
};

struct node* HEAD;
struct node* temp;
struct node* temp1;


/*************************************************************************************
Description   : This function is used to print the elements in the linked list
Input         : N/A
Output        : N/A
*************************************************************************************/


void PrintElements()
{
    if(HEAD==NULL)//If the list is empty
        printf("List is empty");
    else
    {
        temp1=HEAD;
        while(temp1!=NULL)
        {
            printf("%d ",temp1->data);
            temp1=temp1->next;
        }
    }
}

/*************************************************************************************
Description   : This function is used to insert elements in the beginning of the
                linked list
Input         : Element to be inserted
Output        : N/A
*************************************************************************************/

void InsertElement(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=HEAD;
    HEAD=temp;

}

int main()
{

    int i, x;
    int n;   //n stores the number of elements to be added to the linked list
    HEAD=NULL; //Assigning HEAD to null when there are no elements in the list
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n\rEnter the number");
        scanf("%d",&x);
        InsertElement(x);
        PrintElements();
    }

    return 0;
}

