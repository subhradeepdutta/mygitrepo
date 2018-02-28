#include <stdio.h>
void string_reverse(char *start, char *stop)
{
    int difference = stop - start;
    char temp;
    if(difference)
    {
        for(int i = 0; i<((difference+1)/2); i++)
        {
            temp = *start;
            *start = *stop;
            *stop = temp;
            start++;
            stop--;
        }
    }
    else
        return;
}

int main() {
	char sample[] = "This is a sample string";
	int length = sizeof(sample);
	char *ptr = sample;
	char *start = ptr, *stop = NULL;
	while(length--)
	{
	    if(*ptr == ' ' || *ptr == '\0')
	    {
	        stop = ptr-1;
	        string_reverse(start, stop);
	        start = ptr+1;
	    }
	    ptr++;
	}
	
	printf("%s ",sample);
	return 0;
}