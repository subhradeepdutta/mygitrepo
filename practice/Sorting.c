#include <stdio.h>
#include <stdbool.h>

int partition (int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;    // increment index of smaller element
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return (i + 1);
}

int *quick_sort(int array[], int low, int high)
{
    if(low < high)
    {
        int partion_index = partition(array,low,high);
        quick_sort(array,low,partion_index-1);
        quick_sort(array,partion_index+1,high);
    }
    return(array);
}

int *insertion_sort(int array[], int length)
{
    int key, i, j;
    for(i = 1; i<length; i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1]= key;
    }
    return(array);
}

int *bubble_sort(int array[], int length)
{
    int temp;
    bool swapped = false;
    for(int i = 0; i<length-1; i++)
    {
        for(int j = 0; j<length-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        /*No swaps would have occurred if the array was already sorted*/
        if(swapped == false)
        break;
    }
    return(array);
}

int *selection_sort(int array[], int length)
{
    int temp, min_index;
    for(int i = 0; i<length-1; i++)
    {
        min_index = i;
        for(int j = i+1; j < length; j++)
        {
            if(array[min_index] > array[j])
            {
                min_index = j;
            }
        }
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
    return(array);
}

int main() 
{
    int list_numbers[] = {64,25,12,22,11};
    int length = sizeof(list_numbers)/sizeof(list_numbers[0]);
    int *ptr = selection_sort(list_numbers, length);
    printf("\n\rSelection Sort\n\r");
    while(length--)
    {
        printf(" %d ",*(ptr++));
    }
    
    
    int list_number1[] = {64,25,12,22,11};
    int length1 = sizeof(list_number1)/sizeof(list_number1[0]);
    int *ptr1 = bubble_sort(list_number1, length1);
    printf("\n\rBubble Sort\n\r");
    while(length1--)
    {
        printf(" %d ",*(ptr1++));
    }
    
    int list_number2[] = {64,25,12,22,11};
    int length2 = sizeof(list_number2)/sizeof(list_number2[0]);
    int *ptr2 = bubble_sort(list_number2, length2);
    printf("\n\rInsertion Sort\n\r");
    while(length2--)
    {
        printf(" %d ",*(ptr2++));
    }
    
    int list_number3[] = {64,25,12,22,11};
    int length3 = sizeof(list_number3)/sizeof(list_number3[0]);
    int *ptr3 = quick_sort(list_number3, 0, length3-1);
    printf("\n\rInsertion Sort\n\r");
    while(length3--)
    {
        printf(" %d ",*(ptr3++));
    }
}