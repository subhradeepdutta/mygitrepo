#include <stdio.h>

int main() 
{
	unsigned int number = 25;
	printf("Intial Number - %d",number);
	/*Check for position of rightmost zero*/
	unsigned int duplicate = number;
	int position = 0, bit_data;
	while(duplicate!=0)
	{
	    bit_data = duplicate & 1;
	    if(bit_data == 0)
	        break;
	    position++;
	    duplicate>>=1;
	}
	
	for(int i = 0; i<= position; i++)
	{
	    number^= (1<<i);
	}
	printf("\nFinal number - %d",number);
	return 0;
}