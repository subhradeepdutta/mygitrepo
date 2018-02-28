#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t n = 0b00000011;
    int bits = sizeof(n) * 8;
    uint8_t bit_data;
    
    while(bits!=0)
    {
        bit_data = n & (0b10000000);
        if(bit_data > 0)
        {
            break;
        }
        n = n<<1;
        bits--;
    }
    printf("\n%ld",((sizeof(n) * 8 )- bits));
    return 0;
}
