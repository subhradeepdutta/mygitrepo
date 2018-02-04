/*Find 2 non repeating elements in an array of repeating elements*/
#include <stdio.h>

int main() 
{
	int numbers[] = {2, 3, 7, 9, 11, 2, 3, 11};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	
	int xor_array=numbers[0];
	int num1 = 0, num2 = 0;
	
	for(int i=1;i<length; i++)
	{
	    xor_array^= numbers[i];
	}
	 int set_bit = xor_array & ~(xor_array-1);
	 
	for(int i=0;i<length; i++)
	{
	    if(numbers[i] & set_bit)
	    {
	        num1^=numbers[i];
	    }
	    else
	    {
	        num2^=numbers[i];
	    }
	}
	printf("%d %d",num1, num2);
	return 0;
}