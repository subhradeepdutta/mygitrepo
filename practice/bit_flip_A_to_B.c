/*Count number of bits that need to be modified to change A to B*/
#include <stdio.h>

int main()
{
    int A = 7;
    int B = 10;
    int counter = 0;
    while(A != 0 || B!= 0)
    {
        if((A&1)!=(B&1))
        {
            counter ++;
        }
        A>>=1;
        B>>=1;
    }
    printf(" %d", counter);
}