/*Reverse a  number efficiently using bit shifting*/
#include <stdio.h>

int main()
{
    int number;
    int reverse_number = 0;
    printf("Enter a number");
    scanf("%d",&number);
    while(number != 0)
    {
        reverse_number <<= 1;
        int bit_data = number & 1;
        reverse_number|=bit_data;
        number>>= 1;
    }
    printf(" %d", reverse_number);
}