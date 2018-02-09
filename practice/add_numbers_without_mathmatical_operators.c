/*Add two numbers without using any mathematical */
/*Added implementation*/
#include <stdio.h>

int main() 
{
    int number1= 22, number2 = 33;
    int carry;
    while(number1!=0)
    {
        /*Calculate the carry*/
        carry = number1 & number2;
        
        /*Calculate the sum*/
        number2 = number2 ^ number1;
        
        /*Transfer carry to next bit*/
        number1 = carry << 1;
    }
    
    printf("%d",number2);
	return 0;
}