/**********************************************************
Print the Max length of the subsequence in a separate line.

Input
1
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Output
6
**********************************************************/

#include <stdio.h>

void main()
{
    int num_test_cases, i=0, n=0, j=0, temp_var;
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
        int result[n];
        for(i=0;i<n;i++)
            *(result+i)=1;
        
        for(i = 1; i < n; i++)
        {
            for(j=0;j<i;j++)
            {
                if(*(elements+j) < *(elements + i))
                {
                    if(*(result+j)+1 > *(result+i))
                       *(result+i) = *(result+j)+1;
                }
            }
            
        }
        temp_var = result[0];
        for(i=0;i<n;i++)
        {
            if(*(result+i) > temp_var)
                temp_var =  *(result+i);
        }
        printf("\nLength of LIS is %d",temp_var);
        
    }
}