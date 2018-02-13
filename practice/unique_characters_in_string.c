/*Unique characters in a string*/
#include <stdio.h>
#include <string.h>

int main()
{
    char sample[] = "aabbcdcaea";
    int length = strlen(sample);
    int repeat = 0;
    for(int i = 0; i<length; i++)
    {
        repeat = 0;
        for(int j=0;j<length;j++)
        {
            if(sample[i] == sample[j])
            {
                repeat++;
            }
        }
        if(repeat == 1)
        {
            printf(" %c", sample[i]);
        }
    }
    
}
