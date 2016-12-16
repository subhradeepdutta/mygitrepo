/****************************************************************
*Name: Subhradeep Dutta
*Date: 12/15/2016
*This program swaps three numbers without using fourth variable
*****************************************************************/


#include <stdio.h>

void main()
{
	int a, b, c;//Create three variables
	printf("Enter a b c values\n\r");
	scanf("%d %d %d",&a,&b,&c);
	printf("\n\r a=> %d b=> %d c=%d ",a,b,c);

	a = a+b+c;
	b = a-(b+c);
	c = a-(b+c);
	a = a-(b+c);

	printf("\n\r After swap a=> %d b=> %d c=%d ",a,b,c);


}
