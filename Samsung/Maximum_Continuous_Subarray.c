/*Kadane's Algorithm*/

/**********************************************************
Print the maximum sum of the contiguous sub-array 
in a separate line for each test case.

Input
2
3
1 2 3
4
-1 -2 -3 -4
Output
6
-1
**********************************************************/

#include <stdio.h>

void main()
{
    int num_test_cases, i=0, n=0;
    int global_sum = 0, local_sum = 0;
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
        local_sum = *(elements);
        global_sum = *(elements);
        for(i = 1; i < n; i++)
        {
            
            local_sum = *(elements+i) > (local_sum + *(elements+i))?*(elements+i) : (local_sum + *(elements+i));
            if(global_sum<local_sum)
            {
                global_sum = local_sum;
            }
        }
        
        printf("\n%d",global_sum);
    }
}