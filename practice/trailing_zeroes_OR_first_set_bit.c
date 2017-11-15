#include <stdio.h>
#include <stdint.h>
void main()
{
    size_t n = 0;
    int counter = 0;
    int lsb_bit;
    printf("Enter a number");
    scanf("%zd",&n);
    size_t copy = n;
    while(n!=0)
    {
        lsb_bit = n & 1;
        counter++;
        if(lsb_bit == 1)
            break;
        n = n>>1;
    }
    printf("The first set bit is at position %d",counter);
}