#include <stdio.h>

void main()
{
    int i, j, k;
    printf("Enter i,j,k");
    scanf("%d %d %d",&i, &j, &k);
    int M[i][j];
    int N[j][k];
    int result[i][k];
    int temp_sum = 0;
    int loop_var1, loop_var2, loop_var3;
    for(loop_var1 = 0; loop_var1 < i; loop_var1++)
    {
        for(loop_var2 = 0; loop_var2 <j; loop_var2++)
        {
            printf("\n Enter an element");
            scanf("%d",&M[loop_var1][loop_var2]);
        }
    }
    for(loop_var1 = 0; loop_var1 < j; loop_var1++)
    {
        for(loop_var2 = 0; loop_var2 <k; loop_var2++)
        {
            printf("\n Enter an element");
            scanf("%d",&N[loop_var1][loop_var2]);
        }
    }
    
    for(loop_var1 = 0; loop_var1 < i; loop_var1++)
    {
        for(loop_var2 = 0; loop_var2 <j; loop_var2++)
        {
            result[loop_var1][loop_var2] = 0;
            for(loop_var3 = 0; loop_var3 <k; loop_var3++)
            {
                result[loop_var1][loop_var2] = result[loop_var1][loop_var2] + M[loop_var1][loop_var3]*N[loop_var3][loop_var2];
            }
        }
    }
    for(loop_var1 = 0; loop_var1 < i; loop_var1++)
    {
        for(loop_var2 = 0; loop_var2 <j; loop_var2++)
        {
            printf("%d ",result[loop_var1][loop_var2]);
            
        }
        printf("\n");
    }
    
}