#include <stdio.h>

int main()
{
	int n , n1;
	scanf("%d",&n);
	int list_of_numbers[n], largest_num, second_largest_num;
	for(int i =0; i<n; i++)
	{
		scanf("%d",(list_of_numbers + i));
	}
	largest_num = *(list_of_numbers);
	for(int i =1; i<n; i++)
	{
		if(*(list_of_numbers+i) > largest_num)
		{
			largest_num = *(list_of_numbers +i);
		}
	}
	second_largest_num = 0;
	for(int i =0; i<n; i++)
	{
		if((*(list_of_numbers+i) > second_largest_num) && (*(list_of_numbers + i)!= largest_num) && (*(list_of_numbers+i) < largest_num))
		{
			second_largest_num = *(list_of_numbers+i);
		}
	}
	printf("%d", (largest_num * second_largest_num));

	return (0);
}