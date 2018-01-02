#include <stdio.h>
#include <string.h>

int main()
{
    int num_of_test_cases=0;
    char test_string[100];
    int length;
    int counter = 0;
    int looking_for_zero = 0;
    int looking_for_one = 0;
    char c;
    printf("Enter number of test cases");
    scanf("%d",&num_of_test_cases);
    while(num_of_test_cases!=0)
    {
        printf("Enter test string");
        scanf("%s",test_string);
        length = strlen(test_string);
        for(int i =0; i<length; i++)
        {
            c = *(test_string + i);
            if((c == '1') && (looking_for_one == 0))
            {
                looking_for_zero = 1;
                looking_for_one = 0;
            }
            else if ((c == '0') && (looking_for_zero == 1) && (looking_for_one == 0))
            {
                looking_for_one = 1;
                looking_for_zero = 0;
            }
            else if((c == '0') && (looking_for_one == 1) && (looking_for_zero == 0))
            {
                continue;
            }
            else if((c == '1') && (looking_for_zero == 0) && (looking_for_one == 1))
            {
                looking_for_one = 0;
                looking_for_zero = 1;
                counter++;
            }
            else
            {
                looking_for_one = 0;
                looking_for_zero = 0;
            }
        }
        printf("%d\n",counter);
        counter = 0;
        looking_for_zero = 0;
        looking_for_one = 0;
        num_of_test_cases--;
    }
    return (0);
}