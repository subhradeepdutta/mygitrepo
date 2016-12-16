/****************************************************************
*Name: Subhradeep Dutta
*Date: 12/15/2016
*This program calculates the remainder of two numbers without
*using the "%" or "/" operator
*****************************************************************/


#include <stdio.h>


void main()
{
	int number1, number2, remainder;
	printf("\n\r Enter two numbers\n\r");
	scanf("\n\r %d %d",&number1,&number2);
	if(number1>number2)//First case if dividend is greater than divisor
	{
		while(number1-number2>0)//Repeated subtraction until result is negative
		{
			number1=number1-number2;
			remainder=number1;
			if(number1==number2)//If dividend is perfectly divisible by divisor
			{
				remainder=0;
				break;
			}
		}
	}
	else if(number1<number2)//Case 2 if divisor is greater than dividend
	{
		remainder=number2;
	}
	printf("\n\r Remainder is %d",remainder);
}
