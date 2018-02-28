/*Swap n bits in a given number between 2 positions*/
#include <stdio.h>

int main() 
{
    unsigned int number= 28;
    unsigned int position1 = 0, position2 = 3, number_of_bits=2;
    unsigned int set1 = (number>>position1) & ((1<<number_of_bits)-1);
    unsigned int set2 = (number>>position2) & ((1<<number_of_bits)-1);
    unsigned int xor = set1^set2;
    xor = (xor<<position1)|(xor<<position2);
    unsigned int final_result = number ^ xor;
    printf("%d",final_result);
	return 0;
}