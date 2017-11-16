#include <stdio.h>
#include <stdint.h>

void main()
{
    size_t num_test_cases, n=0, remainder=0, counter = -1, copy;
    scanf("%zd",&num_test_cases);
    while(num_test_cases--)
    {
        scanf("%zd",&n);
        counter = 0;
        copy = n;
    if(n < 0)
        n = n*-1;
    while(n)
    {
        if(n%2 != 0 && n!=1)
        {
            counter = 1;
            break;
        }
        n =n>>1;
        
    }
    if(counter == 0 && copy!=0)
        printf("YES\n");
    else
        printf("NO\n");
        
    }
}