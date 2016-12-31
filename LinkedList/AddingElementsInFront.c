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
void InsertElementInTheBeginning(int x);
void InsertElementAtN(int x, int n);

struct node
{
    int data;//Refers to the data part of the linked list
    struct node* next;//Refers to the pointer which points to the next element
};

struct node* HEAD;
struct node* temp;
struct node* temp1;
struct node* temp2;
struct node* temp3;


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

void InsertElementInTheBeginning(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=HEAD;
    HEAD=temp;

}

/*************************************************************************************
Description   : This function is used to insert elements in the nth position of the
                linked list
Input         : Element to be inserted
Output        : N/A
*************************************************************************************/

void InsertElementAtN(int x, int n)
{
    int i;
    struct node* temp2=(struct node*)malloc(sizeof(struct node));
    temp2->data=x;
    temp2->next=NULL;
    if(n==1)
    {
        temp2->next=HEAD;
        HEAD=temp2;
        return;
    }
    struct node* temp3=HEAD;
    for(i=0;i<n-2;i++)
    {
        printf("Inside the loop");
        temp3=temp3->next;
    }
    temp2->next=temp3->next;
    temp3->next=temp2;
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
        InsertElementInTheBeginning(x);
        PrintElements();
    }
        printf("\n\rEnter the number and position");
        scanf("%d %d",&x,&n);
        InsertElementAtN(x, n);
        PrintElements();
    return 0;
}

