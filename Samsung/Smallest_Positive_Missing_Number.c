/**********************************************************
Print the smallest missing positive number
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2
**********************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    int num_of_test_cases=0;
    int num_of_elements=0;
    int elements;
    printf("Enter number of test cases");
    scanf("%d",&num_of_test_cases);
    while(num_of_test_cases!=0)
    {
        printf("Enter number of elements");
        scanf("%d",&num_of_elements);
        int list_of_numbers[num_of_elements];
        for(int i = 0; i<num_of_elements; i++)
        {
            *(list_of_numbers + i) = 0;
        }
        for(int i = 0; i<num_of_elements; i++)
        {
            scanf("%d ",&elements);
            if((elements>0) && (elements<=num_of_elements))
            {
                *(list_of_numbers +(elements-1))=1;
            }
        }
        
        for(int i=0;i<num_of_elements;i++)
        {
            if(*(list_of_numbers+i)==0)
            {
                printf("%d\n",i+1);
                break;
            }

        }
        num_of_test_cases--;
    }
    return (0);
}