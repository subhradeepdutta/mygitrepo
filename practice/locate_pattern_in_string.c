#include <stdio.h>
#include <string.h>

int main() 
{
	char sample_string[] = "This is a sample string";
	char pattern[] = "is";
	int str_length = strlen(sample_string);
	int pat_length = strlen(pattern);
	char *ptr = sample_string;
	char temp[pat_length];
	int result = 1;
	for(int i = 0; i<=(str_length-pat_length); i++,ptr++)
	{
	    strncpy(temp,ptr,pat_length);
	    result = strncmp(temp, pattern, pat_length);
	    if(result == 0)
	    {
	        printf("\nPattern found at index %d",i);
	    }
	}
	return 0;
}