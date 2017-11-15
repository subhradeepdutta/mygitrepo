#include <stdio.h>

int recursive_search(int arr[], int i, int length, int element)
{
    if(i>length)
    return (-1);
    else if(arr[i]==element)
    return i;
    else
    return (recursive_search(arr,i+1,length, element));
}
int main() {
	//code
	int arr[]={1,2,3,4,5};
	int length = sizeof(arr)/sizeof(arr[0]);
	int index = recursive_search(arr,0,length-1,6);
	if(index != -1)
	printf("the number %d is located at %d",arr[index],index);
	else
	printf("Number not found");
	return 0;
}