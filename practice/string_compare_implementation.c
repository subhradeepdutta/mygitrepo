/*String compare implementation*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int stringcompare(char *str1, char *str2)
{
    while((*str1 == *str2 || *str1 == (*str2 ^32)) && (*str1!='\0' && *str2!='\0'))
    {
        str1++;
        str2++;
    }
    
    if(*str1 < *str2)
        return -1;
    if(*str1> *str2)
        return 1;
    if(*str1 == '\0' && *str2 == '\0')
        return 0;
}

int main()
{
    char string1[] = "aBBb";
    char string2[] = "aB";
    printf(" %d", stringcompare(string1, string2));
    printf(" %d", strcmp(string1, string2));
    return 0;
}