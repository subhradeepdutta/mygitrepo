/*Generate every possible permutation of string*/

/*********************************************************
Input:
ABC

Output:
ABC
ACB
BAC
BCA
CAB
CBA
*********************************************************/

#include <stdio.h>
#include <string.h>

void permute(char *str, int start, int end);
void swap(char *character1, char *character2);

int main()
{
    int length = 0;
    char original_string[20];
    printf("Enter a string");
    scanf("%s",original_string);
    length = strlen(original_string);
    permute(original_string, 0, length-1);
}

void permute(char *str, int start, int end)
{
    if(start == end)
    {
        printf("%s\n", str);
    }
    else
    {
        for(int i=start; i<=end; i++)
        {
            swap((str+start),(str+i));
            permute(str,(start+1),(end));
            swap((str+start),(str+i));
        }
    }
}

void swap(char *character1, char *character2)
{
    char temp = *character1;
    *character1 = *character2;
    *character2 = temp;
}