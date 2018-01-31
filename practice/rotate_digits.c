/*Bit rotation*/
//Assumes 32 bit number
#include <stdio.h>
#include <stdint.h>


int main() 
{
    uint32_t number, rotate_bits, result = 0;
    unsigned char direction;
	printf("Enter a number");
	scanf("%d",&number);
	printf("Enter number of bits to rotate");
    scanf("%d",&rotate_bits);
	printf("Enter L to rotate left R to rotate right");
	scanf(" %c",&direction);
	if(direction == 'L' || direction == 'l')
	{
	    result = ((number << rotate_bits) | (number >> (32-rotate_bits) ));
	}
	else if(direction == 'r' || direction == 'R')
	{
	    result = ((number >> rotate_bits) | (number << (32-rotate_bits) ));
	}
	else
	result = 0;
	
	printf("Result is %d",result);
	return 0;
}