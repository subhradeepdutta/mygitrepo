#include <stdio.h>
#include <stdint.h>

int main() 
{
	uint32_t number= 0x10000000;
	uint32_t bit_data = 0;
	uint32_t temp = 0;
	int number_of_bytes = sizeof(number);
	uint32_t LSB = number & 0x0000FFFF;
	uint32_t MSB = number & 0xFFFF0000;
	int bit_shift = number_of_bytes/2 * 8;
	while(bit_shift--)
	{
	    bit_data = MSB & 0x80000000;
	    temp|= (bit_data>>bit_shift);
	    MSB<<=1;
	}
	number = temp | LSB;
	printf(" Answer %x", number);
	return 0;
}