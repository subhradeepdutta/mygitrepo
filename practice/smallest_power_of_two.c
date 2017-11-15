#include <stdio.h>
#include <stdint.h>
#include <math.h>
void main()
{
    size_t n = 0;
    int counter = 0;
    int remainder;
    printf("Enter a number");
    scanf("%zd",&n);
    size_t copy = n;
    while(n!=1)
    {
        remainder = n%2;
        n = n/2;
        counter++;
    }
    
    if(remainder == 0)
        printf("The smallest power of 2 is %zd",copy);
    else
        printf("The smallest power of 2 is %lf",pow(2,counter+1));
}