/*Square root using binary search*/

#include <stdio.h>

int square_root(int x)
{
    if(x ==0 || x == 1)
    {
        return x;
    }
    
    int start = 1, end = x, answer;
    while(start <= end)
    {
        int mid = (start + end)/2;
        
        if(mid * mid == x)
        {
            return mid;
        }
        
        if(mid * mid < x)
        {
            start = mid + 1;
            answer = mid;
        }
        
        else
        {
            end = mid - 1;
        }
    }
    return answer;
}


int main()
{
    printf("Square root of 24 is %d", square_root(24));
    return 0;
}