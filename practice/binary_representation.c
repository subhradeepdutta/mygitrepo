/*Binary representation of a number */
#include <stdio.h>
#include <stdint.h>
int main()
{
    uint32_t n = 255;
    int bit_data = 0;
    int data[32]={0};
    int index = 31;
    while(n!=0)
    {
        bit_data = n & 1;
        data[index] = (bit_data>0)?1:0;
        index--;
        n = n>>1;
    }
    printf("\n");
    for(int i = 0; i<32; i++)
    {
        printf("%d",data[i]);
    }
    return 0;
}