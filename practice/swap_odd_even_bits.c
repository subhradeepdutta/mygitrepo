/*Swap odd even bits in a number*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define EVEN_SET 0xAAAAAAAA
#define ODD_SET 0x55555555

int main()
{
   uint32_t number = 23;
   uint32_t even_data = number & EVEN_SET;
   uint32_t odd_data = number & ODD_SET;
   odd_data = odd_data << 1;
   even_data = even_data >> 1;
   uint32_t final_data = odd_data | even_data;
   printf("%d", final_data);
    return 0;
}