/*Adding two bit strings*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void bitadd(char *string1, char *string2, int length)
{
    int carry = 0;
    int carry_old = 0;
    int sum = 0;
    char final_result[20];
    string1 = string1 + (length - 1);
    string2 = string2 + (length - 1);
    while(length)
    {
        int bit_data1 = *string1 - '0';
        int bit_data2 = *string2 - '0';
        sum = bit_data1 ^ bit_data2 ^ carry_old;
        carry = ((bit_data1 & bit_data2) |(bit_data2 & carry_old) |(carry_old & bit_data1));
        final_result[length-1] = '0'+sum;
        length-- ;
        carry_old = carry;
        string1--;
        string2--;
    }
    printf("%s",final_result);
}

int main()
{
    char string2[] = "1100011";
    char string1[] = "10";
    char padding[20] = "";
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    int difference = abs(len2 - len1);
    if(len1 > len2)
    {
        while(difference--)
        {
            strncat(padding, "0",1);
        }
        strncat(padding, string2, len2);
        bitadd(string1, padding, len1);
    }
    else if(len1 < len2)
    {
        while(difference--)
        {
            strncat(padding, "0",1);
        }
        strncat(padding, string1, len1);
        bitadd(padding, string2, len2);
    }
    else if(len1 == len2)
    {
        bitadd(string1, string2, len1);
    }
    
    return 0;
}