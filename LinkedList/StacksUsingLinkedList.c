/****************************************************************
*Name: Subhradeep Dutta
*Date: 1/10/2016
*This program implements a stack using linked lists
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
 char data;
 struct node *next;
};

struct node *top=NULL;
int NoofElements;

void Push(char n);
struct node *Pop();
void PrintElements();
void StringReverse(char string[]);


/*************************************************************************************
Description   : This function is used to push elements into the stack
Input         : Element to be inserted
Output        : N/A
*************************************************************************************/

void Push(char n)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL)//Check if malloc was successful
    {
        printf("Memory allocation failed");
        return;
    }
    new_node->data=n;
    new_node->next=top;//Make the newly created node's next point to the current top node
    top=new_node;//Make top point to the newly created node
    NoofElements++;
}

/*************************************************************************************
Description   : This function is used to pop elements from the stack
Input         : Element to be inserted
Output        : Pointer to top of the stack
*************************************************************************************/


struct node *Pop()
{

    struct node *ptr;
    ptr=top;
    if(ptr==NULL)
    {
        return top;//Return if stack is empty
    }
    top=top->next;//Make top point to the next element in the stack
    free(ptr);
    NoofElements--;
    return top;
}


/*************************************************************************************
Description   : This function is used to print elements of the stack
Input         : N/A
Output        : N/A
*************************************************************************************/

void PrintElements()
{
    struct node *ptr;
    ptr=top;
    if(ptr==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    while(ptr!=NULL)
    {
        printf("\n %c ", ptr->data);
        ptr=ptr->next;
    }

}

void StringReverse(char string[])
{
    int i;
    for(i=0;i<100 && string[i]!='\0';i++)
    {
        Push(string[i]);
    }
    for(i=0;i<100 && string[i]!='\0';i++)
    {
        string[i]=top->data;
        Pop();
    }
}

int main()
{
    int choice, flag=1;
    char n;
    char string[100];
    while(flag==1)
    {
        printf("\nMake a selection\n");
        printf("Enter 1 to push an element in the stack\n");
        printf("Enter 2 to pop an element from the stack\n");
        printf("Enter 3 to print the stack elements\n");
        printf("Enter 4 to display the top element of the stack\n");
        printf("Enter 5 to reverse a string using stack\n");
        printf("Enter 9 to quit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter an element to push into the stack -->  ");
                getchar();
                scanf(" %c",&n);
                Push(n);
                break;

            case 2:
                top=Pop();
                break;

            case 3:
                PrintElements();
                break;

            case 4:
                if(top==NULL)
                    printf("Stack is empty");
                else
                    printf("\nThe top element on the stack is --> %c",top->data);
                break;

            case 5:
                fflush(stdin);
                printf("Enter a string\n");
                fgets (string,100,stdin);
                printf("\n Original string is --> %s",string);
                for(int i=0;i<100;i++)
                {
                    if(string[i]=='\0')
                        string[i-1]='\0';
                }
                StringReverse(string);
                printf("Modified string is --> %s",string);
                break;

            case 9:
                flag=0;
                break;

            default:
                printf("Incorrect selection");
                break;
        }


    }
    return 0;
}

