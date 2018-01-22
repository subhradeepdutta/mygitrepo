#include <stdio.h>
#include <stdint.h>
int main()
{
	int64_t n , temp;
	scanf("%ld",&n);
	int64_t list_of_numbers[n], largest_num, second_largest_num;
	for(int i =0; i<n; i++)
	{
		scanf("%ld",(list_of_numbers + i));
	}
	largest_num = 0;
	for(int i =1; i<n; i++)
	{
		if(*(list_of_numbers+i) > *(list_of_numbers + largest_num))
		{
			largest_num = i;
		}
	}
	temp = list_of_numbers[n-1];
	list_of_numbers[n-1] = list_of_numbers[largest_num];
	list_of_numbers[largest_num] =  temp;
	largest_num = n-1;

	second_largest_num = 0;

	for(int i =0; i<n; i++)
	{
		if((list_of_numbers[i] > list_of_numbers[second_largest_num]) && (i!= largest_num))
		{
			second_largest_num = i;
		}
	}
	printf("%ld", (*(list_of_numbers + largest_num) * *(list_of_numbers + second_largest_num)));

	return (0);
}