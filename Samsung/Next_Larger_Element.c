/**********************************************************
Given an array A [ ] having distinct elements, the task 
is to find the next greater element for each element of 
the array in order of their appearance in the array. 
If no such element exists, output -1 

Input
1
4
1 3 2 4 

Output
3 4 4 -1
**********************************************************/


#include <stdio.h>

void main()
{
    int num_test_cases, i=0, j=0, n=0, temp_val = 0;
    static int elements[100];
    printf("Enter number of test cases");
    scanf("%d",&num_test_cases);
    while(num_test_cases--)
    {
        printf("Enter number of elements");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("Enter elements");
            scanf("%d",(elements + i));
        }
        for(i = 0; i < n; i++)
        {
            temp_val = 0;
            for(j = i+1; j<n;j++ )
            {
                if(elements [i]< elements[j])
                {
                    temp_val = elements[j];
                    break;
                }
            }
            if(temp_val == 0)
            printf (" -1");
            else
            printf(" %d",temp_val);
        }
    }
}