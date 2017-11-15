#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void main()
{
    size_t n = 0;
    int counter = 1;
    int even=0, odd=0;
    printf("Enter a number");
    scanf("%zd",&n);
    size_t copy = n;
    while(n)
    {
        counter++;
        if((n & 1 == 1)&&(counter%2==0))
            even++;
        else if((n & 1 == 1)&&(counter%2!=0))
            odd++;
        n = n>>1;
       
    }

    if(abs(even-odd)%3==0)
        printf("Divisible");
    else
        printf("Not Divisible");
}