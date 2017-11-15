#include <stdio.h>
#include <stdint.h>
void main()
{
    size_t n = 0;
    int counter = 0;
    printf("Enter a number");
    scanf("%zd",&n);
    size_t copy = n;
    while(n!=0)
    {
        if(n & 1 == 1)
        counter++;
        n = n>>1;
    }
    printf("The number of ones in %zd are %d",copy, counter);
}